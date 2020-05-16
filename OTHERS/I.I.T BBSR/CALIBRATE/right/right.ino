int lPin1 = 2;
int lPin2 = 4;
int rPin1 = 7;
int rPin2 = 8;
void setup()
{
 
 pinMode(2,OUTPUT); //Left Motor Pin 1
 pinMode(4,OUTPUT); //Left Motor Pin 2
 pinMode(7,OUTPUT); //Right Motor Pin 1
 pinMode(8,OUTPUT);  //Right Motor Pin 2
 pinMode(9,OUTPUT);  //Left PWM pin
 pinMode(10,OUTPUT);  //Right PWM pin
 Serial.begin(9600); //Enable Serial Communications

}

void loop()
{
  right();
  halt();
  delay(3000);
}

void right()
{
  digitalWrite(2,HIGH);
  digitalWrite(4,LOW);
  digitalWrite(7,LOW);
  digitalWrite(8,HIGH);
  analogWrite(9,150);
  analogWrite(10,150);
  delay(400);
  digitalWrite(2,LOW);
  digitalWrite(4,HIGH);
  digitalWrite(7,LOW);
  digitalWrite(8,HIGH);
  analogWrite(9,150);
  analogWrite(10,150);
  delay(400);
}

void halt()
{
  digitalWrite(2,LOW);
  digitalWrite(4,LOW);
  digitalWrite(7,LOW);
  digitalWrite(8,LOW);
}


