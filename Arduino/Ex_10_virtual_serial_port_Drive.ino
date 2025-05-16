int LED=8;
int In=9;
int count;

void setup() 
{
 pinMode(LED,OUTPUT);
 pinMode(In,INPUT_PULLUP);

 Serial.begin(9600);
}

void loop() 
{
 while(Serial.available()>0)
 {count=Serial.parseInt();
 if (digitalRead(In)==LOW)
 {for (int i=0;i<count;i++)
 {digitalWrite(LED,HIGH);
 delay(250);
 digitalWrite(LED,LOW);
 delay(250);
 }}}
 delay(10);
}
