#ifndef MATH_BIT_H_
#define MATH_BIT_H_
#define F_CPU 1000000UL
#include <util/delay.h>



#define  SET_BIT(VAR,BIT_NO)            (VAR|=(1<<BIT_NO))

#define CLR_BIT(VAR,BIT_NO)            (VAR&=(~(1<<BIT_NO)))

#define TOGGLE_BIT(VAR,BIT_NO)         (VAR^=(1<<BIT_NO))

#define GET_BIT(VAR,BIT_NO)            ((VAR&(1<<BIT_NO))>>BIT_NO)

#endif


