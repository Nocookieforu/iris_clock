
#define BUTTON_INTEGRATE_MAX   10

struct button
{
    int integrate;
    int state;
    int pressed;
};

int button_init(struct button *b);

int button_update(struct button *b, int value);

int button_was_pressed(struct button *b);

