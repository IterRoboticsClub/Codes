
int e1 = 6;
int e2 = 5;

int in1 = 7;
int in2 = 8;
int in3 = 4;
int in4 = 3;
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
  digitalWrite(e1,1);
  digitalWrite(e1,1);
 
}

// the loop routine runs over and over again forever:
void loop()
{
  follow();
   
}
void follow()
{
  for (int i = 0; i < 3; i++)
    sensors[i] = digitalRead(i);
  if((sensors[0]==1) && (sensors[1]==0) && (sensors[2]==1))
  {
  digitalWrite(in1,1);
  digitalWrite(in2,0);
  digitalWrite(in3,0);
  digitalWrite(in4,1);
  digitalWrite(e1,1);
  digitalWrite(e2,1);
  }
  
  
  else if((sensors[0]==0) && (sensors[1]==1) && (sensors[2]==1))
  {
  digitalWrite(in1,1);
  digitalWrite(in2,0);
  digitalWrite(in3,0);
  digitalWrite(in4,1);
  digitalWrite(e1,1);
  digitalWrite(e2,1);
  }
  
  else if((sensors[0]==1) && (sensors[1]==1) && (sensors[2]==0))
  {
  digitalWrite(in1,1);
  digitalWrite(in2,0);
  digitalWrite(in3,0);
  digitalWrite(in4,1);
  digitalWrite(e1,1);
  digitalWrite(e2,1);
  }
  
  else
  {
    digitalWrite(in1,1);
  digitalWrite(in2,0);
  digitalWrite(in3,0);
  digitalWrite(in4,1);
  digitalWrite(e1,1);
  digitalWrite(e2,1);
  }
}
