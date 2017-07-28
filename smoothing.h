

struct exponential_filter
{
    float value;
    float alpha;
    float one_sub_alpha;
};

int exponential_filter_init(struct exponential_filter *filt,
                            float  alpha);

void exponential_filter_update(struct exponential_filter *filt,
                               float  new_val);

