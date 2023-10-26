/*
 * app.h
 *
 * Created: 8/20/2023 10:14:13 PM
 *  Author: ayman
 */ 

#include "../HAL/led.h"
#include "../HAL/LCD.h"


#ifndef APP_H_
#define APP_H_

#define LCD_PORT PORT_C
#define CONROL_PORT PORT_A
#define output_port PORT_D 
#define button 3


typedef enum output_pins
{
	botel_1 , botel_2 , botel_3 , botel_4 , red , green , routiting_motor , filling_motor
} output_pins ;

void app_int(void);
void welcome_mode(void);
void end_mode(void);
void filling_bottle_1(void);
void routing(void);
void filling_bottle_2(void);
void filling_bottle_3(void);
void filling_bottle_4(void);
void app_st(void);




#endif /* APP_H_ */