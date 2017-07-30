
#include "color.h"
#include <stdio.h>

rgb color_add_rgb(rgb one, rgb two)
{
    uint16_t red   = (one.r + two.r) >> 1;
    uint16_t green = (one.g + two.g) >> 1;
    uint16_t blue  = (one.b + two.b) >> 1;

    rgb out = {
        .r = red,
        .g = green,
        .b = blue,
    };
    return out;
}

hsv color_add_hsv(hsv one, hsv two)
{
    uint16_t hue = (one.h + two.h) >> 1;
    uint16_t sat = (one.s + two.s) >> 1;
    uint16_t val = (one.v + two.v) >> 1;

    hsv out = {
        .h = hue,
        .s = sat,
        .v = val,
    };
    return out;
}

static const char rgb_format_str[] = "color: (r = 0x%02X, g = 0x%02X, b = 0x%02X)\0";
int color_rgb_to_string(rgb c, char **out_str)
{
    return sprintf(*out_str, rgb_format_str, c.r, c.g, c.b);
}

static const char hsv_format_str[] = "color: (h = 0x%02X, s = 0x%02X, v = 0x%02X)\0";
int color_hsv_to_string(hsv c, char **out_str)
{
    return sprintf(*out_str, hsv_format_str, c.h, c.s, c.v);
}

rgb color_hsv_to_rgb(hsv in_hsv)
{
    rgb out_rgb;
    uint8_t region, remainder, p, q, t;

    if (in_hsv.s == 0)
    {
        out_rgb.r = in_hsv.v;
        out_rgb.g = in_hsv.v;
        out_rgb.b = in_hsv.v;
        return out_rgb;
    }

    region = in_hsv.h / 43;
    remainder = (in_hsv.h - (region * 43)) * 6;

    p = (in_hsv.v * (255 - in_hsv.s)) >> 8;
    q = (in_hsv.v * (255 - ((in_hsv.s * remainder) >> 8))) >> 8;
    t = (in_hsv.v * (255 - ((in_hsv.s * (255 - remainder)) >> 8))) >> 8;

    switch (region)
    {
        case 0:
            out_rgb.r = in_hsv.v;
            out_rgb.g = t;
            out_rgb.b = p;
            break;
        case 1:
            out_rgb.r = q;
            out_rgb.g = in_hsv.v;
            out_rgb.b = p;
            break;
        case 2:
            out_rgb.r = p;
            out_rgb.g = in_hsv.v;
            out_rgb.b = t;
            break;
        case 3:
            out_rgb.r = p;
            out_rgb.g = q;
            out_rgb.b = in_hsv.v;
            break;
        case 4:
            out_rgb.r = t;
            out_rgb.g = p;
            out_rgb.b = in_hsv.v;
            break;
        default:
            out_rgb.r = in_hsv.v;
            out_rgb.g = p;
            out_rgb.b = q;
            break;
    }

    return out_rgb;
}

hsv color_rgb_to_hsv(rgb in_rgb)
{
    hsv in_hsv;
    uint8_t rgbMin, rgbMax;

    rgbMin = in_rgb.r < in_rgb.g ? (in_rgb.r < in_rgb.b ? in_rgb.r : in_rgb.b)
                                 : (in_rgb.g < in_rgb.b ? in_rgb.g : in_rgb.b);
    rgbMax = in_rgb.r > in_rgb.g ? (in_rgb.r > in_rgb.b ? in_rgb.r : in_rgb.b)
                                 : (in_rgb.g > in_rgb.b ? in_rgb.g : in_rgb.b);

    in_hsv.v = rgbMax;
    if (in_hsv.v == 0)
    {
        in_hsv.h = 0;
        in_hsv.s = 0;
        return in_hsv;
    }

    in_hsv.s = 255 * (long)(rgbMax - rgbMin) / in_hsv.v;
    if (in_hsv.s == 0)
    {
        in_hsv.h = 0;
        return in_hsv;
    }

    if (rgbMax == in_rgb.r)
        in_hsv.h = 0 + 43 * (in_rgb.g - in_rgb.b) / (rgbMax - rgbMin);
    else if (rgbMax == in_rgb.g)
        in_hsv.h = 85 + 43 * (in_rgb.b - in_rgb.r) / (rgbMax - rgbMin);
    else
        in_hsv.h = 171 + 43 * (in_rgb.r - in_rgb.g) / (rgbMax - rgbMin);

    return in_hsv;
}
