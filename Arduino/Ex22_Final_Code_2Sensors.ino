//***************************************************** Current Sensor **************************************************************************************

//***************************************************** Light Sensor **************************************************************************************
#include <Wire.h>                              
#define MAX44009_ADDR 0x4A                                 // I2C address of MAX44009
//************************************************* Temperature Sensor ************************************************************************************
#include <OneWire.h>
#include <DallasTemperature.h>
#define ONE_WIRE_BUS 4                                     // Data wire is connect to the Arduino digital pin 4
OneWire oneWire(ONE_WIRE_BUS);                            // Setup a oneWire instance to communicate with any OneWire devices
DallasTemperature sensors(&oneWire);                     // Pass our oneWire reference to Dallas Temperature sensor 
//***************************************************** LCD ***********************************************************************************************
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2); // set the LCD address to 0x27 for a 16 chars and 2 line display
//--------------------------------------------------- void setup ------------------------------------------------------------------------------------------
void setup(void)
{
  Serial.begin(9600);                                    // Start serial communication for debugging purposes
  sensors.begin();                                       // Start up the library (T_S)
  Wire.begin();                                          // 
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
    //Serial.print("Lux: ");
    Serial.print(luxValue);
    Serial.print(" ,");
    lcd.setCursor(0, 0);
    lcd.print("LUX:");
    lcd.setCursor(4, 0);
    lcd.print(round(luxValue)); 
  }
  ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  sensors.requestTemperatures();                 // Call sensors.requestTemperatures() to issue a global temperature and Requests to all devices on the bus
  Serial.print(sensors.getTempCByIndex(0));
  Serial.print(", ");
  Serial.print(sensors.getTempFByIndex(0));
  Serial.print(" ,");
  if(sensors.getTempCByIndex(0)>30)
  {Serial.println("   So Hot");}
  if (sensors.getTempCByIndex(0)<17)
  {Serial.println("   So Cold");}
  if (sensors.getTempCByIndex(0)>=17 & sensors.getTempCByIndex(0)<=30)
  {Serial.println("   Normal Temperature");}
  lcd.setCursor(0, 1);
  lcd.print("Battery(T):");
  lcd.setCursor(11, 1);
  lcd.print(round(sensors.getTempCByIndex(0))); 
  delay(100);
  ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 
  

}
