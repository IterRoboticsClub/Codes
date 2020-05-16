
int e1 = 9;
int e2 = 10;

int in1 = 7;
int in2 = 8;
int in3 = 4;
int in4 = 2;
int sensors[]={0,0,0};
// the setup routine runs once when you press reset:
void setup() {
  // initialize the digital pin as an output.
  pinMode(e1, OUTPUT);
  pinMode(e2, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  //digitalWrite(e1,1);
  //digitalWrite(e2,1);
 
}

// the loop routine runs over and over again forever:
void loop()
{
  follow();
   
}
void follow()
{
  for (int i = 0; i < 3; i++)
    sensors[i] = analogRead(i);
  if((sensors[0]>200) && (sensors[1]<200) && (sensors[2]>200))
  {
  digitalWrite(in1,1);
  digitalWrite(in2,0);
  digitalWrite(in3,0);
  digitalWrite(in4,1);
  analogWrite(e1,255);
  analogWrite(e2,255);
  }
  
  
  else if((sensors[0]<200) && (sensors[1]>200) && (sensors[2]>200))
  {
  digitalWrite(in1,1);
  digitalWrite(in2,0);
  digitalWrite(in3,0);
  digitalWrite(in4,0);
  analogWrite(e1,255);
  analogWrite(e2,255);
  }
  
  else if((sensors[0]>200) && (sensors[1]>200) && (sensors[2]<200))
  {
  digitalWrite(in1,0);
  digitalWrite(in2,0);
  digitalWrite(in3,0);
  digitalWrite(in4,1);
analogWrite(e1,255);
  analogWrite(e2,255);
  }
  
  else
  {
    digitalWrite(in1,1);
  digitalWrite(in2,0);
  digitalWrite(in3,0);
  digitalWrite(in4,1);
  analogWrite(e1,255);
  analogWrite(e2,25);
  }
}
