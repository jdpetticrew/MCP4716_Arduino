#include "MCP4716.hpp"
#include "Arduino.h"
#include <Wire.h>

MCP4716::MCP4716(int adrs){
  address=adrs;
  Gain=1;
  Vref=1;
  Cmd=3; // Option Not Available to user, function to be added
};

void MCP4716::setGain(int G){
  if(G==1) Gain=1;
  else Gain=2;
};

void MCP4716::setVref(int Vr){
  // 1=Vdd, 2=VrefUnbuf, 3=VrefBuff
  Vref=Vr;
};

void MCP4716::command(){
  uint8_t command;
  command=96; //Command Bit

  if(Vref==1){
    command=command+0; //Vdd
  }
  else if (Vref==2){
    command=command+16; // VrefUnbuf
  }
  else if (Vref==3){
    command=command+24;
  }

  command=command+00;; //Power down Bits

  if (Gain==1){
    command=command+0;; //Gain=1
  }
  else command=command+1; //Gain =2
  byte com=(byte) command;
  Wire.write(com);
};

void MCP4716::setVout(uint16_t Vout){
  uint16_t set= Vout << 6;
  byte set_upper= (byte) (set >> 8);
  uint8_t set_l = (uint8_t) set;
  byte set_lower= (byte) set_l;

  Wire.beginTransmission(address);
  command();
  Wire.write(set_upper);
  Wire.write(set_lower);
  Wire.endTransmission();
};
