 int redPin=9;
 int greenPin=10;
 int bluePin=11;

void setup()
{
 pinMode(redPin,OUTPUT);
 pinMode(greenPin,OUTPUT);
 pinMode(bluePin,OUTPUT);
}

void loop()
{
 setColor(255,0,0);
 delay(100);
 setColor(0,255,0);
 delay(100);
 setColor(0,0,255);
 delay(100);
 setColor(0,255,0);
 delay(100);
 setColor(255,0,0);
 delay(100);
 setColor(0,0,0);
 delay(100);
 setColor(255,255,255);
 delay(100);
  setColor(0,0,0);
 delay(100);
 setColor(255,255,255);
 delay(100);
setColor(0,0,0);
 delay(100);
}

void setColor(int red, int green, int blue)
{
 analogWrite(redPin,red);
 analogWrite(greenPin,green);
 analogWrite(bluePin,blue);
}