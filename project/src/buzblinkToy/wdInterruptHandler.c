#include <msp430.h>
#include "stateMachines.h"
#include "led.h"
#include "buzzer.h"
#include "switches.h"

char state = 0;

void
__interrupt_vec(WDT_VECTOR) WDT(){/* 250 interrupts/sec */
  static char blink_count = 0;

  if (++blink_count == 50 && state == 0) {      //Plays Zelda Song
    buzz_song_zelda();
    blink_count = 0;
  }
  else if ((blink_count == 42) && state == 1) { //Plays Mario Song
    buzz_song_mario();
    blink_count = 0;
  }
  else if ((blink_count == 60) && state == 2) { //Plays Pokemon Song
    buzz_song_pokemon();
    blink_count = 0;
  }
  else if ((blink_count == 31) && state == 3) { //Plays Kirby Song
    buzz_song_kirby();
    blink_count = 0;
  }
}
