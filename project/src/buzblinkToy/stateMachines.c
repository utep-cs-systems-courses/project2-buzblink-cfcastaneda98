#include <msp430.h>
#include "stateMachines.h"
#include "led.h"
#include "buzzer.h"
#include "notes.h"


void toggle_red() /*always toggle!*/
{
  static char state = 0;
  
  switch (state) {
  case 0: 
    red_on = 1;
    state = 1;
    break;
  case 1: 
    red_on = 0;
    state = 0;
    break;
  }
  led_update();
}

void toggle_green() /* only toggle green if red is on! */
{
  static char state = 0;
  switch (state) {
  case 0: 
    green_on = 1;
    state = 1;
    break;
  case 1: 
    green_on = 0;
    state = 0;
    break;
  }
  led_update();
}

void toggle_r25() //dim at 25
{
  static char state = 0;
  switch (state) {
  case 0: 
    red_on = 0;
    state = 1;
    break;
  case 1: 
    red_on = 0;
    state = 2;
    break;
  case 2: 
    red_on = 1;
    state = 0;
    break;
  }
  led_update();
}

void toggle_g25() //Green at 25% intensity
{
  static char state = 0;
  switch (state) {
  case 0: //Red off
    green_on = 0;
    state = 1;
    break;
  case 1: //Red off
    green_on = 0;
    state = 2;
    break;
  case 2: //Red on
    green_on = 1;
    state = 0;
    break;
  }
  led_update();
}

void dim()
{
  static char state = 0;
  switch (state) {
  case 0: 
    toggle_red();
    toggle_green();
    state = 1;
    break;
  case 1:
    toggle_g25();
    toggle_r25();
    toggle_g25();
    state = 2;
  case 2: 
    toggle_r25();
    toggle_g25();
    toggle_r25();
    state = 0;
    break;
  }
}

void turn_green_on() //Only green will be on
{
  green_on = 1;
  red_on = 0;
  led_update();
}

void turn_red_on() //Only red will be on
{
  red_on = 1;
  green_on = 0;
  led_update();
}

void buzz_song_zelda() //Plays Lost Woods
{
  static char note = 0;

  //Alternates notes found in the song to compose jingle
  switch(note) {
  case 0: 
    buzzer_set_period(0);
    dim();
    note++;
    break;
  case 1: 
    buzzer_set_period(F);
    note++;
    break;
  case 2: 
    buzzer_set_period(A);
    note++;
    break;
  case 3: 
    buzzer_set_period(B);
    note++;
    break;
  case 4: 
    buzzer_set_period(B);
    note++;
    break;
  case 5: 
    buzzer_set_period(F);
    note++;
    break;
  case 6: 
    buzzer_set_period(A);
    note++;
    break;
  case 7: 
    buzzer_set_period(B);
    note++;
    break;
  case 8: 
    buzzer_set_period(B);
    note++;
    break;
  case 9: 
    buzzer_set_period(F);
    note++;
    break;
  case 10: 
    buzzer_set_period(A);
    note++;
    break;
  case 11: 
    buzzer_set_period(B);
    note++;
    break;
  case 12: 
    buzzer_set_period(E);
    note++;
    break;
  case 13:
    buzzer_set_period(D);
    note++;
    break;
  case 14: 
    buzzer_set_period(D);
    note++;
    break;
  case 15:
    buzzer_set_period(B);
    note++;
    break;
  case 16:
    buzzer_set_period(CNOTE);
    note++;
    break;
  case 17: 
    buzzer_set_period(B);
    note++;
    break;
  case 18: 
    buzzer_set_period(G);
    note++;
    break;
  case 19: 
    buzzer_set_period(E);
    note++;
    break;
  case 20: 
    buzzer_set_period(E);
    note++;
    break;
  case 21: 
    buzzer_set_period(E);
    note++;
    break;
  case 22: 
    buzzer_set_period(E);
    note++;
    break;
  case 23: 
    buzzer_set_period(E);
    note++;
    break;
  case 24: 
    buzzer_set_period(D);
    note++;
    break;
  case 25: 
    buzzer_set_period(E);
    note++;
    break;
  case 26:
    buzzer_set_period(G);
    note++;
    break;
  case 27: 
    buzzer_set_period(E);
    note++;
    break;
  case 28: 
    buzzer_set_period(E);
    note++;
    break;
  case 29: 
    buzzer_set_period(E);
    note++;
    break;
  case 30: 
    buzzer_set_period(E);
    note++;
    break;
  case 31: 
    buzzer_set_period(E);
    note++;
    break;
  case 32: 
    buzzer_set_period(E);
    note++;
    break;
  case 33: //Start from  to beggining
    buzzer_set_period(0);
    note = 0;
    break;
  default:
    note++;
  }
}  

