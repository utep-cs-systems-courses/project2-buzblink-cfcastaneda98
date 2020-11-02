#include <msp430.h>
#include "libTimer.h"
#include "led.h"
#include "buzzer.h"
#include "switches.h"

void main(void)
{
  configureClocks();
  led_init();
  buzzer_init();
  switch_init();
  enableWDTInterrupts();
  or_sr(0x18);   //CPU off, GIE on
}
