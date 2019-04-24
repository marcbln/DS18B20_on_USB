//  This Arduino sketch reads DS18B20 "1-Wire" digital
//  temperature sensors.
//  Copyright (c) 2010 Mark McComb, hacktronics LLC
//  License: http://www.opensource.org/licenses/mit-license.php (Go crazy)
//  Tutorial:
//  http://www.hacktronics.com/Tutorials/arduino-1-wire-tutorial.html

#include <OneWire.h>
#include <DallasTemperature.h>

// Data wire is plugged into pin 3 on the Arduino
#define ONE_WIRE_BUS 2

// Setup a oneWire instance to communicate with any OneWire devices
OneWire oneWire(ONE_WIRE_BUS);

// Pass our oneWire reference to Dallas Temperature. 
DallasTemperature sensors(&oneWire);

// http://www.hacktronics.com/Tutorials/arduino-1-wire-address-finder.html
DeviceAddress insideThermometer = { 0x28, 0xD6, 0x6D, 0xD3, 0x05, 0x00, 0x00, 0x29 };
//DeviceAddress outsideThermometer = { 0x28, 0x6B, 0xDF, 0xDF, 0x02, 0x00, 0x00, 0xC0 };

void setup(void)
{
  // start serial port
  Serial.begin(9600);
  // Start up the library
  sensors.begin();
  // set the resolution to 10 bit (good enough?)
  sensors.setResolution(insideThermometer, 10);
  // sensors.setResolution(outsideThermometer, 10);
}


void loop(void)
{ 
  sensors.requestTemperatures();
  float tempC = sensors.getTempC(insideThermometer);
  Serial.print(tempC);
  Serial.print(" °C");
  Serial.print("\n");

  delay(2000);
  
//  Serial.print("\n\r");
//  Serial.print("Outside temperature is: ");
//  printTemperature(outsideThermometer);
}
