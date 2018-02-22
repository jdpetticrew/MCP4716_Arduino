#ifndef MCP4716_H
#define MCP4716_H
#include "Arduino.h"

#include <stdint.h>

class MCP4716 {
private:
  void command();
  int address; //DEFAULT ADDRESS
  int Gain;
  int Vref;
  int Cmd; // Option Not Available to user, function to be added
public:
  MCP4716(int adrs);
  void setGain(int G); //1=x1, 2=x2
  void setVout(uint16_t Vout);
  void setVref(int Vr); // 1=Vdd, 2=VrefUnbuf, 3=VrefBuff
};
#endif
