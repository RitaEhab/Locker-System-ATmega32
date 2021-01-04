/*
 * CFile1.c
 *
 * Created: 9/20/2020 4:03:41 PM
 *  Author: Rita
 */ 

#include "lcd.h"

void lcd_init(void)
{
	LCD_PORT_INIT();					// Set LCD pins direction
	lcd_write_command(0x3);				// Initialize
	lcd_write_command(0x2);				// Enable 4 bit mode
	lcd_write_command(0x28);			// Function set 4 bit, 2 lines
	lcd_write_command(0x1);				// Clear display
	lcd_write_command(0x6);				// Entry mode
	lcd_write_command(0xc);				// Display on Cursor off
	_delay_ms(20);
}

void lcd_write_command(uint8_t x)
{
	RS(0);											// Write command
	D7(READBIT(x,7));								// Put highest nibble of command
	D6(READBIT(x,6));
	D5(READBIT(x,5));
	D4(READBIT(x,4));
	EN(1); _delay_ms(1); EN(0); _delay_ms(1);		// Enable pulse
	
	D7(READBIT(x,3));								// Put lowest nibble of command
	D6(READBIT(x,2));
	D5(READBIT(x,1));
	D4(READBIT(x,0));
	EN(1); _delay_ms(1); EN(0); _delay_ms(1);		// Enable pulse
}

void lcd_write_char(uint8_t x)
{
	RS(1);											// Write data
	D7(READBIT(x,7));								// Put highest nibble of data
	D6(READBIT(x,6));
	D5(READBIT(x,5));
	D4(READBIT(x,4));
	EN(1); _delay_ms(1); EN(0); _delay_ms(1);		// Enable pulse
	
	D7(READBIT(x,3));								// Put lowest nibble of data
	D6(READBIT(x,2));
	D5(READBIT(x,1));
	D4(READBIT(x,0));
	EN(1); _delay_ms(1); EN(0); _delay_ms(1);		// Enable pulse
}

void lcd_write_string(uint8_t* data)
{
	uint8_t i;
	for (i = 0; data[i] != '\0'; i++)				// Display char till '\0'
	lcd_write_char(data[i]);
}

void lcd_write_num(uint32_t num)
{
	uint8_t txt[10] = {0};				// Array holds the number in digits
	int8_t i = 0;						// Iterator
	if(num == 0)
	{
		lcd_write_char('0');
		return;
	}
	for(i = 0; num != 0; i++)
	{
		txt[i] = num%10 +48;			// Get the ASCII code of the rightmost digit
		num = num/ 10;					// Remove the rightmost digit
	}
	i--;
	while(i >= 0 )
	{
		lcd_write_char(txt[i]);			// Display the digits in reverse order
		i--;
	}
}