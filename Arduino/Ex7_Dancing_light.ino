// Dancing Light

void setup()
{
 for (int Pin=2;Pin<=9;Pin++)
 {pinMode(Pin,OUTPUT);}
 //pinMode(2,OUTPUT);
 //pinMode(3,OUTPUT);
 //pinMode(4,OUTPUT);
 //pinMode(5,OUTPUT);
 //pinMode(6,OUTPUT);
 //pinMode(7,OUTPUT);
 //pinMode(8,OUTPUT);
 //pinMode(9,OUTPUT);
}

void loop() 
{
 Turn_ON();
 delay(50);
 Turn_Off();
 delay(50);
 f1();
 delay(50);
 f2();
 delay(50);
 f3();
 delay(50);
 Turn_Off();
 delay(50);
 f4();
 delay(50);
 Turn_ON();
 delay(25);
 Turn_Off();
 delay(25);
 Turn_ON();
 delay(25);
 Turn_Off();
 delay(25);
}
//-----------------------------------------------------Function--------------------------------------------------------------------------------------------
void Turn_ON()
{
 //for (int i=2;i<=9;i++)
 //{digitalWrite(i,HIGH);} 
 digitalWrite(2,HIGH);
 digitalWrite(3,HIGH);
 digitalWrite(4,HIGH);
 digitalWrite(5,HIGH);
 digitalWrite(6,HIGH);
 digitalWrite(7,HIGH);
 digitalWrite(8,HIGH);
 digitalWrite(9,HIGH);
}
//----------------------------------------------------------------------------------------------------------------------------------------------------------
void Turn_Off()
{
 //for(int i=2;i<=9;i++)
 //{digitalWrite(i,LOW);}
 digitalWrite(2,LOW);
 digitalWrite(3,LOW);
 digitalWrite(4,LOW);
 digitalWrite(5,LOW);
 digitalWrite(6,LOW);
 digitalWrite(7,LOW);
 digitalWrite(8,LOW);
 digitalWrite(9,LOW);
}
//------------------------------------------------------------------------------------------------------------------------------------------------------------
void f1()
{
 for (int i=2;i<=9;i++)
 {digitalWrite(i,HIGH);
 delay(50);}

 for (int i=9;i>=2;i--)
 {digitalWrite(i,LOW);
 delay(50);}
}
//------------------------------------------------------------------------------------------------------------------------------------------------------------
void f2()
{
 for (int i=9;i>=2;i--)
 {digitalWrite(i,HIGH);
 delay(50);}

 for (int i=2;i<=9;i++)
 {digitalWrite(i,LOW);
 delay(50);}
}
//------------------------------------------------------------------------------------------------------------------------------------------------------------
void f3()
{
 for (int i=2;i<=9;i+=2)
 {digitalWrite(i,HIGH);
 delay(50);}
 for (int i=2;i<=9;i+=1)
 {digitalWrite(i,HIGH);
 delay(50);}
}
//------------------------------------------------------------------------------------------------------------------------------------------------------------
void f4()
{
 for (int i=2;i<=9;i++)
 {digitalWrite(i,HIGH);
 delay(50);
 digitalWrite(i,LOW);
 delay(50);}

 for (int i=9;i>=2;i--)
 {digitalWrite(i,HIGH);
 delay(50);
 digitalWrite(i,LOW);
 delay(50);}
}