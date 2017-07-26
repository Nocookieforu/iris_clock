
#ifndef __COLOR_H
#define __COLOR_H

#include <stdint.h>

struct color
{
  uint8_t red;
  uint8_t green;
  uint8_t blue;
};


static struct color color_yellow = {
  .red = 255,
  //.green = 195,
  .green = 150,
  .blue = 0,
};
static struct color color_orange = {
  .red = 255,
  .green = 87,
  .blue = 20,
};
static struct color color_red = {
  .red = 199,
  .green = 0,
  .blue = 20,
};


struct color add_colors(struct color one,
                        struct color two);

#endif //__COLOR_H

