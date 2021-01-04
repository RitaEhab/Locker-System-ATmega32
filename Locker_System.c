/*
 * Locker_System.c
 *
 * Created: 10/4/2020 2:50:03 PM
 *  Author: Rita
 */ 

#include "app.h"

int main(void)
{
	System_init();							// Initialize system modules
	uint8_t locker_closed = 1;					// Variable holds the state of the locker whether open or closed
	checkMemory();							// Set initial password valid only if this is first time to use
	uint8_t errorStatus = enterPassword();				// Enter password to open the locker		
	while (errorStatus)						// Locker remains closed until user enters correct password
	{
		buzzer_3_sec();						// Activate buzzer for 3 seconds
		errorStatus = enterPassword();				// Enter password to open the locker
	}
	locker_closed = 0;						// locker is now open
	
	while(1)
    {
		if(!locker_closed)
		{
			LED_ON();					// LED ON indicates open locker 
			locker_closed = takeOpenLockerActions();	// Change password & activate buzzer if pressing wrong keys
		}		
		
		else
		{
			LED_OFF();					// LED OFF indicates closed locker
			_delay_ms(100);
			errorStatus = enterPassword();			// Enter password to open the locker		
			while (errorStatus) 				// Locker remains closed until user enters correct password
			{
				buzzer_3_sec();				// Activate buzzer for 3 seconds
				errorStatus = enterPassword();		// Enter password to open the locker
			}
			locker_closed = 0; 				// locker is now open
		}
	}
}
