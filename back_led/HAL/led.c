/*
 * led.c
 *
 * Created: 5/18/2023 5:29:28 PM
 *  Author: ayman
 */ 
#include "led.h"

void led_on(u8 PortNumber, u8 PinNumber)
{
	 DIO_write(PortNumber,PinNumber,high);
	
}
void led_off(u8 PortNumber,u8 PinNumber)
{
	DIO_write(PortNumber,PinNumber,low);
	
}
void led_togle(u8 PortNumber, u8 PinNumber )
{
		DIO_toggle(PortNumber,PinNumber);
}
void led_blink(u8 PortNumber, u8 PinNumber , int sec )
{
	sec=sec*8;
	for(int i = 0 ; i<sec ; i++)
	{
		DIO_toggle(PortNumber,PinNumber);
		_delay_ms(125);
		
	}
	
}