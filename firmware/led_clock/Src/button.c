
#include <stddef.h>
#include "button.h"

/** Initialize the button state storage struct.
 *
 *  @param b A pointer to an already initialized button struct.
 *  @returns A value less than one if an error occurred or zero if this
 *  function was successful.
 */
int button_init(struct button *b)
{
    if (b == NULL)
    {
        return -1;
    }

    b->integrate = 0;
    b->state = 0;
    b->pressed = 0;
    return 0;
}


/** Update the button debouncer based on the current input.
 *  This button debounce code is based on Kenneth Kuhn's button debounce code
 *  found in the following post on Hackaday:
 *
 *  http://hackaday.com/2010/11/09/debounce-code-one-post-to-rule-them-all/
 *  or on Kenneth Kuhn's site:
 *
 *  http://www.kennethkuhn.com/electronics/debounce.c
 *
 *  @param b Pointer to the state storage struct for the button debouncer.
 *  @param value The current value of the input pin as a boolean value. value
 *  should be high if the button is pressed, so this input value may require
 *  logical inversion if the input pin is pulled low by the button.
 */
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

/** Determine if the button has been pressed based on the latch in the state
 *  storage struct.
 *
 *  @param b A pointer to the state storage struct for the button debouncer.
 *  @returns A value greater than 0 if the button has been pressed since the
 *  button struct was initialized or the last time this method was checked.
 */
int button_was_pressed(struct button *b)
{
    int out = b->pressed;
    b->pressed = 0;
    return out;
}
