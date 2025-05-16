// Burglar alarm  // 
int LED=6;
int sensor=A0;
int sensor_value;

void setup() {
pinMode(LED,OUTPUT);
pinMode(sensor,INPUT);
Serial.begin(9600);
}

void loop() {
sensor_value=analogRead(sensor);
Serial.println(sensor_value);
delay(50);

if (sensor_value<800)
{digitalWrite(LED,HIGH);}

if (sensor_value>800)
{digitalWrite(LED,LOW);}

}
