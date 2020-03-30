/*
  SFM3300 - A Arduino Library for the Sensirion SFM3300 Sensor

  Created by Malte712 in March 2020

  WITHOUT ANY WARRANTY!
*/


#include <inttypes.h>
#include <Wire.h>
#include "Arduino.h"
#include "SFM3300.h"

#define OFFSET 32768    //Offset from the Datasheet     (32768 for the SFM3300)
#define SCALEFACTOR 120  //Scalefactor from the Datasheet   (120 for the SFM3300)

/******************************************************************************
   Global Functions
 ******************************************************************************/

/**********************************************************
   Get Flow -> Gets the actual Flow

   @return float - The Flow in liter per minute
 **********************************************************/
float SFM3300Class::GetFlow(void)
{
  uint16_t result;

  if (readSensor((uint16_t*)&result)) {

    //Calculate Flow
    float flow = ((float)result - OFFSET) / SCALEFACTOR;
    return (flow);

  } else {
    return -10000000;
  }
}

/**********************************************************
   StartMeasuring -> sends the command to start the Measurement
 **********************************************************/
void SFM3300Class::StartMeasuring(void) {
  Wire.begin();
  writeSensor(StartMeasurementCmd);
  delay(100);  //The Sonsor needs some time to deliver the first value
}

/**********************************************************
  StopMeasuring -> sends the Command to stop the Measurement
 **********************************************************/
void SFM3300Class::StopMeasuring(void) {
  writeSensor(StopMeasurementCmd);
}


/******************************************************************************
   Private Functions
 ******************************************************************************/

/**********************************************************
   readSensor -> picks the data from the sensor

   @return bool -> wether the read worked, or not
 **********************************************************/
bool SFM3300Class::readSensor(uint16_t* res) {

  uint8_t data[2];
  unsigned long startTime;

  delay(50);
  Wire.requestFrom(SFM3300Address, 2);

  startTime = millis();
  while (Wire.available() < 2) {
    //wait 500ms for results.
    if (millis() - startTime > 500) {
      return false;
    }
  }

  //Store the result
  data[0] = Wire.read();
  data[1] = Wire.read();

  //Put the result in once and give it to the pointer
  *res = (data[0] << 8) | data[1];
  
  return true;
}



/**********************************************************
   writeSensor -> writes the Data into the sensor
 **********************************************************/
void SFM3300Class::writeSensor(uint16_t data) {

  uint8_t bytes[2];

  bytes[0] = (data & 0xFF00) >> 8;
  bytes[1] = data & 0x00FF;

  Wire.beginTransmission(SFM3300Address);  //begin transmission
  Wire.write(bytes[0]);          //send the pointer location
  Wire.write(bytes[1]);          //send the pointer location
  delay(100);
  Wire.endTransmission();    //end Transmission
}



SFM3300Class SFM3300;
