/*
 * LCD.h
 *
 * Created: 1/4/2023 4:36:20 PM
 *  Author: ayman
 */ 


#ifndef LCD_H_
#define LCD_H_


#define F_CPU 1000000UL
#include "../MCAL/dio.h"
#include <util/delay.h>



#define LCD_PORT PORT_C
#define CONROL_PORT  PORT_A

typedef  enum cont
{
	RS , RW ,E
} cont ;


void  LCDsendComand(u8 Command);
 
void  LCDsendData(u8 data);

void  LCD_Init(void);

void  LCDsendStringData( char * data);

void  LCD_clear();












#endif /* LCD_H_ */