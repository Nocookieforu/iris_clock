
#include <Adafruit_NeoPixel.h>
#include <TimeLib.h>
#include <TimerOne.h>

extern "C"
{
  #include "color.h"
  #include "button.h"
}

// Analog sensor hooked to Teensy LC pin 14
#define LIGHT_ANALOG_PIN    (A0)
#define LIGHT_NUM_READS     16
uint32_t analog_reads[LIGHT_NUM_READS] = {0};
size_t   analog_ind = 0;
int light_sensor_read(void);
int light_sensor_done(void);
float light_sensor_average(void);

#define BUTTON_PIN          11
struct button in_button;
void button_int(void)
{
  button_update(&in_button, !digitalRead(BUTTON_PIN));
}

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
  pinMode(LIGHT_ANALOG_PIN, INPUT);
}

void loop()
{
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

  light_sensor_read();
  if (light_sensor_done())
  {
    float light_sense = light_sensor_average();
    if (light_sense >= 650.0f)
    {
      light_sense = 650.0f;
    }
    float light_ratio = light_sense / 650.0f;
    int out_brightness = (int)((float)brightness * light_ratio);
    strip.setBrightness(out_brightness);

    Serial.print("(Light sensor, Brightness): (");
    Serial.print(light_sense);
    Serial.print(", ");
    Serial.print(out_brightness);
    Serial.println(")");
  }
}

void display_time(time_t time)
{
  uint8_t i;
  for (i = 0; i < 8; i++)
  {
    uint8_t hour_bit = (hour(time)   >> i) & 0x1;
    uint8_t min_bit  = (minute(time) >> i) & 0x1;
    uint8_t sec_bit  = (second(time) >> i) & 0x1;
    struct color pixel_color = {0};
    if (hour_bit)
    {
      pixel_color = add_colors(pixel_color, color_blue);
    }
    if (min_bit)
    {
      pixel_color = add_colors(pixel_color, color_green);
    }
    /*
    if (sec_bit)
    {
      pixel_color = add_colors(pixel_color, color_red);
    }
    */
    //strip.setPixelColor(i, 255*hour_bit, 255*min_bit, 255*sec_bit);
    strip.setPixelColor(i, pixel_color.red, pixel_color.green, pixel_color.blue);
  }

  // Use LEDs 6 and 7 for seconds
  if (second(time) & 0x8)
    strip.setPixelColor(6, color_red.red, color_red.green, color_red.blue);
  else
    strip.setPixelColor(6, 0, 0, 0);

  if (second(time) & 0x10)
    strip.setPixelColor(7, color_red.red, color_red.green, color_red.blue);
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

int light_sensor_read(void)
{
  analog_reads[analog_ind] = analogRead(LIGHT_ANALOG_PIN);
  //Serial.println(analog_reads[analog_ind]);
  analog_ind++;
}

int light_sensor_done(void)
{
  return analog_ind >= LIGHT_NUM_READS;
}

float light_sensor_average(void)
{
  uint32_t sum = 0;
  for (analog_ind = 0; analog_ind < LIGHT_NUM_READS; analog_ind++)
  {
    sum += analog_reads[analog_ind];
  }
  float avg = (float)sum / LIGHT_NUM_READS;
  analog_ind = 0;
  return avg;
}

