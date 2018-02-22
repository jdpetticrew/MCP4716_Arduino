#include "MCP4716.h"

MCP4716::MCP4716(){
  //Uses Default address.
};
MCP4716::MCP4716(int adrs){
  address=adrs;
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
  Wire.write(B1); // Write Bit
  Wire.write(B011); //Command Bit
  if(Vref==1){
    Wire.write(B00); //Vdd
  }
  else if (Vref==2){
    Wire.write(B10); // VrefUnbuf
  }
  else if (Vref==3){
    Wire.write(B11);
  }

  Wire.write(B00); //Power down Bits

  if (G==1){
    Wire.Write(B0); //Gain=1
  }
  else Wire.Write(B1); //Gain =2
};

void MCP4716::setVout(uint16_t Vout){
  uint16_t set= Vout << 6;
  byte set_upper= (byte) (set >> 8);
  byte set_lower= (byte) (set && 0x0f);

  Wire.beginTransmission(address);
  command();
  Wire.write(set_upper);
  Wire.write(set_lower);
  Wire.endTransmission;
};
