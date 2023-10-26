/*
 * LCD.c
 *
 * Created: 1/4/2023 4:57:17 PM
 *  Author: ayman
 */ 
#include "LCD.h"
void LCDsendComand (u8 Command)
{
	//set RS 0 for command
	DIO_write(CONROL_PORT,RS,low);
	
	//set rw 0 for write comand
	DIO_write(CONROL_PORT,RW,low);
	
	/* set command to data pins */
	//DIO_SetPort(LCD_PORT_DATA,Command);
	PORTC = Command ;
	
	 /* set eneble pulse */
	 DIO_write(CONROL_PORT,E,high);
	 //timer_2mSec();
	 _delay_ms(2); 
	 DIO_write(CONROL_PORT,E,low);
	
}
void  LCDsendData (u8 data)
{
	//set RS 1 for data
	DIO_write(CONROL_PORT,RS,high);
	
	//set rw 0 for write data
	DIO_write(CONROL_PORT,RW,low);
	
	/* set command to data pins */
	//DIO_SetPort(LCD_PORT_DATA,data);
	PORTC = data ;
	
	/* set eneble pulse */
	DIO_write(CONROL_PORT,E,high);
	 _delay_ms(2); 
	DIO_write(CONROL_PORT,E,low);
	
}
void  LCD_Init (void)
{
	DIO_init(CONROL_PORT,RS,output);
	DIO_init(CONROL_PORT,RW,output);
	DIO_init(CONROL_PORT,E,output);
	
	DIO_init(LCD_PORT,0,output);
	DIO_init(LCD_PORT,1,output);
	DIO_init(LCD_PORT,2,output);
	DIO_init(LCD_PORT,3,output);
	DIO_init(LCD_PORT,4,output);
	DIO_init(LCD_PORT,5,output);
	DIO_init(LCD_PORT,6,output);
	DIO_init(LCD_PORT,7,output);
	
	
	 _delay_ms(40); 
		/* function set command : 2 line ,5*8 font size */
	LCDsendComand(0b00111000);
	
	/* display on off control */
	LCDsendComand(0b00001100);
	
	/* display clear */
	LCDsendComand(0b00000001);

}
void  LCDsendStringData(  char * data)
{
		u8 i = 0 ;
	while(data[i] != '\0')
	{
	LCDsendData	(data[i]);
	i++;
	}
}
void  LCD_clear()
{
	PORTC=0x01;
	DIO_write(CONROL_PORT,RS,low);
	DIO_write(CONROL_PORT,RW,low);
	DIO_write(CONROL_PORT,E,high);
	_delay_ms(2);
	DIO_write(CONROL_PORT,E,low);
	_delay_ms(10);
	
}
