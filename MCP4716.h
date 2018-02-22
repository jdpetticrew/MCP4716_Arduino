#ifndef MCP4716_H
#define MCP4716_H

#include <Wire.h>
#include <stdint.h>
class MCP4716{
private:
  void command();
  int address=0x60; //DEFAULT ADDRESS
  int Gain=1;
  int Vref=1;
  int Cmd=3; // Option Not Available to user, function to be added
public:
  MCP4716(int adrs);
  void setGain(int G); //1=x1, 2=x2
  void setVout(uint16_t Vout);
  void setVref(int Vr); // 1=Vdd, 2=VrefUnbuf, 3=VrefBuff
};
#endif
