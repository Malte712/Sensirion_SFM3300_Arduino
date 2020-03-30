/*
  SFM3300 - A Arduino Library for the Sensirion SFM3300 Sensor

  Created by Malte712 in March 2020

  WITHOUT ANY WARRANTY!
*/

#ifndef SFM3300_H
#define SFM3300_H


#include <inttypes.h>

typedef enum {
  SFM3300Address = 0x40, //(64)
} PRES_SENSOR_ADRESS;

typedef enum {
  StartMeasurementCmd = 0x1000, //Command to start am measurement  (only one time necessary)
  StopMeasurementCmd = 0x5050, //Command to stop Measurement (any comment possible after start)
  SoftResetCmd = 0x2000,   //Command for soft reset
} PRES_MEASUREMENT_CMD;

class SFM3300Class {
  private:
    bool readSensor(uint16_t* res);
    void writeSensor(uint16_t data);

  public:
    float GetFlow(void);
    void StartMeasuring(void);
    void StopMeasuring(void);
};

extern SFM3300Class SFM3300;

#endif
