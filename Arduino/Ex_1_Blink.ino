void setup() {
pinMode(6,OUTPUT);
}

void loop() {
  digitalWrite(6,HIGH);
  delay(1000); //1ms
  digitalWrite(6,LOW);
  delay(1000);
}
