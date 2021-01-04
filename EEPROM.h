/*
 * EEPROM.h
 *
 * Created: 9/20/2020 4:04:24 PM
 *  Author: Rita
 */ 


#ifndef EEPROM_H_
#define EEPROM_H_

#include "std_macros.h"

/*
 * Function: write value in certain address of EEPROM
 * Parameter: [uint16_t] address, [uint8_t] data
 * Output: no return
 */
void EEPROM_write(uint16_t addr, uint8_t data);

/*
 * Function: read value from certain address of EEPROM
 * Parameter: [uint16_t] address
 * Output: [uint8_t] data
 */
uint8_t EEPROM_read(uint16_t addr);



#endif /* EEPROM_H_ */