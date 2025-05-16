// include the library code: 
#include <LiquidCrystal.h> //library for LCD 

// initialize the library with the numbers of the interface pins 
LiquidCrystal lcd(13, 12, 11, 10, 9, 8); 

void setup() 
{
  lcd.begin(20, 4); // set up the LCD's number of columns and rows:
  lcd.setCursor(0,0);
  lcd.print("   Progetto n.63   ");
  lcd.setCursor(0,1)
  lcd.print(" Voltage Measurement ");
} 

void loop()
{ 
  // Measure The Votage ***********************************
  // read the input on analog pin A0:
  int sensorValue = analogRead(A0);
  // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
  float vol = (sensorValue * 5.0) / 1024.0;

  float voltage = vol * 6;
  lcd.setCursor(0,3);
  lcd.print("  Voltage = ");
  lcd.print(voltage);
  lcd.print("V");
  delay(200);
}

