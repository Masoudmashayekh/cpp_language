void setup() {
  pinMode(1,OUTPUT);  // Red light
  pinMode(2,OUTPUT);  // Yellow light
  pinMode(3,OUTPUT);  // Green light
}
void loop() {
  digitalWrite(1,HIGH);
  delay(20000); //ms , 20s
  digitalWrite(1,LOW);
  digitalWrite(2,HIGH);
  delay(7000); //ms , 7s
  digitalWrite(2,LOW);
  digitalWrite(3,HIGH);
  delay(15000); //ms , 15s
  digitalWrite(3,LOW);
}
