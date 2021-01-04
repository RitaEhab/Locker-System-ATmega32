/*
 * Buzzer.c
 *
 * Created: 10/4/2020 2:53:17 PM
 *  Author: Rita
 */ 
#include "Buzzer.h"
#include "std_macros.h"

void buzzer_init()
{
	BUZZER_PORT_INIT();
}

void buzzer_3_sec()
{
	BUZZER_ON();
	_delay_ms(1000);
	_delay_ms(1000);
	_delay_ms(1000);
	BUZZER_OFF();
	_delay_ms(100);
}

void buzzer_100ms()
{
	BUZZER_ON();
	_delay_ms(100);
	BUZZER_OFF();
	_delay_ms(10);
}