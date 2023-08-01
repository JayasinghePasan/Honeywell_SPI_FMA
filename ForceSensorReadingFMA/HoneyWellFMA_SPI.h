#ifndef HoneyWellFMA_SPI_H
#define HoneyWellFMA_SPI_H

#include <SPI.h>

class HoneyWellFMA_SPI 
{
  public:
    HoneyWellFMA_SPI(int ssPin);
    void begin();
    double getForce();

  private:
    const int ssPin;
    
    int SPI_SPEED  = 800000;

    uint16_t raw_force_data = 0;
    uint16_t sensor_status = 0;

    const float output_max = 13107; // %80 of 14bit data.  // given by Honeywell
    const float output_min = 3276;  // %20 of 14 bit data. // given by HoneyWell

    double force_val = 0;
};

#endif
