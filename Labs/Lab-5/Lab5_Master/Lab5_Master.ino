#include<avr/io.h>
#include<util/delay.h>
#define SS      PB2
#define MOSI    PB3
#define MISO    PB4
#define SCK     PB5
void SPI_Init() {
  DDRB |= (1 << MOSI) | (1 << SCK) | (1 << SS);
  DDRB &= ~(1 << MISO);
  PORTB |= (1 << SS);
  SPCR = (1 << SPE) | (1 << MSTR) | (1 << SPR0);
  SPSR &= ~(1 << SPI2X);
}
void SPI_Write(char data) {

  char flush_buffer;
  SPDR = data;
  while (!(SPSR & (1 << SPIF)));

  flush_buffer = SPDR;

}
char SPI_Read() {
  SPDR = 0xff;
  while (!(SPSR & (1 << SPIF)));

  return (SPDR);
}

uint8_t cnt = 0;


void setup() {
  SPI_Init();

  Serial.begin(9600);
  Serial.println("Master start");
  PORTB &= ~(1 << SS);
  _delay_ms(1000);

}



void loop() {

  if (++cnt >= 101)
    cnt = 1;
  SPI_Write(cnt);
  _delay_ms(200);
  Serial.println(uint8_t(SPI_Read()));
   _delay_ms(100);
}
