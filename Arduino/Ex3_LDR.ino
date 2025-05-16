int sensor;
int LED_1=6;
int LED_2=7;
void setup() {
pinMode(LED_1,OUTPUT);
pinMode(LED_2,OUTPUT);
}

void loop() {
sensor=analogRead(A1);
if (sensor<100)
{
digitalWrite(LED_1,HIGH);
  }
if (sensor>100)
{
digitalWrite(LED_1,LOW);
}
//-------------------------------------------------
if (sensor>100)
{
digitalWrite(LED_2,HIGH);
  }
if (sensor<100)
{
digitalWrite(LED_2,LOW);
}
}