void buzz_song_mario()
{
  //Alternates notes to compose jingle
  static char note = 0;
  switch(note){
  case 0: 
    buzzer_set_period(E);
    dim();
    note++;
    break;
  case 1:
    buzzer_set_period(E);
    note++;
    break;
  case 2: 
    buzzer_set_period(C);
    note++;
    break;
  case 3: 
    buzzer_set_period(C);
    note++;
    break;
  case 4: 
    buzzer_set_period(G);
    note++;
    break;
  case 5: 
    buzzer_set_period(A);
    note++;
    break;
  case 6: 
    buzzer_set_period(CNOTE);
    note++;
    break;
  case 7: 
    buzzer_set_period(0);
    note++;
    break;
  case 8: 
    buzzer_set_period(CNOTE);
    note++;
    break;
  case 9: 
    buzzer_set_period(CNOTE);
    note++;
    break;
  case 10: 
    buzzer_set_period(CNOTE);
    note++;
    break;
  case 11: 
    buzzer_set_period(A);
    note++;
    break;
  case 12: 
    buzzer_set_period(G);
    note++;
    break;
  case 13:
    buzzer_set_period(CNOTE);
    note++;
    break;
  case 14: 
    buzzer_set_period(0);
    note++;
    break;
  case 15: 
    buzzer_set_period(CNOTE);
    note++;
    break;
  case 16: 
    buzzer_set_period(G);
    note++;
    break;
  case 17:
    buzzer_set_period(E);
    note++;
    break;
  case 18: 
    buzzer_set_period(D);
    note++;
    break;
  case 19: 
    buzzer_set_period(D);
    note++;
    break;
  case 20: 
    buzzer_set_period(G);
    note++;
    break;
  case 21: 
    buzzer_set_period(E);
    note++;
    break;
  case 22:
    buzzer_set_period(E);
    note++;
    break;
  case 23: 
    buzzer_set_period(E);
    note++;
    break;
  case 24: 
    buzzer_set_period(CNOTE);
    note++;
    break;
  case 25: 
    buzzer_set_period(CNOTE);
    note++;
    break;
  case 26: 
    buzzer_set_period(G);
    note++;
    break;
  case 27: 
    buzzer_set_period(A);
    note++;
    break;
  case 28:
    buzzer_set_period(CNOTE);
    note++;
    break;
  case 29: 
    buzzer_set_period(0);
    note++;
    break;
  case 30:
    buzzer_set_period(CNOTE);
    note++;
    break;
  case 31: 
    buzzer_set_period(CNOTE);
    note++;
    break;
  case 32: 
    buzzer_set_period(A);
    note++;
    break;
  case 33: 
    buzzer_set_period(G);
    note++;
    break;
  case 34: 
    buzzer_set_period(CNOTE);
    note++;
    break;
  case 35:
    buzzer_set_period(F);
    note++;
    break;
  case 36: 
    buzzer_set_period(E);
    note++;
    break;
  case 37: 
    buzzer_set_period(D);
    note++;
    break;
  case 38: 
    buzzer_set_period(CNOTE);
    note++;
    break;
  case 39: 
    buzzer_set_period(CNOTE);
    note++;
    break;
  case 40: 
    buzzer_set_period(CNOTE);
    note++;
    break;
  case 41:
    buzzer_set_period(0);
    note = 0;
    break;
  default:
    note++;
  }
}

void buzz_song_pokemon()
{
  //Alternates notes to produce jingle
  static char note = 0;
  switch(note){
  case 0:
    buzzer_set_period (G);
    dim();
    note++;
    break;
  case 1:
    buzzer_set_period (F);
    note++;
    break;
  case 2:
    buzzer_set_period (E);
    note++;
    break;
  case 3:
    buzzer_set_period (D);
    note++;
    break;
  case 4:
    buzzer_set_period (C);
    note++;
    break;
  case 5:
    buzzer_set_period (A);
    note++;
    break;
  case 6:
    buzzer_set_period (B);
    note++;
    break;
  case 7:
    buzzer_set_period (A);
    note++;
    break;
  case 8:
    buzzer_set_period (G);
    note++;
    break;
  case 9:
    buzzer_set_period (G);
    note++;
    break;
  case 10:
    buzzer_set_period (G);
    note++;
    break;
  case 11:
    buzzer_set_period (E);
    note++;
    break;
  case 12:
    buzzer_set_period (C);
    note++;
    break;
  case 13:
    buzzer_set_period (C);
    note++;
    break;
  case 14:
    buzzer_set_period (0);
    note++;
    break;
  case 15:
    buzzer_set_period (C);
    note++;
    break;
  case 16:
    buzzer_set_period (D);
    note++;
    break;
  case 17:
    buzzer_set_period (E);
    note++;
    break;
  case 18:
    buzzer_set_period (F);
    note++;
    break;
  case 19:
    buzzer_set_period (F);
    note++;
    break;
  case 20:
    buzzer_set_period (F);
    note++;
    break;
  case 21:
    buzzer_set_period (F);
    note++;
    break;
  case 22:
    buzzer_set_period (F);
    note++;
    break;
  case 23:
    buzzer_set_period (B);
    note++;
    break;
  case 24:
    buzzer_set_period (C);
    note++;
    break;
  case 25:
    buzzer_set_period (D);
    note++;
    break;
  case 26:
    buzzer_set_period (E);
    note++;
    break;
  case 27:
    buzzer_set_period (E);
    note++;
    break;
  case 28:
    buzzer_set_period (E);
    note++;
    break;
  case 29:
    buzzer_set_period (F);
    note++;
    break;
  case 30:
    buzzer_set_period (E); 
    note++;
    break;
  case 31:
    buzzer_set_period (D);
    note++;
    break;
  case 32: 
    buzzer_set_period(D);
    note = 0;
    break;
  case 33:
    buzzer_set_period (D);
    note++;
    break;
  case 34:
    buzzer_set_period (D);
    note++;
    break;
  case 35: 
    buzzer_set_period(0);
    note = 0;
    break;
  default:
    note++;
  }
}

