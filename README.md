# Sensirion_SFM3300_Arduino
A library to get the flow from the SFM3300 sensor from Sensirion.

# Installation on Arduino IDE
- First you have to download this repository as zip. 
- Then you have to select in the Arduino IDE Menubar:
    Sketch -> import library -> import Zip
- Select the downloaded repository and start your project :)

## Use of the library
Make sure you connected the sensor on the right way to the I2C pins on your Arduino. I am using an Arduino nano where SCL is connected to pin A5 and SDA to pin A4. Also dont forget the pullup-resistors, described in the datasheet. Too see how the library works take a look at the example sketch.
