/*
 * app.h
 *
 * Created: 12/29/2020 8:55:20 PM
 *  Author: Rita
 */ 


#ifndef APP_H_
#define APP_H_


#include "std_macros.h"
#include "Buzzer.h"
#include "keypad.h"
#include "EEPROM.h"

/* LED PA1 */
#define LED_INIT()		SETBIT(DDRA, 1);
#define LED_ON()		SETBIT(PORTA, 1);
#define LED_OFF()		CLRBIT(PORTA, 1);


/*
 * Function: Initialize system modules
 * Parameter: no input
 * Output: no return
 */
void System_init();

/*
 * Function: Set initial password to certain EEPROM addresses valid only if this is first time to use
 * Parameter: no input
 * Output: no return
 */
void checkMemory();

/*
 * Function: Change password of locker
 * Parameter: no input
 * Output: no return
 */
void changePassword();

/*
 * Function: Enter password to open the locker
 * Parameter: no input
 * Output: [uint8_t] password correct or not
 */
uint8_t enterPassword();

/*
 * Function: Take actions on locker when it's open like changing 
 *			 password & activate buzzer if pressing wrong keys.
 * Parameter: no input
 * Output: [uint8_t] locker status. 0: Open		1: Closed
 */
uint8_t takeOpenLockerActions();

#endif /* APP_H_ */