#ifndef _ROTARYENCODER_H
#define _ROTARYENCODER_H

/*
 * BROWN = GROUND
 * RED = OUTPUT
 * WIT = VCC
 */

void setupRotaryEncoder();
int updateRotaryMode();
void interruptRotary1();
void interruptRotary2();

#endif
