int speaker=12;
int count=10;
int tones[] = {200,230,280,320,380,400,420,450,480,490};

void setup() {
  for (int i=0;i<count;i++)
  {tone(speaker,tones[i]);
  delay(50);}
  noTone(speaker);
}

void loop() {

}
