
int e1 = 6;
int e2 = 5;

int in1 = 7;
int in2 = 8;
int in3 = 4;
int in4 = 3;
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
void loop() {
  digitalWrite(in1,1);
  digitalWrite(in2,0);
  digitalWrite(in3,0);
  digitalWrite(in4,1);
  digitalWrite(e1,1);
  digitalWrite(e2,1);
  delay(5000);
  
  digitalWrite(in1,0);
  digitalWrite(in2,1);
  digitalWrite(in3,1);
  digitalWrite(in4,0);
  digitalWrite(e1,1);
  digitalWrite(e2,1);
  delay(5000);
  
  digitalWrite(in1,1);
  digitalWrite(in2,0);
  digitalWrite(in3,1);
  digitalWrite(in4,0);
  digitalWrite(e1,1);
  digitalWrite(e2,1);
  delay(5000);
  
  digitalWrite(in1,0);
  digitalWrite(in2,1);
  digitalWrite(in3,0 );
  digitalWrite(in4,1);
  digitalWrite(e1,1);
  digitalWrite(e2,1);
  delay(5000);
    
}
