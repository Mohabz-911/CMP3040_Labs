#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#define SET_BIT(reg,pin) (reg|=(1<<pin))
#define CLEAR_BIT(reg,pin) (reg&=~(1<<pin))
#define TOGGLE_BIT(reg,pin) (reg^=(1<<pin))


ISR(INT0_vect) {
  for (int i=0; i<5; i++) {
    PORTC = 0x07;
    _delay_ms(500);
    PORTC = 0x00;
    _delay_ms(500);
  }
  }

  void INT0_Init (void) {
    SREG &= ~(1<<7);
    DDRD &= (~(1<<PD2));
    EIMSK |= (1<<INT0);
    EICRA |= (1<<ISC00) | (1<<ISC01);
    SREG |= (1<<7);
  }


  int main (void) {
    int pin = 0;
    INT0_Init();  
    DDRC = DDRC | (1<<PC0)| (1<<PC1)| (1<<PC2);
    PORTC = PORTC | (1<<PC0);
    while (1){
       SET_BIT(PORTC,pin);
       _delay_ms(300);
       CLEAR_BIT(PORTC,pin);
       if(pin==2)pin = 0;
       else pin++;
      }
    }
  
