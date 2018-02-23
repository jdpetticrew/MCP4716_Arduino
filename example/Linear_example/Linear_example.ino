#include <Wire.h>
#include "MCP4716.hpp"

MCP4716 MCP4716(0x60);

void setup() {
  // put your setup code here, to run once:
  Wire.begin(); // Join I2C as Master
  Wire.setClock(100000);
  MCP4716.setGain(1);
  MCP4716.setVref(1);
}

void loop() {

  int i;
  
  for(i=0;i<1024;i++){
  MCP4716.setVout(i);  
  delay(1000);
  }
}

