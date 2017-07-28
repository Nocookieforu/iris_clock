
#include <stddef.h>
#include "smoothing.h"

int exponential_filter_init(struct exponential_filter *filt,
                            float  alpha)
{
    if (filt == NULL)
    {
        return -1;
    }
    if (alpha <= 0.0f)
    {
        return -2;
    }
    else if (alpha > 1.0f)
    {
        return -3;
    }

    filt->value = 0;
    filt->alpha = alpha;
    filt->one_sub_alpha = 1.0f - alpha;
}

void exponential_filter_update(struct exponential_filter *filt,
                               float  new_val)
{
    filt->value = (filt->one_sub_alpha * filt->value) +
                  (filt->alpha         * new_val);
}

