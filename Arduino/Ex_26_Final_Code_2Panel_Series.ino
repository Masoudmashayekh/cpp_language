//****************************************************** Voltage Sensor (Panel 1) **************************************************************************************
int analogInput1 = A1; 
float vout1 = 0.0; 
float Vin1 = 0.0; 
float R1 = 30000.0; //   
float R2 = 7500.0; //  
int value1 = 0; 
//****************************************************** Voltage Sensor (Panel 2) **************************************************************************************
int analogInput2 = A2; 
float vout2 = 0.0; 
float Vin2 = 0.0; 
float R3 = 30000.0; //   
float R4 = 7500.0; //  
int value2 = 0; 
//****************************************************** Current Sensor **************************************************************************************

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
  pinMode(analogInput1, INPUT); 
  pinMode(analogInput2, INPUT); 
  Serial.begin(9600);    // Start serial communication for debugging purposes
 
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
    lcd.print((luxValue)); 
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
  lcd.print("Temp: ");
  lcd.print((sensors.getTempCByIndex(0)));
  lcd.print(" C"); 
  delay(1000);
  lcd.clear();
 ///////////////////////////////////////////////////////////////// Current sensor //////////////////////////////////////////////////////////////////////////////
 unsigned int x=0;
 float AcsValue=0.0,Samples=0.0,AvgAcs=0.0,AcsValueF=0.0;

  for (int x = 0; x < 150; x++){ //Get 150 samples
  AcsValue = analogRead(A0);     //Read current sensor values   
  Samples = Samples + AcsValue;  //Add samples together
  delay (3); // let ADC settle before next sample 3ms
 }
 AvgAcs=Samples/150.0;//Taking Average of Samples

 //((AvgAcs * (5.0 / 1024.0)) is converitng the read voltage in 0-5 volts
 //2.5 is offset(I assumed that arduino is working on 5v so the viout at no current comes
 //out to be 2.5 which is out offset. If your arduino is working on different voltage than 
 //you must change the offset according to the input voltage)
 //0.100v(100mV) is rise in output voltage when 1A current flows at input
 AcsValueF = ((2.5 - (AvgAcs * (5.0 / 1024.0)) )/0.100) + 0.35;


  Serial.print("Current: ");
  Serial.print(AcsValueF);
  Serial.print(" A");
  Serial.print(" , ");

  lcd.setCursor(0, 0);
  lcd.print("Current: ");
  lcd.print(AcsValueF); 
  lcd.print(" A"); 
 ////////////////////////////////////////////////////////////  Panel 1 & 2  //////////////////////////////////////////////////////////////////////////////  
  value1 = analogRead(analogInput1); 
  vout1 = (value1 * 5.0) / 1024.0; // see text 
  Vin1 = vout1 / (R2/(R1+R2));  

  Serial.print("Voltage(P1): ");
  Serial.print(Vin1);
  Serial.print(" V");
  Serial.print(" , ");
  
  value2 = analogRead(analogInput2); 
  vout2 = (value2 * 5.0) / 1024.0; // see text 
  Vin2 = vout2 / (R4/(R3+R4)); 
  float Vinall = Vin2 + Vin1;

  Serial.print("Voltage(P2): ");
  Serial.print(Vin2); 
  Serial.print(" V");
  Serial.print(" , ");

  Serial.print("Voltage(all): ");
  Serial.print(Vinall);
  Serial.println(" V");
  

  lcd.setCursor(0, 1);
  lcd.print("Voltage: ");
  lcd.print((Vinall)); 
  lcd.print(" V");
  delay(1000);
  lcd.clear();

}
