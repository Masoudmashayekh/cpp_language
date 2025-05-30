#include <ThemeTest.h>

int LED=9; //PWM
int sensor=A0; //analog
int reading;
#include <LiquidCrystal.h>
const int rs=12, en=11, d4=5, d5=4, d6=3, d7=2;
LiquidCrystal lcd(rs,en,d4,d5,d6,d7);

//-----------------------------------------------------------------------------------------
void setup() {
 pinMode(LED,OUTPUT);
 Serial.begin(9600);
 lcd.begin(16,2);
}

void loop() {
 reading= analogRead(sensor)/4;
 Serial.println(reading);
 analogWrite(LED,reading);
 lcd.setCursor(0,1);
 lcd.println(reading);
 delay(100); 
 lcd.clear(); 
}
