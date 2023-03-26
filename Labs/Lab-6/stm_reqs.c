void req1();
void req2();
void req3();

void main() {
  //Step_1: Enable LEDs in SW15
  GPIO_Digital_Output(&GPIOD_BASE, _GPIO_PINMASK_ALL); // Set PORTD as digital output
  GPIO_Digital_Output(&GPIOE_BASE, _GPIO_PINMASK_ALL); // Set PORTE as digital output

  GPIOD_ODR = 0;
  GPIOE_ODR = 0;

  while(1) {
    req3();
  }
}


void req1()
{
  GPIOD_ODR = ~GPIOD_ODR; // Toggle PORTD
  GPIOE_ODR = ~GPIOE_ODR; // Toggle PORTE
  Delay_ms(500);
}

void req2()
{
  char i;
  GPIOD_ODR = 0;
  GPIOE_ODR = 0;
  for(i = 0; i < 4; i++)
  {
    GPIOD_ODR = GPIOD_ODR ^ (0x1111 << i);
    GPIOE_ODR = GPIOE_ODR ^ (0x1111 << i);
    Delay_ms(100);
  }
}

void req3()
{
  //Include Button library (as in slides)
  //Configure the buttons on board to be active high (HIGH when pressed)
  //Setup section
  char counter = 0, b1 = 0, b2 = 0, prev_b1 = 0, prev_b2 = 0;
  GPIO_Digital_Input(&GPIOB_BASE, _GPIO_PINMASK_0);
  GPIO_Digital_Input(&GPIOB_BASE, _GPIO_PINMASK_1);
  
  //Loop section
  b1 = Button(&GPIOB_IDR, 0, 1, 1);
  b2 = Button(&GPIOB_IDR, 1, 1, 1);
  if(b1 == b2) return;  //Replace "return" with "continue"
  if(b1 == 1 && prev_b1 == 0) counter++;
  else if(b2 == 1 && prev_b2 == 0) counter--;
  
  if(counter > 15) counter = 15;
  if(counter < 0) counter = 0;
  
  GPIOD_ODR &= (counter & 0x0F);
  prev_b1 = b1;
  prev_b2 = b2;
}