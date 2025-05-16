int PWM=9;

void setup() {
  pinMode(PWM,OUTPUT);  
}

void loop() {
 for (int i=0; i<256; i+=10)
 {analogWrite(PWM,i);
 delay(100);}

}
