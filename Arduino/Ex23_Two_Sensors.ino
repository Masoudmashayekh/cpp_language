#include <Wire.h>
#define sensor_1 0x4A      // Address
#define sensor_2 0x4B      // Address
//------------------------------------------------------------------------------------------------------------------------------------------
void setup() {
Serial.begin(9600);
Wire.begin();
}
//-------------------------------------------------------------------------------------------------------------------------------------------
void loop() {
Wire.beginTransmission(sensor_1);
Wire.write(0x03);
Wire.endTransmission(false);
Wire.requestFrom(sensor_1,1);
if (Wire.available()) {
  byte highByte = Wire.read();

  int E3 = (highByte >> 7) & 0x01;
  int E2 = (highByte >> 6) & 0x01;
  int E1 = (highByte >> 5) & 0x01;
  int E0 = (highByte >> 4) & 0x01;
  int M7 = (highByte >> 3) & 0x01;
  int M6 = (highByte >> 2) & 0x01;
  int M5 = (highByte >> 1) & 0x01;
  int M4 = highByte & 0x01;

  int exponent = 8*E3 + 4*E2 + 2*E1 + E0;
  int mantissa = 8*M7 + 4*M6 + 2*M5 + M4;
  float luxValue = pow(2,exponent) * mantissa * 0.72;

  Serial.print("Senor_1 (lux): ");
  Serial.print(luxValue);
  Serial.flush();
}
delay(1);

Wire.beginTransmission(sensor_2);
Wire.write(0x03);
Wire.endTransmission(false);
Wire.requestFrom(sensor_2,1);
if (Wire.available()) {
  byte highByte = Wire.read();

  int E3 = (highByte >> 7) & 0x01;
  int E2 = (highByte >> 6) & 0x01;
  int E1 = (highByte >> 5) & 0x01;
  int E0 = (highByte >> 4) & 0x01;
  int M7 = (highByte >> 3) & 0x01;
  int M6 = (highByte >> 2) & 0x01;
  int M5 = (highByte >> 1) & 0x01;
  int M4 = highByte & 0x01;

  int exponent = 8*E3 + 4*E2 + 2*E1 + E0;
  int mantissa = 8*M7 + 4*M6 + 2*M5 + M4;
  float luxValue = pow(2,exponent) * mantissa * 0.72;

  Serial.print(", Senor_2 (lux): ");
  Serial.println(luxValue);
  Serial.flush();
  
}
delay(100);
}
