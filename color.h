
#ifndef __COLOR_H
#define __COLOR_H

#include <stdint.h>

typedef struct rgb_color
{
    uint8_t r;
    uint8_t g;
    uint8_t b;
} rgb;

typedef struct hsv_color
{
    uint8_t h;
    uint8_t s;
    uint8_t v;
} hsv;

const rgb color_yellow = {
    .r = 255,
    .g = 255,
    .b = 0,
};
const rgb color_orange = {
    .r = 255,
    .g = 87,
    .b = 20,
};
const rgb color_red = {
    .r = 255,
    .g = 0,
    .b = 0,
};
const rgb color_blue = {
    .r = 0,
    .g = 0,
    .b = 255,
};
const rgb color_green = {
    .r = 0,
    .g = 255,
    .b = 0,
};
const rgb color_teal = {
    .r = 0,
    .g = 255,
    .b = 255,
};


rgb color_add_rgb(rgb one, rgb two);

hsv color_add_hsv(hsv one, hsv two);

rgb color_hsv_to_rgb(hsv in_hsv);

hsv color_rgb_to_hsv(rgb in_rgb);

int color_rgb_to_string(rgb c, char **out_str);

int color_hsv_to_string(hsv c, char **out_str);

#endif //__COLOR_H

