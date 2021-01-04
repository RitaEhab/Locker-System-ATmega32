/*
 * LCD.h
 *
 * Created: 9/20/2020 4:04:02 PM
 *  Author: Rita
 */ 


#ifndef LCD_H_
#define LCD_H_


#include "std_macros.h"

/* LCD PINS CONNECTION
 * D7	PA7  
 * D6	PA6  
 * D5	PA5  
 * D4	PA4  
 * RS	PA3  
 * EN	PA2  
 */

/* Set LCD pins direction as output */
#define  LCD_PORT_INIT() DDRA |= 0b11111100;

/* Apply logic 1 or logic 0 to data & control pins */
#define D7(x) if(x == 0) CLRBIT(PORTA,7); else SETBIT(PORTA,7);
#define D6(x) if(x == 0) CLRBIT(PORTA,6); else SETBIT(PORTA,6);
#define D5(x) if(x == 0) CLRBIT(PORTA,5); else SETBIT(PORTA,5);
#define D4(x) if(x == 0) CLRBIT(PORTA,4); else SETBIT(PORTA,4);
#define RS(x) if(x == 0) CLRBIT(PORTA,3); else SETBIT(PORTA,3);
#define EN(x) if(x == 0) CLRBIT(PORTA,2); else SETBIT(PORTA,2);

/* LCD Commands */
#define SHIFT_LEFT			0x18
#define SHIFT_RIGHT			0x1C
#define MOVE_CURSOR_LEFT	0x10
#define MOVE_CURSOR_RIGHT	0x14
#define CLEAR_DISPLAY		0x01
#define CURSOR_ON			0x0E
#define CURSOR_OFF			0x0C
#define NEXT_LINE			0xC0


/*
 * Function: Initialize LCD
 * Parameter: no input
 * Output: no return
 */
void lcd_init(void);

/*
 * Function: Send command to LCD
 * Parameter: [uint8] command
 * Output: no return
 */
void lcd_write_command(uint8_t c);

/*
 * Function: Write char on LCD
 * Parameter: [uint8] character to be written
 * Output: no return
 */
void lcd_write_char(uint8_t data);

/*
 * Function: Write string on LCD
 * Parameter: [uint8] string to be written
 * Output: no return
 */
void lcd_write_string(uint8_t* data);

/*
 * Function: Write number on LCD
 * Parameter: [uint8] number to be written
 * Output: no return
 */
void lcd_write_num(uint32_t num);


#endif /* LCD_H_ */