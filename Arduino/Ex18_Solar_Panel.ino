// include the library code: 
#include <LiquidCrystal.h> //library for LCD 

// initialize the library with the numbers of the interface pins 
LiquidCrystal lcd(13, 12, 11, 10, 9, 8); 

//Measuring Current Using ACS712 
int sensitivity = 66; // use 100 for 20A Module and 185 for 5A Module 
int adcvalue= 0; 
int offsetvoltage = 2500;  //Sensor Callibration
double Voltage = 0; //voltage measuring 
double Current = 0;// Current measuring 

void setup() 
{
  lcd.begin(20, 4); // set up the LCD's number of columns and rows:
  lcd.setCursor(0,0);
  lcd.print("   Solar Panel   ");
  
} 

void loop()
{ 
  // Measure The Votage ************************************************************************************************************************
  // read the input on analog pin A1:
  int sensorValue = analogRead(A1);
  // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
  float vol = (sensorValue * 5.0) / 1023.0;
  float voltage = vol * 5;
  lcd.setCursor(0,1); 
  lcd.print("  Voltage: "); 
  lcd.print(voltage); 
  lcd.print("V"); 
  delay(100);

  // Measure The Current ***********************************************************************************************************************
  adcvalue = analogRead(A0);//reading the value from the analog pin A0
  Voltage = (adcvalue / 1024.0) * 5000; // Gets you mV 
  Current = ((Voltage - offsetvoltage) / sensitivity); 
  lcd.setCursor(0,2); 
  lcd.print("  Current: "); 
  lcd.print(Current); 
  lcd.print("A"); 
  delay(100);

    // Measure The Power **************************************************************************************************************************
  float Power = voltage*Current; 
  lcd.setCursor(0,3); 
  lcd.print("  Power: "); 
  lcd.print(Power); 
  lcd.print("W"); //unit for the current to be measured 
  delay(100);
}