void buzz_song_kirby() //Plays Kirby song
{
  //Alternates notes to produce jingle
  static char note = 0;
  
  switch(note) {
  case 0: 
    buzzer_set_period(FSH);
    dim();
    note++;
    break;
  case 1: 
    buzzer_set_period(GSH);
    note++;
    break;
  case 2: 
    buzzer_set_period(ASH);
    note++;
    break;
  case 3: 
    buzzer_set_period(B);
    note++;
    break;
  case 4: 
    buzzer_set_period(ASH);
    note++;
    break;
  case 5: 
    buzzer_set_period(B);
    note++;
    break;
  case 6: 
    buzzer_set_period(CSH);
    note++;
    break;
  case 7: 
    buzzer_set_period(GSH);
    note++;
    break;
  case 8: 
    buzzer_set_period(E);
    note++;
    break;
  case 9: 
    buzzer_set_period(FSH);
    note++;
    break;
  case 10: 
    buzzer_set_period(GSH);
    note++;
    break;
  case 11: 
    buzzer_set_period(ASH);
    note++;
    break;
  case 12: 
    buzzer_set_period(B);
    note++;
    break;
  case 13:
    buzzer_set_period(ASH);
    note++;
    break;
  case 14: 
    buzzer_set_period(B);
    note++;
    break;
  case 15: 
    buzzer_set_period(CNOTE);
    note++;
    break;
  case 16: 
    buzzer_set_period(CNOTE);
    note++;
    break;
  case 17: 
    buzzer_set_period(CNOTE);
    note++;
    break;
  case 18: 
    buzzer_set_period(CNOTE);
    note++;
    break;
  case 19: 
    buzzer_set_period(CNOTE);
    note++;
    break;
  case 20: 
    buzzer_set_period(E);
    note++;
    break;
  case 21: 
    buzzer_set_period(E);
    note++;
    break;
  case 22: 
    buzzer_set_period(E);
    note++;
    break;
  case 23: 
    buzzer_set_period(FSH);
    note++;
    break;
  case 24: 
    buzzer_set_period(GSH);
    note++;
    break;
  case 25: 
    buzzer_set_period(ASH);
    note++;
    break;
  case 26: 
    buzzer_set_period(B);
    note++;
    break;
  case 27: 
    buzzer_set_period(ASH);
    note++;
    break;
  case 28: 
    buzzer_set_period(B);
    note++;
    break;
  case 29: 
    buzzer_set_period(CNOTE);
    note++;
    break;
  case 30: 
    buzzer_set_period(CNOTE);
    note++;
    break;
  case 31: 
    buzzer_set_period(F);
    note++;
    break;
  case 32: 
    buzzer_set_period(GSH);
    note++;
    break;
  case 33: 
    buzzer_set_period(E);
    note++;
    break;
  case 34: 
    buzzer_set_period(E);
    note++;
    break;
  case 35: 
    buzzer_set_period(G);
    note++;
    break;
  case 36: 
    buzzer_set_period(F);
    note++;
    break;
  case 37: 
    buzzer_set_period(F);
    note++;
    break;
  case 38: 
    buzzer_set_period(E);
    note++;
    break;
  case 39: 
    buzzer_set_period(D);
    note++;
    break;
  case 40: 
    buzzer_set_period(D);
    note++;
    break;
  case 41: 
    buzzer_set_period(E);
    note++;
    break;
  case 42: 
    buzzer_set_period(CSH);
    note++;
    break;
  case 43: 
    buzzer_set_period(CSH);
    note++;
    break;
  case 44: 
    buzzer_set_period(CSH);
    note++;
    break;
  case 45:
    buzzer_set_period(CNOTE);
    note++;
    break;
  case 46: 
    buzzer_set_period(CNOTE);
    note++;
    break;
  case 47:
    buzzer_set_period(CNOTE);
    note++;
    break;
  case 48: 
    buzzer_set_period(0);
    note = 0;
    break;
  default:
    note++;
  }
}
