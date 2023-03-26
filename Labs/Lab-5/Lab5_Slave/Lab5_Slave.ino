#include<avr/io.h>
#include<util/delay.h>
#define SS      PB2
#define MOSI    PB3
#define MISO    PB4
#define SCK     PB5

void SPI_Init() {
  DDRB &= ~(1 << SS);
  DDRB &= ~(1 << MOSI);
  DDRB &= ~(1 << SCK);
  DDRB |= (1 << MISO);
  SPCR |= (1 << SPE);
}

char SPI_Read() {
  
  while (!(SPSR & (1 << SPIF)));

  return (SPDR);
}
void SPI_Write(char data) {

  char flush_buffer;
  SPDR = data;
  while (!(SPSR & (1 << SPIF)));

  flush_buffer = SPDR;
}
uint8_t cnt = 0;
char buffer_[5];

void setup() {
  SPI_Init();

  Serial.begin(9600);
  delay(100);
  Serial.println("Slave start");
}


void loop() {
  cnt = SPI_Read();
  Serial.println(cnt);
  _delay_ms(100);
  SPI_Write(cnt+100);
  _delay_ms(100);
}
