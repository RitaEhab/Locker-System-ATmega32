/*
 * keypad.h
 *
 * Created: 9/29/2020 8:08:12 PM
 *  Author: Rita
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_

#include "std_macros.h"

/* KEYPAD PINS CONNECTION
 * PD0 -> PD3 [input]  
 * PD4 -> PD7 [output] 
 */

/* Set keypad pins direction & enable pull up for inputs */
#define KEYPAD_PORT_INIT()		DDRD = 0xf0; PORTD |= 0x0f;

/*
 * Function: initialize keypad
 * Parameter: no input
 * Output: no return
 */
void keypad_init();

/*
 * Function: read the value pressed on keypad
 * Parameter: no input
 * Output: [uint8] value of button pressed
 */
uint8_t keypad_read();



#endif /* KEYPAD_H_ */