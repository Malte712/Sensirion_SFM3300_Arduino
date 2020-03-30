
/*
  SFM3300_Flow
  This is an exmple sketch, to show how the library works.
  Created by Malte712 in March 2020
  WITHOUT ANY WARRANTY!
*/

#include "SFM3300.h"

void setup() {

  //Initialze serial console
  Serial.begin(9600);

  //Start Measuring (only one Time required)
  SFM3300.StartMeasuring();

}

void loop() {

  //get the Data
  float flow = SFM3300.GetFlow();

  //Print the data on the console
  Serial.print(flow);
  Serial.println(" liter per minute!");

}

/*
  Note:
  If you want to stop Measuring use SFM3300.StopMeasuring();
  To Measure after that again, you have to Start Measuring a second time
*/
