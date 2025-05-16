#include <OneWire.h>
#include <DallasTemperature.h>
#define ONE_WIRE_BUS 4                                     // Data wire is connect to the Arduino digital pin 4
OneWire oneWire(ONE_WIRE_BUS);                            // Setup a oneWire instance to communicate with any OneWire devices
DallasTemperature sensors(&oneWire);                     // Pass our oneWire reference to Dallas Temperature sensor 
//-----------------------------------------------------------------------------------------------------------------------------------------------------
void setup(void)
{
  Serial.begin(9600);                                    // Start serial communication for debugging purposes
  sensors.begin();                                       // Start up the library
}
//----------------------------------------------------------------------------------------------------------------------------------------------------
void loop(void)
{   
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
  delay(100);
}
