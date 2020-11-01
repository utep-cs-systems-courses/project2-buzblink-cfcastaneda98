#include <msp430.h>
#include "switches.h"
#include "led.h"

char switch_state_down, switch_state_changed; /* effectively boolean */

static char
switch_update_interrupt_sense()
{
  char p1val = P1IN;
  char p2val = P2IN;
  /* update switch interrupt to detect changes from current buttons */
  P1IES |= (p1val & SWITCHES);/* if switch up, sense down */
  P1IES &= (p1val | ~SWITCHES);/* if switch down, sense up */
  P2IES |= (p2val & SWITCHES2);
  P2IES &= (p2val | ~SWITCHES2);
  return p1val;
}


void
switch_init()/* setup switch */
{
  P1REN |= SWITCHES;/* enables resistors for switches */
  P2REN |= SWITCHES2;
  P1IE |= SWITCHES;/* enable interrupts from switches */
  P2IE |= SWITCHES2;
  P1OUT |= SWITCHES;/* pull-ups for switches */
  P2OUT |= SWITCHES2;
  P1DIR &= ~SWITCHES;/* set switches' bits for input */
  P2DIR &= ~SWITCHES2;
  switch_update_interrupt_sense();
  led_update();
}


void
switch_interrupt_handler()
{
  char p1val = switch_update_interrupt_sense();
  switch_state_down = (p1val & SW1) ? 0 : 1; /* 0 when SW1 is up */
  switch_state_changed = 1;
  led_update();
}
