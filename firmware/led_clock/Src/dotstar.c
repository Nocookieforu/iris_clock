
#include "dotstar.h"

/** Need extra data bytes for start and stop data.
 *  Start bytes are 4x 0x00.
 *  Stop bytes are 4x 0xFF.
 */
#define DOTSTAR_DATA_LEN    (DOTSTAR_NUM_LEDS + 2)

/** Internal storage for the values of the LEDs. */
static union dotstar_data leds[DOTSTAR_DATA_LEN] = {0};

void dotstar_init(void)
{
    // Start bytes
    leds[0].data = 0x00000000;

    // Stop bytes
    leds[DOTSTAR_DATA_LEN-1].data = 0xFFFFFFFF;

    // Data
    size_t i;
    for (i = 1; i < (DOTSTAR_NUM_LEDS + 1); i++)
    {
        //leds[i].values.reserved = 0x07;
        leds[i].values.global   = 0xFF;
        leds[i].values.red      = 0;
        leds[i].values.green    = 0;
        leds[i].values.blue     = 0;
    }
}

int dotstar_set_global(uint8_t brightness)
{
    if (brightness > 31)
    {
        return -1;
    }

    size_t i;
    for (i = 1; i < (DOTSTAR_NUM_LEDS + 1); i++)
    {
        // Top 3 bits of first byte must be 1
        leds[i].values.global = 0xE0 | (brightness & 0x1F);
    }

    return 0;
}

int dotstar_set_led(size_t led_num, uint8_t red, uint8_t green, uint8_t blue)
{
    if (led_num > DOTSTAR_NUM_LEDS)
    {
        return -1;
    }

    leds[led_num+1].values.red   = red;
    leds[led_num+1].values.green = green;
    leds[led_num+1].values.blue  = blue;

    return 0;
}

int dotstar_get_data(uint8_t **out_data, uint16_t *out_size)
{
    if (out_data == NULL || out_size == NULL)
    {
        return -1;
    }

    *out_data = (uint8_t*)leds;
    *out_size = DOTSTAR_DATA_LEN * sizeof(leds[0]);
  
    return 0;
}

int dotstar_write(void)
{
    size_t i;
    /*
    // Write start bytes (4 x 0x00)
    for (i = 0; i < 4; i++)
    {
        // TODO
        spi_write(0x00);
    }
    */

    // Write data
    for (i = 0; i < DOTSTAR_NUM_LEDS; i++)
    {
        // TODO
        spi_write(leds[i].bytes.byte3);
        spi_write(leds[i].bytes.byte2);
        spi_write(leds[i].bytes.byte1);
        spi_write(leds[i].bytes.byte0);
    }

    /*
    // Write end bytes (4 x 0xFF)
    for (i = 0; i < 4; i++)
    {
        // TODO
        spi_write(0xFF);
    }
    */
    
    return 0;
}

