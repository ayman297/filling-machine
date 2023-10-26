/*
 * led.h
 *
 * Created: 5/18/2023 5:29:07 PM
 *  Author: ayman
 */ 

#include "../MCAL/dio.h"

#ifndef LED_H_
#define LED_H_



void led_on(PortNumber,PinNumber);

void led_off(PortNumber,PinNumber);

void led_togle(PortNumber,PinNumber);

void led_blink(u8 PortNumber, u8 PinNumber , int sec );



#endif /* LED_H_ */