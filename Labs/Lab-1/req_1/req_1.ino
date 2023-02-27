#include <avr/io.h>
#include <util/delay.h>

#define SET_BIT(reg,pin) (reg|=(1<<pin))
#define CLEAR_BIT(reg,pin) (reg&=~(1<<pin))
#define TOGGLE_BIT(reg,pin) (reg^=(1<<pin))

// a b c d e g f

char prev = 1;

char x = 0;

int arr [10] = {0b00000010, 0b10011110, 0b00100100, 0b00001100, 0b10011000, 0b01001000, 0b01000000, 0b00011110, 0b00000000, 0b00001000};

void setup() {
  // put your setup code here, to run once:
  CLEAR_BIT(DDRB,0);
  SET_BIT(PORTB,0);

  //INTIALIZE LEDS
  DDRD = 0xFF;
  PORTD = arr[0];
}




void loop() {
  // put your main code here, to run repeatedly:
  if ((PINB & 0x01 == 1) && prev == 0) {
    if(x == 9) x = 0;
    else x++;
    PORTD = arr[x];
  }
  
  prev = (PINB & 0x01);
  _delay_ms(30);
}

//we have internal pull-up
