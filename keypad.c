/*
 * keypad.c
 *
 * Created: 9/29/2020 8:08:23 PM
 *  Author: Rita
 */ 

#include "keypad.h"

/* Array that holds the value returned for each button */
uint8_t keypad_matrix[] = 
{
	7 , 4 , 1 , 14,
	8 , 5 , 2 , 0,
	9 , 6 , 3 , 15,
	10 , 11 , 12 , 13,
};


void keypad_init()
{
	KEYPAD_PORT_INIT();			// Set keypad pins direction & enable pull up for inputs
}

uint8_t keypad_read()
{
	/* Select pin 4 to be 0 and other pins 5 6 7 to be 1 */
	PORTD = 0b11101111;
	/* Read input pins & return the value of the corresponding pressed button */
	if (READBIT(PIND,0) == 0){_delay_ms(1); return keypad_matrix[0];}
	if (READBIT(PIND,1) == 0){_delay_ms(1); return keypad_matrix[1];}
	if (READBIT(PIND,2) == 0){_delay_ms(1); return keypad_matrix[2];}
	if (READBIT(PIND,3) == 0){_delay_ms(1); return keypad_matrix[3];}
	
	_delay_ms(1);
	
	/* Select pin 5 to be 0 and other pins 4 6 7 to be 1 */
	PORTD = 0b11011111;
	/* Read input pins & return the value of the corresponding pressed button */
    if (READBIT(PIND,0) == 0){_delay_ms(1); return keypad_matrix[4];}
	if (READBIT(PIND,1) == 0){_delay_ms(1); return keypad_matrix[5];}
	if (READBIT(PIND,2) == 0){_delay_ms(1); return keypad_matrix[6];}
	if (READBIT(PIND,3) == 0){_delay_ms(1); return keypad_matrix[7];}
		
	_delay_ms(1);
	
	/* Select pin 6 to be 0 and other pins 4 5 7 to be 1 */
	PORTD = 0b10111111;
	/* Read input pins & return the value of the corresponding pressed button */
    if (READBIT(PIND,0) == 0){_delay_ms(1); return keypad_matrix[8];}
	if (READBIT(PIND,1) == 0){_delay_ms(1); return keypad_matrix[9];}
	if (READBIT(PIND,2) == 0){_delay_ms(1); return keypad_matrix[10];}
	if (READBIT(PIND,3) == 0){_delay_ms(1); return keypad_matrix[11];}
		
	_delay_ms(1);
	
	/* Select pin 7 to be 0 and other pins 4 5 6 to be 1 */
	PORTD = 0b01111111;
	/* Read input pins & return the value of the corresponding pressed button */
	if (READBIT(PIND,0) == 0){_delay_ms(1); return keypad_matrix[12];}
	if (READBIT(PIND,1) == 0){_delay_ms(1); return keypad_matrix[13];}
	if (READBIT(PIND,2) == 0){_delay_ms(1); return keypad_matrix[14];}
	if (READBIT(PIND,3) == 0){_delay_ms(1); return keypad_matrix[15];}
	
	/* Default value if no button is pressed */	
	return '$';
}