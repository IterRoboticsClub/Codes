int surface[7]={0, 0, 0, 0, 0, 0, 0};

void setup()
{
  // put your setup code here, to run once:
Serial.begin(9600);
}

void loop() 
{
  // put your main code here, to run repeatedly
  surface[0]=analogRead(A0);
  surface[1]=analogRead(A1);
  surface[2]=analogRead(A2);
  surface[3]=analogRead(A3);
  surface[4]=analogRead(A4);
  surface[5]=analogRead(A5);
  surface[6]=analogRead(7);
  //surface[1]=digitalRead(6);
  //surface[2]=digitalRead(3);
  Serial.print("\nS1 = ");
  Serial.print(surface[0]);
  Serial.print("\nS2 = ");
  Serial.print(surface[1]);
  Serial.print("\nS3 = ");
  Serial.print(surface[2]);
  Serial.print("\nS4 = ");
  Serial.print(surface[3]);
  Serial.print("\nS5 = ");
  Serial.print(surface[4]);
  Serial.print("\nS6 = ");
  Serial.print(surface[5]);
  Serial.print("\nS7 = ");
  Serial.print(surface[6]);
  /*Serial.print("\nS2 = ");
  Serial.print(surface[1]);
  Serial.print("\nS3 = ");
  Serial.print(surface[2]);*/
  delay(3000);
}
