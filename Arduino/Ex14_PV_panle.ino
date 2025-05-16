// include the library code:
#include <LiquidCrystal.h> // library for LCD
LiquidCrystal lcd(13,12,11,10,9,8);
//------------------------------------------------------------------------------------------------------------------------------------------------------------
// Measuring Current using ACS712
int sensitivity=185; // use 100 for 20A module and 66 for 30A module
int adcvalue=0;
int offsetvoltage=2511; // sensor callibration
double Voltage=0; // voltage measuring
double ecurrent=0; // current measuring
//----------------------------------------------------------------------------------------------------------------------------------------------------------
void setup() {
pinMode(7,OUTPUT); //MOSFET pin
digitalWrite(7,LOW); // Initially Turn off the MOSFET

// set up the LCD's numbers of columns and rows:
lcd.begin(16,2);
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------
void loop() {

//Measure the Voltage:
int sensorValue=analogRead(A1);
//Convert analog Reading (which goes from 0-1023 ) to a voltage 0-5V :
float vol=(sensorValue*5.0)/1023.0;
float Voltage=vol*5;
lcd.setCursor(0,0);
lcd.print("Voltage=");
lcd.print(Voltage);
lcd.print(" V");

//Measure the Voltage:
digitalWrite(7,HIGH); // Turn on the MOSFET 
delay(100);
adcvalue=analogRead(A0);
delay(100);
digitalWrite(7,LOW);
Voltage=(adcvalue/1024.0)*5000.0; //Get you mV
ecurrent=((Voltage-offsetvoltage)/sensitivity);
lcd.setCursor(0, 1);
lcd.print("Current=");
lcd.print(ecurrent);
lcd.print(" A");
delay(2000);







}











