#define __AVR_ATmega328P__
#include <avr/io.h>
#include <avr/interrupt.h>
#define 	SET_BIT(REG_NAME,BIT_NUMBER) 		REG_NAME |= (1<<BIT_NUMBER)
#define 	CLEAR_BIT(REG_NAME,BIT_NUMBER) 		REG_NAME &= (~(1<<BIT_NUMBER))
#define 	TOGGLE_BIT(REG_NAME,BIT_NUMBER) 	REG_NAME ^= (1<<BIT_NUMBER)

ISR(INT0_vect)
{
    TOGGLE_BIT(PORTC,0);
}


void INT0_Init(void)
{
    CLEAR_BIT(SREG,0);
    CLEAR_BIT(DDRD,2);
    SET_BIT(EIMSK,0);
    EICRA |= 0x03;      //rising edge
    SET_BIT(SREG,0);
}

void main(void)
{
    //Setup
    INT0_Init();
    SET_BIT(DDRC,0);
    SET_BIT(PORTC,0);
    while(1)
    {
        
    }
}