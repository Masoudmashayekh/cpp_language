//****************************************************** Voltage Sensor (Panel 1) **************************************************************************************
int analogInput1 = A1; 
float vout1 = 0.0; 
float Vin1 = 0.0; 
float R1 = 30000.0; //   
float R2 = 7500.0; //  
int value1 = 0; 
//****************************************************** Voltage Sensor (Panel 2) **************************************************************************************
//int analogInput2 = A0; 
//float vout2 = 0.0; 
//float Vin2 = 0.0; 
//float R3 = 30000.0; //   
//float R4 = 7500.0; //  
//int value2 = 0; 

//--------------------------------------------------- void setup ------------------------------------------------------------------------------------------
void setup(void)
{
  pinMode(analogInput1, INPUT); 
  //pinMode(analogInput2, INPUT); 
  Serial.begin(9600);    // Start serial communication for debugging purposes                                        
  
}
//---------------------------------------------------- void loop --------------------------------------------------------------------------------------------
void loop(void)
 {   
  
 ////////////////////////////////////////////////////////////  Panel 1 & 2  //////////////////////////////////////////////////////////////////////////////  
  value1 = analogRead(analogInput1); 
  vout1 = (value1 * 5.0) / 1024.0; // see text 
  Vin1 = vout1 / (R2/(R1+R2));  

  Serial.print("Voltage(P1): ");
  Serial.print(Vin1);
  Serial.print(" V");
  Serial.print(" , ");
  
  //value2 = analogRead(analogInput2); 
  //vout2 = (value2 * 5.0) / 1024.0; // see text 
  //Vin2 = vout2 / (R4/(R3+R4)); 
  //float Vinall = Vin2 + Vin1;

  //Serial.print("Voltage(P2): ");
  //Serial.print(Vin2); 
  //Serial.print(" V");
  //Serial.print(" , ");

  //Serial.print("Voltage(all): ");
  //Serial.print(Vinall);
  //Serial.println(" V");
  
  ///////////////////////////////////////////////////////////////// Current sensor //////////////////////////////////////////////////////////////////////////////
 unsigned int x=0;
 float AcsValue=0.0,Samples=0.0,AvgAcs=0.0,AcsValueF=0.0;

  for (int x = 0; x < 150; x++){ //Get 150 samples
  AcsValue = analogRead(A0);     //Read current sensor values   
  Samples = Samples + AcsValue;  //Add samples together
  delay (3); // let ADC settle before next sample 3ms
 }
 AvgAcs=Samples/150.0;//Taking Average of Samples

 //((AvgAcs * (5.0 / 1024.0)) is converitng the read voltage in 0-5 volts
 //2.5 is offset(I assumed that arduino is working on 5v so the viout at no current comes
 //out to be 2.5 which is out offset. If your arduino is working on different voltage than 
 //you must change the offset according to the input voltage)
 //0.100v(100mV) is rise in output voltage when 1A current flows at input
 AcsValueF = ((2.5 - (AvgAcs * (5.0 / 1024.0)) )/0.100) + 0.35;


  Serial.print("Current: ");
  Serial.print(AcsValueF);
  Serial.print(" A");
  Serial.print(" , ");

  float P = AcsValueF * Vin1;
  Serial.print("Power: ");
  Serial.print(P);
  Serial.print(" W");
  Serial.println(" , ");

  delay(100);

}
