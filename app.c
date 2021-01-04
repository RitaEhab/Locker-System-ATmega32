/*
 * app.c
 *
 * Created: 12/29/2020 8:55:05 PM
 *  Author: Rita
 */ 

#include "app.h"


void System_init()
{
	keypad_init();
	buzzer_init();
	LED_INIT();
}

void checkMemory()
{
	/* Read memory locations that hold the password */
	uint8_t data[4];
	data[0]= EEPROM_read(10);
	data[1]= EEPROM_read(11);
	data[2]= EEPROM_read(12);
	data[3]= EEPROM_read(13);
	
	/* First time to use EEPROM default values are 255. Make initial password to be 0000 */
	if ((data[0] == 255) && (data[1] == 255) && (data[2] == 255) && (data[3] == 255))
	{	
		EEPROM_write(10, 0);
		EEPROM_write(11, 0);
		EEPROM_write(12, 0);
		EEPROM_write(13, 0);
	}
}

uint8_t enterPassword ()
{
	uint8_t passwordEntered [4], passwordSaved [4];
	
	/* Get the 4 chars of the password from keypad */
	for(uint8_t t = 0; t < 4; t++)
	{
		uint8_t key = '$';
		while (key == '$')	{key = keypad_read();}
		passwordEntered[t] = key;
		_delay_ms(100);
	}
	
	/* Read memory locations that hold the saved password */
	passwordSaved [0] = EEPROM_read(10);
	passwordSaved [1] = EEPROM_read(11);
	passwordSaved [2] = EEPROM_read(12);
	passwordSaved [3] = EEPROM_read(13);
	
	/* Password entered is the same as the password saved before */
	if ((passwordSaved [0] == passwordEntered [0]) && (passwordSaved [1] == passwordEntered [1]) &&
		(passwordSaved [2] == passwordEntered [2]) && (passwordSaved [3] == passwordEntered [3]))
	{
		/* There is NO error! */
		return 0;
	}
	/* There IS error! */
	return 1;
}

void changePassword ()
{
	uint8_t newPassword [4];
	
	/* Get the new 4 chars of the password from keypad */
	for(uint8_t t = 0; t < 4; t++)
	{
		uint8_t key = '$';
		while (key == '$')	{key = keypad_read();}
		newPassword[t] = key;
		_delay_ms(100);
	}
	
	/* Write new password to memory locations holding password */
	EEPROM_write(10,newPassword[0]);
	EEPROM_write(11,newPassword[1]);
	EEPROM_write(12,newPassword[2]);
	EEPROM_write(13,newPassword[3]);
}

uint8_t takeOpenLockerActions()
{
	/* Get key pressed on keypad to select action accordingly */
	uint8_t key = '$';
	while (key == '$')	key = keypad_read();
	
	/* 'P' (=) Sign on keypad maps to "Change Password" */
	if (key == 15)
	{
		buzzer_3_sec();
		changePassword();
		key = '$';
		/* Press 'P' (=) again to confirm inserting password */
		while (key != 15)	key = keypad_read();
		
		key = '$';
		/* Press 'C' (ON/C) to close locker */
		while (key != 14)	key = keypad_read();
		/* Locker is now closed */
		return 1;
	}
	
	/* Any other key pressed, activates the buzzer */
	else
	{
		buzzer_100ms();
		/* Locker is now open */
		return 0;
	}
}
