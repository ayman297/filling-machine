/*
 * back_led.c
 *
 * Created: 5/18/2023 5:24:52 PM
 * Author : ayman
 */ 

#include "app/app.h"



int main(void)
{
    
	app_int();
	u8 x ;
	while (1) 
    {
	DIO_read(CONROL_PORT,button,&x);
		if (x==1)
		{
			app_st();
		}
	 
	}
}

