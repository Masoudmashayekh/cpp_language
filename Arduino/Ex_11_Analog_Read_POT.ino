int reading;
int sensor=A0;
#include <LiquidCrystal.h>
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
 Serial.begin(9600);
 lcd.begin(16,2);
}

void loop() {
 reading=analogRead(sensor);
 Serial.println(reading);
 lcd.println(reading);
 delay(1000);
 lcd.clear();
 
}
