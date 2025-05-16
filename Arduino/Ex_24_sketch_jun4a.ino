#include <OneWire.h>
#include <DallasTemperature.h>
#define ONE_WIRE_BUS 4                                     // Data wire is connect to the Arduino digital pin 4
OneWire oneWire(ONE_WIRE_BUS);                            // Setup a oneWire instance to communicate with any OneWire devices
DallasTemperature sensors(&oneWire);                     // Pass our oneWire reference to Dallas Temperature sensor 

#include <Wire.h>
#define sensor_1 0x4A      // Address

//------------------------------------------------------------------------------------------------------------------------------------------
void setup() {
Serial.begin(9600);
Wire.begin();
sensors.begin();                                       // Start up the library
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
  Serial.print(" , ");
  delay(100);
}

sensors.requestTemperatures();                    // Call sensors.requestTemperatures() to issue a global temperature and Requests to all devices on the bus
Serial.print(sensors.getTempCByIndex(0));
Serial.print(" C   ,   ");
Serial.print(sensors.getTempFByIndex(0));
Serial.print(" F");
if(sensors.getTempCByIndex(0)>30)
{Serial.println("   So Hot");}
if (sensors.getTempCByIndex(0)<17)
{Serial.println("   So Cold");}
if (sensors.getTempCByIndex(0)>=17 & sensors.getTempCByIndex(0)<=30)
{Serial.println("   Normal Temperature");}
delay(1000);

}
