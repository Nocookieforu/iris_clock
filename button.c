
#include "button.h"

void button_init(struct button *b)
{
  b->integrate = 0;
  b->state = 0;
  b->pressed = 0;
}

int button_update(struct button *b, int value)
{
  if (!value && b->integrate > 0)
  {
    b->integrate--;
  }
  else if (b->integrate < BUTTON_INTEGRATE_MAX)
  {
    b->integrate++;
  }
  
  if (b->integrate == 0)
  {
    b->state = 0;
    b->pressed = 0;
  }
  else if (b->integrate >= BUTTON_INTEGRATE_MAX)
  {
    b->integrate = BUTTON_INTEGRATE_MAX;
    if (b->state == 0)
    {
      b->pressed = 1;
    }
    b->state = 1;
  }
  
  return b->state;
}

int button_was_pressed(struct button *b)
{
  int out = b->pressed;
  b->pressed = 0;
  return out;
}
