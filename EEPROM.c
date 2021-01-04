/*
 * EEPROM.c
 *
 * Created: 9/20/2020 4:04:15 PM
 *  Author: Rita
 */ 

#include "EEPROM.h"

void EEPROM_write(uint16_t addr, uint8_t data)
{
	while(READBIT(EECR, EEWE) == 1){}		// Wait for completion of previous write operation
	EEAR = addr;							// Write addr to register
	EEDR = data;							// Write data to register
	SETBIT(EECR, EEMWE);					// Enable master write
	SETBIT(EECR, EEWE);						// Enable write
}

uint8_t EEPROM_read(uint16_t addr)
{
	while(READBIT(EECR, EEWE) == 1){}		// Wait for completion of previous write operation
	EEAR = addr;							// Write addr to register
	SETBIT(EECR, EERE);						// Enable read
	return EEDR;							// Return data register
}