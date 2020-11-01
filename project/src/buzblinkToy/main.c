#include <msp430.h>
#include "libTimer.h"
#include "led.h"
#include "buzzer.h"
#include "switches.h"
#include "stateMachines.h"

void main(void)
{
  configureClocks();
  led_init();
  buzzer_init();
  switch_init();
  enableWDTInterrupts();
  state_init();
  or_sr(0x18);   //CPU off, GIE on
}
