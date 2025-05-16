#include<LiquidCrystal.h>

LiquidCrystal lcd(7,6,5,4,3,2);
int ledpin= 13;
int ldrpin= A0;
//---------------------------------------------------------------------------------------------------------------------------------------------------------
void setup() {
  lcd.begin(20, 4);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Light Sensor");
  lcd.setCursor(0, 1);
  lcd.print("Progetto n.63");
  pinMode(ledpin,OUTPUT);
  pinMode(ldrpin,INPUT);
}
//-------------------------------------------------------------------------------------------------------------------------------------------------------
void loop() {
  int ldrstatus= analogRead(ldrpin);
  if(ldrstatus<=110){
    digitalWrite(ledpin,HIGH);
    lcd.setCursor(0, 2);
    lcd.print("LED ON!");
    lcd.setCursor(0, 3);
    lcd.print("Intensity:");
    lcd.setCursor(11, 3);
    lcd.print(ldrstatus);
  }
    else {
    digitalWrite(ledpin,LOW);
    lcd.setCursor(2, 2);
    lcd.print("LED OFF!");
    lcd.setCursor(3, 3);
    lcd.print("Intensity:");
    lcd.setCursor(11, 3);
    lcd.print(ldrstatus);
    }
  }
