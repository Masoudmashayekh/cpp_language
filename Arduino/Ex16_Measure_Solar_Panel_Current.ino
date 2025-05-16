// include the library code:
#include <LiquidCrystal.h>  //library for LCD

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(13, 12, 11, 10, 9, 8);

//Measuring Current Using ACS712
int sensitivity = 66;  // use 185 for 5A Module and 100 for 20A Module
int adcvalue = 0;
int offsetvoltage = 2500;  //Sensor Callibration
double Voltage = 0;        //voltage measuring
double ecurrent = 0;       // Current measuring

void setup() {
  lcd.begin(20, 4);  // set up the LCD's number of columns and rows:
  lcd.setCursor(0, 0);
  lcd.print("   Progetto n.63   ");
  lcd.setCursor(0, 1);
  lcd.print(" Current Measurement  ");
}

void loop() {
  // Measure The Current ***********************************
  adcvalue = analogRead(A0);             //reading the value from the analog pin A0
  Voltage = (adcvalue / 1024.0) * 5000;  // Gets you mV
  ecurrent = ((Voltage - offsetvoltage) / sensitivity);
  lcd.setCursor(0, 3);
  lcd.print("  Current = ");
  lcd.print(ecurrent);
  lcd.print("A");  //unit for the current to be measured
  delay(200);
}
