
#include <Adafruit_NeoPixel.h>
#include <TimeLib.h>
#include <TimerOne.h>

extern "C"
{
  #include "color.h"
  #include "button.h"
  #include "smoothing.h"
}

// Analog sensor hooked to Teensy LC pin 14
#define LIGHT_ANALOG_PIN    (A0)
#define LIGHT_FILT_ALPHA    ((float)0.05)
struct exponential_filter light_filt = {0};
float light_sensor_update(void);

#define BUTTON_PIN          11
struct button in_button;
#define COLOR_BUTTON_PIN    8
struct button color_button;
void button_int(void)
{
  button_update(&in_button,    !digitalRead(BUTTON_PIN));
  button_update(&color_button, !digitalRead(COLOR_BUTTON_PIN));
}
rgb colors[3];
int color_switch = 0;

#define NEOPIXEL_PIN        17
uint8_t brightness = 64;

// Parameter 1 = number of pixels in strip
// Parameter 2 = Arduino pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
//   NEO_RGBW    Pixels are wired for RGBW bitstream (NeoPixel RGBW products)
Adafruit_NeoPixel strip = Adafruit_NeoPixel(8, NEOPIXEL_PIN, NEO_GRB + NEO_KHZ800);

#define STR_BUF_LEN     128
char str_buf[STR_BUF_LEN];
char *str_buf_ptr = str_buf;

void clear_buf()
{
    size_t i;
    for (i = 0; i < STR_BUF_LEN; i++)
    {
        str_buf[i] = '\0';
    }
}

void print_str_buf()
{
    size_t i;
    for (i = 0; i < STR_BUF_LEN; i++)
    {
        if (str_buf[i] == '\0')
        {
            Serial.print("\\0");
        }
        else
        {
            Serial.print(str_buf[i]);
        }
    }
    Serial.println();
}

void test_colors()
{
    Serial.println("Testing colors!");
    clear_buf();
    //rgb in_color = color_yellow;
    rgb in_color = color_red;
    int len = color_rgb_to_string(in_color, &str_buf_ptr);
    //print_str_buf();
    Serial.println(str_buf);
    hsv color_conv = color_rgb_to_hsv(in_color);
    len = color_hsv_to_string(color_conv, &str_buf_ptr);
    //print_str_buf();
    Serial.println(str_buf);
    rgb color_back = color_hsv_to_rgb(color_conv);
    len = color_rgb_to_string(color_back, &str_buf_ptr);
    Serial.println(str_buf);
}

void switch_colors()
{
    color_switch++;
    if (color_switch >= 3)
    {
        color_switch = 0;
    }
    switch (color_switch)
    {
        case 0:
            colors[0] = color_green;
            colors[1] = color_blue;
            break;
        case 1:
            colors[0] = color_yellow;
            colors[1] = color_red;
            break;
        case 2:
            colors[0] = color_yellow;
            colors[1] = color_blue;
            break;
    }
    colors[2] = color_hsv_to_rgb(color_add_hsv(color_rgb_to_hsv(colors[0]),
                                               color_rgb_to_hsv(colors[1])));
}

void setup()
{
  Serial.begin(115200);

  strip.begin();
  // Initialize all pixels to 'off'
  strip.show();
  strip.setBrightness(brightness);

  // Set interrupt for 1 ms
  Timer1.initialize(1000);
  Timer1.attachInterrupt(button_int, 1000);

  setTime(5, 10, 0, 0, 0, 0);
  pinMode(BUTTON_PIN, INPUT);
  button_init(&in_button);
  pinMode(COLOR_BUTTON_PIN, INPUT);
  button_init(&color_button);
  pinMode(LIGHT_ANALOG_PIN, INPUT);

  color_switch = 3;
  switch_colors();

  exponential_filter_init(&light_filt, LIGHT_FILT_ALPHA);
}

void loop()
{
  test_colors();

  // Some example procedures showing how to display to the pixels:
  //rainbow(20);
  //rainbowCycle(20);

  // Increase time by one second
  adjustTime(1);
  // Show time on LEDs
  display_time(now());
  //delay(1000);
  delay(20);
  //Serial.println(in_button.integrate);

  if (button_was_pressed(&in_button))
  {
    brightness = (brightness + 63) & 0xFF;
    //strip.setBrightness(brightness);
    //Serial.println(brightness);
  }
  if (button_was_pressed(&color_button))
  {
    switch_colors();
  }

  float light_ratio = light_sensor_update();
  int out_brightness = (int)((float)brightness * light_ratio);
  strip.setBrightness(out_brightness);

  //Serial.print("(Light sensor, Brightness): (");
  //Serial.print(light_filt.value);
  //Serial.print(", ");
  //Serial.print(out_brightness);
  //Serial.println(")");
}

void display_time(time_t time)
{
  uint8_t i;
  for (i = 0; i < 8; i++)
  {
    uint8_t hour_bit = (hour(time)   >> i) & 0x1;
    uint8_t min_bit  = (minute(time) >> i) & 0x1;
    uint8_t sec_bit  = (second(time) >> i) & 0x1;

    rgb pixel_color = {0};
    if (hour_bit && min_bit)
      pixel_color = colors[2];
    else if (min_bit)
      pixel_color = colors[0];
    else if (hour_bit)
      pixel_color = colors[1];
    /*
    if (sec_bit)
    {
      pixel_color = color_add_rgb(pixel_color, color_red);
    }
    */

    Serial.print(i);
    Serial.print(": ");
    color_hsv_to_string(color_rgb_to_hsv(pixel_color), &str_buf_ptr);
    Serial.println(str_buf);
    //strip.setPixelColor(i, 255*hour_bit, 255*min_bit, 255*sec_bit);
    strip.setPixelColor(i, pixel_color.r, pixel_color.g, pixel_color.b);
  }

  // Use LEDs 6 and 7 for seconds
  if (second(time) & 0x8)
    strip.setPixelColor(6, colors[1].r, colors[1].g, colors[1].b);
  else
    strip.setPixelColor(6, 0, 0, 0);

  if (second(time) & 0x10)
    strip.setPixelColor(7, colors[1].r, colors[1].g, colors[1].b);
  else
    strip.setPixelColor(7, 0, 0, 0);

  strip.show();
}

void rainbow(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<256; j++) {
    for(i=0; i<strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel((i+j) & 255));
    }
    strip.show();
    delay(wait);
  }
}

// Slightly different, this makes the rainbow equally distributed throughout
void rainbowCycle(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<256*5; j++) { // 5 cycles of all colors on wheel
    for(i=0; i< strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel(((i * 256 / strip.numPixels()) + j) & 255));
    }
    strip.show();
    delay(wait);
  }
}

// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
uint32_t Wheel(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if(WheelPos < 85) {
    return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  }
  if(WheelPos < 170) {
    WheelPos -= 85;
    return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
  WheelPos -= 170;
  return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
}

float light_sensor_update(void)
{
  exponential_filter_update(&light_filt, analogRead(LIGHT_ANALOG_PIN));
  //Serial.println(light_filt.value);
  float light_val = light_filt.value;
  if (light_val >= 650.0f)
  {
    light_val = 650.0f;
  }
  return light_val / 650.0f;
}

