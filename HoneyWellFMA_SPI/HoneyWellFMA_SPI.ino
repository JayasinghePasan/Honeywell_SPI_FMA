#include "HoneyWellFMA_SPI.h"

HoneyWellFMA_SPI sensor1(53);
HoneyWellFMA_SPI sensor2(54);

void setup() 
{
  sensor1.begin();
  sensor2.begin();
}

void loop() 
{
  int val1 = sensor1.getForce();
  int val2 = sensor2.getForce(); 
}
