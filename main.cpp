#include<SPI.h>

int batteryPin = A2;
int batteryVal = 0;

void setup() 

{
  Serial.begin(9600);

  pinMode(MISO, OUTPUT);

  SPCR |= _BV(SPE);
  SPCR |= _BV(SPIE);

}

// SPI interrupt routine
ISR (SPI_STC_vect) {
  byte c = SPDR;
  SPDR = int((analogRead(batteryPin)-440)/2);
}

void loop () {}
