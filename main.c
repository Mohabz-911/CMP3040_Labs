#define __AVR_ATmega328P__
#include <avr/io.h>
#include <util/delay.h>
#define 	SET_BIT(REG_NAME,BIT_NUMBER) 		REG_NAME |= (1<<BIT_NUMBER)
#define 	CLEAR_BIT(REG_NAME,BIT_NUMBER) 		REG_NAME &= (~(1<<BIT_NUMBER))
#define 	TOGGLE_BIT(REG_NAME,BIT_NUMBER) 	REG_NAME ^= (1<<BIT_NUMBER)


void main(void)
{
    //Setup

    while(1)
    {
        
    }
}