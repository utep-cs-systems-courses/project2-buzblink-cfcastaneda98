#include <msp430.h>
#include "switches.h"
#include "led.h"

char switch_state_down, switch_state_changed; /* effectively boolean */

static char
switch_update_interrupt_sense()
{
  char p2val = P2IN;
  /* update switch interrupt to detect changes from current buttons */
  P2IES |= (p2val & SWITCHES);/* if switch up, sense down */
  P2IES &= (p2val | ~SWITCHES);/* if switch down, sense up */
  return p2val;
}

void
switch_init()/* setup switch */
{
  P2REN |= SWITCHES;/* enables resistors for switches */
  P2IE |= SWITCHES;/* enable interrupts from switches */
  P2OUT |= SWITCHES;/* pull-ups for switches */
  P2DIR &= ~SWITCHES;/* set switches' bits for input */
  switch_update_interrupt_sense();
  led_update();
}


void
switch_interrupt_handler()
{
  char p2val = switch_update_interrupt_sense();
  //Will change from a specific button in P2
  if ((p2val & S1) == 0)
    state = 0;
  else if ((p2val & S2) == 0) 
    state = 1;
  else if ((p2val & S3) == 0) 
    state = 2;
  else if ((p2val & S4) == 0) 
    state = 3;
}
