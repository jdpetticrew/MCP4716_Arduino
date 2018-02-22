#ifndef MCP4716_H
#define MCP4716_H

#include <Wire.h>
#include <stdint.h>
class MCP4716{
private:
  command();
  int address=0x60;
  int Gain=1;
  uint16_t Vout=0;
  int Vref=1;
  int Cmd=3; // Option Not Available to user, function to be added
public:
  MCP4716(int address);
  setGain(int Gain); //1=x1, 2=x2
  setVout(uint16_t Vout);
  setVref(int Vref); // 1=Vdd, 2=VrefUnbuf, 3=VrefBuff
};
#endif
