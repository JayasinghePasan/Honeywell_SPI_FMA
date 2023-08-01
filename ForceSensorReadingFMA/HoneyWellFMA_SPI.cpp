#include "HoneyWellFMA_SPI.h"

HoneyWellFMA_SPI::HoneyWellFMA_SPI(int sspin)
    : ssPin(sspin) {}

void HoneyWellFMA_SPI::begin() 
{
  pinMode(ssPin, OUTPUT);     // define SS pin
  digitalWrite(ssPin, HIGH);  // disable sensor read
  SPI.begin();
}

double HoneyWellFMA_SPI::getForce() 
{
   
  SPI.beginTransaction(SPISettings(SPI_SPEED, MSBFIRST, SPI_MODE0));
  
  digitalWrite(ssPin,LOW);  // enable sensor read
  raw_force_data = SPI.transfer16(0);
  digitalWrite(ssPin,HIGH);  // disable sensor read
  
  SPI.endTransaction();

  raw_force_data = raw_force_data & 0b11111111111111;
  force_val = ((raw_force_data - output_min) * 25.0) / (output_max - output_min);

  return force_val;
}

