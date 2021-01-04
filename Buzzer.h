/*
 * Buzzer.h
 *
 * Created: 10/4/2020 2:53:08 PM
 *  Author: Rita
 */ 


#ifndef BUZZER_H_
#define BUZZER_H_

#include "std_macros.h"

#define BUZZER_PORT_INIT()		SETBIT(DDRA, 0);
#define BUZZER_ON()				SETBIT(PORTA, 0);
#define BUZZER_OFF()			CLRBIT(PORTA, 0);	

/*
 * Function: initialize buzzer
 * Parameters: no input
 * Output: no return
 */
void buzzer_init();

/*
 * Function: buzzer will be on for 3 sec and then off 
 * Parameters: no input
 * Output: no return
 */
void buzzer_3_sec();

/*
 * Function: buzzer will be on for 100 msec and then off 
 * Parameters: no input
 * Output: no return
 */
void buzzer_100ms();

#endif /* BUZZER_H_ */