#ifndef led_included
#define led_included

#define LED_RED BIT0               // P1.0
#define LED_GREEN BIT6             // P1.6
#define LEDS (BIT0 | BIT6)

//This act as the boolean flags of the program
extern unsigned char red_on, green_on;
extern unsigned char led_changed;

char redOn;
char greenOn;

void led_init();
void led_update();

//Different modes used by the red LED
void activate_red();
void deactivate_red();
void dim_red();
void normal_red();
void bright red();

//Different modes used by the green LED
void activate_green();
void deactivate_green();
void dim_green();
void normal_green();
void bright_green();

#endif // included
