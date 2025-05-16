//****************************************************** Voltage Sensor **************************************************************************************
const int analogPin = A0;  // Analog pin to which the voltage divider is connected
const float Vref = 5.0;    // Reference voltage of the Arduino (usually 5V for most boards)
const float R1 = 30000.0;  // Resistor R1 value in ohms
const float R2 = 7500.0;  // Resistor R2 value in ohms
//****************************************************** Current Sensor **************************************************************************************
#include "ACS712.h"
ACS712 sensor(ACS712_20A, A1);
//***************************************************** Light Sensor **************************************************************************************
#include <Wire.h>                              
#define MAX44009_ADDR 0x4A   // I2C address of MAX44009
//************************************************* Temperature Sensor ************************************************************************************
#include <OneWire.h>
#include <DallasTemperature.h>
#define ONE_WIRE_BUS 4    // Data wire is connect to the Arduino digital pin 4
OneWire oneWire(ONE_WIRE_BUS);    // Setup a oneWire instance to communicate with any OneWire devices
DallasTemperature sensors(&oneWire);  // Pass our oneWire reference to Dallas Temperature sensor 
//***************************************************** LCD ***********************************************************************************************
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2); // set the LCD address to 0x27 for a 16 chars and 2 line display
//--------------------------------------------------- void setup ------------------------------------------------------------------------------------------
void setup(void)
{
  Serial.begin(9600);    // Start serial communication for debugging purposes
   sensor.calibrate();   // Current sensor
  sensors.begin();      // Start up the library (T_S)
  Wire.begin();                                         
  lcd.init();         // initialize the lcd
  lcd.backlight();    // Turn on the LCD screen backlight
}
//---------------------------------------------------- void loop --------------------------------------------------------------------------------------------
void loop(void)
 {   
  Wire.beginTransmission(MAX44009_ADDR);
  Wire.write(0x03); // Start reading from Lux High Byte register
  Wire.endTransmission(false); // Keep the transmission alive for subsequent reading
  Wire.requestFrom(MAX44009_ADDR, 2); // Request 2 bytes (Lux High Byte and Lux Low Byte)
  if (Wire.available() == 2) { // Check if data is available
    byte highByte = Wire.read();
    byte lowByte = Wire.read();
    
    // Extract Exponent and Mantissa from Lux High Byte
    int exponent = (highByte >> 4) & 0x0F;
    int mantissa = ((highByte & 0x0F) << 4) | (lowByte & 0x0F);
    
    // Calculate Lux value
    float luxValue = pow(2, exponent) * mantissa * 0.045;

    // Print the Lux value to Serial Monitor
    Serial.print("Lux: ");
    Serial.print(luxValue);
    Serial.print(" , ");

    lcd.setCursor(0, 0);
    lcd.print("LUX: ");
    lcd.setCursor(5, 0);
    lcd.print(round(luxValue)); 
  }
 ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  sensors.requestTemperatures();                 // Call sensors.requestTemperatures() to issue a global temperature and Requests to all devices on the bus
  Serial.print(sensors.getTempCByIndex(0));
  Serial.print(" C");
  Serial.print(" , ");
  Serial.print(sensors.getTempFByIndex(0));
  Serial.print(" F");
  Serial.print(" , ");

  lcd.setCursor(0, 1);
  lcd.print("Battery(T):");
  lcd.setCursor(11, 1);
  lcd.print(round(sensors.getTempCByIndex(0))); 
  delay(1000);
  lcd.clear();
 ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 float I = sensor.getCurrentAC();
 //ignoring the value below 0.09
  if (I < 0.09) {
    I = 0;
  }
  Serial.print("Current: ");
  Serial.print(I);
  Serial.print(" A");
  Serial.print(" , ");

  lcd.setCursor(0, 0);
  lcd.print("Current: ");
  lcd.setCursor(9, 0);
  lcd.print(I); 
 //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////  
  int sensorValue = analogRead(analogPin);  // Read the analog input
  float voltage = sensorValue * (Vref / 1023.0);  // Convert the analog reading (0-1023) to a voltage (0-5V)
  float Vin = voltage * (R1 + R2) / R2;     // Calculate the input voltage using the voltage divider formula

  Serial.print("Voltage: ");
  Serial.print(Vin);
  Serial.print(" V");
  Serial.println(" , ");
  
  lcd.setCursor(0, 1);
  lcd.print("Voltage: ");
  lcd.setCursor(9, 1);
  lcd.print(round(Vin)); 
  delay(1000);
  lcd.clear();

}
