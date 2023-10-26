/*
 * app.c
 *
 * Created: 8/20/2023 10:14:26 PM
 *  Author: ayman
 */
#define F_CPU 1000000UL
#include <util/delay.h> 
#include "../app/app.h"

void app_int(void)
{
DIO_init(output_port,routiting_motor,output);
DIO_init(output_port,filling_motor,output);
DIO_init(output_port,botel_1,output);
DIO_init(output_port,botel_2,output);
DIO_init(output_port,botel_3,output);
DIO_init(output_port,botel_4,output);
DIO_init(output_port,red,output);
DIO_init(output_port,green,output);
DIO_init(CONROL_PORT,button,input);
LCD_Init();	
	
}
void welcome_mode(void)
{
	DIO_write(output_port,green,high);
	DIO_write(output_port,red,low);
	LCD_clear();
	LCDsendStringData("...welcome...");
	_delay_ms(3000);
	//LCD_clear();
}
void end_mode(void)
{
	DIO_write(output_port,green,low);
	DIO_write(output_port,red,high);
	LCD_clear();
	LCDsendStringData("machine is done");
	
}
void filling_bottle_1(void)
{
	DIO_write(output_port,filling_motor,high);
	LCD_clear();
	LCDsendStringData("filling bottle 1");
	led_blink(output_port,botel_1,10);
	DIO_write(output_port,filling_motor,low);
	led_on(PORT_D,botel_1);
	LCD_clear();
	LCDsendStringData("filling done");
	_delay_ms(3000);
	
	
	
}
void filling_bottle_2(void)
{
	DIO_write(output_port,filling_motor,high);
	LCD_clear();
	LCDsendStringData("filling bottle 2");
	led_blink(output_port,botel_2,10);
	DIO_write(output_port,filling_motor,low);
	led_on(output_port,botel_2);
	LCD_clear();
	LCDsendStringData("filling done");
	_delay_ms(3000);
	
	
	
}
void filling_bottle_3(void)
{
	DIO_write(PORT_D,filling_motor,high);
	LCD_clear();
	LCDsendStringData("filling bottle 3");
	led_blink(PORT_D,botel_3,10);
	DIO_write(PORT_D,filling_motor,low);
	led_on(PORT_D,botel_3);
	LCD_clear();
	LCDsendStringData("filling done");
	_delay_ms(3000);
	
	
	
}
void filling_bottle_4(void)
{
	DIO_write(PORT_D,filling_motor,high);
	LCD_clear();
	LCDsendStringData("filling bottle 4");
	led_blink(PORT_D,botel_4,10);
	DIO_write(PORT_D,filling_motor,low);
	led_on(PORT_D,botel_4);	
}
void routing(void)
{
	DIO_write(PORT_D,routiting_motor,high);
	LCD_clear();
	LCDsendStringData("wait  ");
	_delay_ms(3000);
	DIO_write(PORT_D,routiting_motor,low);
	
}
void app_st(void)
{
	DIO_write(output_port,botel_1,low);
	DIO_write(output_port,botel_2,low);
	DIO_write(output_port,botel_3,low);
	DIO_write(output_port,botel_4,low);
	welcome_mode();
	filling_bottle_1();
	routing();
	filling_bottle_2();
	routing();
	filling_bottle_3();
	routing();
	filling_bottle_4();
	end_mode();
}