
#include "color.h"

struct color add_colors(struct color one,
                        struct color two)
{
    uint16_t r = (one.red   + two.red)   >> 1;
    uint16_t g = (one.green + two.green) >> 1;
    uint16_t b = (one.blue  + two.blue)  >> 1;

    struct color out = {
        .red   = r,
        .green = g,
        .blue  = b,
    };
    return out;
}
