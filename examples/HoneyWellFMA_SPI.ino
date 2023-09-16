#include "HoneyWellFMA_SPI.h"

//use following format when defining the sensor object
//HoneyWellFMA_SPI sensorName(SS-pin);
HoneyWellFMA_SPI sensor1(53); 
HoneyWellFMA_SPI sensor2(54);

void setup() 
{
  //start the sensor
  sensor1.begin();
  sensor2.begin();
}

void loop() 
{
  //read value of the sensor // use doubles for extra accuracy 
  //this can be used with 5N, 15N, 25N sensors with calibration
  //please calibrate your sensor with a known load first !!

  int val1 = sensor1.getForce(); //+ or - calibration error
  int val2 = sensor2.getForce(); //+ or - calibration error
}
