
#ifndef __DOTSTAR_H
#define __DOTSTAR_H

#include <stddef.h>
#include <stdint.h>

/*
struct dotstar_data
{
    union
    {
        uint32_t data;
        struct bytes
        {
            uint8_t byte3;
            uint8_t byte2;
            uint8_t byte1;
            uint8_t byte0;
        };
        struct values
        {
            uint8_t reserved : 3;
            uint8_t global   : 5;
            uint8_t blue;
            uint8_t green;
            uint8_t red;
        };
    };
};
*/
union dotstar_data
{
    uint32_t data;
    struct
    {
        /*
        uint8_t byte3;
        uint8_t byte2;
        uint8_t byte1;
        uint8_t byte0;
        */
        uint8_t byte0;
        uint8_t byte1;
        uint8_t byte2;
        uint8_t byte3;
    } bytes;
    struct
    {
        //uint8_t reserved : 3;
        //uint8_t global   : 5;
        uint8_t global;
        uint8_t blue;
        uint8_t green;
        uint8_t red;
    } values;
};

/** The total number of Dotstar LEDs in the strip. */
#define DOTSTAR_NUM_LEDS    60

/** Initialize the internal storage for the dotstar LEDs.
 *  All LEDs will be initialized with maximum global brightness and no color.
 */
void dotstar_init(void);

/** Set the global brightness value for the Dotstar LEDs.
 *
 *  @param brightness A value in the range 0-31. The value 31 sets the LEDs to
 *  their maximum brightness, and the value 0 turns the LEDs off.
 *  @returns 0 if the global brightness was set succesfully.
 */
int dotstar_set_global(uint8_t brightness);

/** Set the value of an LED.
 *
 *  @param led_num The index of the LED to adjust. The index must be greater
 *  than or equal to 0 and less than @ref DOTSTAR_NUM_LEDS.
 *  @returns 0 if the LED was set correctly.
 */
int dotstar_set_led(size_t led_num, uint8_t red, uint8_t green, uint8_t blue);

int dotstar_get_data(uint8_t **out_data, uint16_t *out_size);

/** Write the current stored values of the LEDs out to the strip.
 */
//int dotstar_write(void);

#endif //__DOTSTAR_H

