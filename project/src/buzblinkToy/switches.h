#ifndef switches_included
#define switches_included

//Switches from green board
#define S1 BIT0
#define S2 BIT1
#define S3 BIT2
#define S4 BIT3
#define SWITCHES (S1 | S2 | S3 | S4)

void switch_init();
void switch_interrupt_handler();

extern char switch_state_down, switch_state_changed, state; /* effectively boolean */

#endif // included
