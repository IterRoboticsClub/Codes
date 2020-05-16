#include<Servo.h>

Servo myservo;

#define trigpin 13
#define echopin 12

int F=200;

void setup()
{

 Serial.begin(9600);  
  pinMode(trigpin,OUTPUT);
  pinMode(echopin,INPUT);
  pinMode(2,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  
 myservo.attach(3);
  myservo.write(90);
}

void loop() 
{
  float d,nR,nL;
  d=ping();
    
  if(d>=10)
    {
      Serial.println("I will go forward");
  digitalWrite(2,HIGH);
  digitalWrite(4,LOW);
  Serial.println("I m in btwn");
  digitalWrite(7,LOW);
  digitalWrite(8,HIGH);
  analogWrite(9,200);
  analogWrite(10,200);
  delay(5000);
    }

  else if(d<10)
    {
      halt();
      right_screen();
      nR=ping();
      right_return();
      //myservo.write(90);
      delay(1000);
      left_screen();
      nL=ping();
      left_return();
      //myservo.write(90);
      
      if(nR>nL)
      {
        right();
      }
      
      else if(nR<nL)
      {
        left();
      }
//      
//      else if((nR<10)&&(nL<10))
//      {
//        back();
//        right();
//        halt();
//      }  
  }
    
  else 
 {
  Serial.println("I will go forward");
  digitalWrite(2,HIGH);
  digitalWrite(4,LOW);
  digitalWrite(7,LOW);
  digitalWrite(8,HIGH);
  analogWrite(9,200);
  analogWrite(10,200);
  delay(5000);
 }  
}

int ping()
{
  float duration,distance;
  digitalWrite(trigpin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigpin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigpin,LOW);
  duration=pulseIn(echopin,HIGH);
  distance=duration/29/2;
  Serial.println("\nDISTANCE = ");
  Serial.print(distance);
  Serial.println(" \nDURATION = ");
  Serial.print(duration);
  return distance;
}

void forward()
{
  Serial.println("I will go forward");
  digitalWrite(2,HIGH);
  digitalWrite(4,LOW);
  digitalWrite(7,LOW);
  digitalWrite(8,HIGH);
  analogWrite(9,200);
  analogWrite(10,200);
  delay(5000);
}

void right()
{
  Serial.println("I will go right");
  digitalWrite(2,HIGH);
  digitalWrite(4,LOW);
  digitalWrite(7,HIGH);
  digitalWrite(8,LOW);
  analogWrite(9,F);
  analogWrite(10,F);
  delay(5000);
}

void halt()
{
  Serial.println("I will stop");
  digitalWrite(2,LOW);
  digitalWrite(4,LOW);
  digitalWrite(7,LOW);
  digitalWrite(8,LOW);
}

void back()
{
  Serial.println("I will go back");
  digitalWrite(2,LOW);
  digitalWrite(4,HIGH);
  digitalWrite(7,HIGH);
  digitalWrite(8,LOW);
  analogWrite(9,F);
  analogWrite(10,F);
  delay(5000);
}

void left()
{
  Serial.println("I will go left");
   digitalWrite(2,LOW);
   digitalWrite(4,HIGH);
   digitalWrite(7,LOW);
   digitalWrite(8,HIGH);
   analogWrite(9,F);
   analogWrite(10,F);
   delay(5000);
}

void right_screen()
{
  int pos;
   for(pos = 90; pos >= 15; pos -= 1) // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    myservo.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(25);                       // waits 15ms for the servo to reach the position 
  } 
}
void right_return()
{
  int pos;
  for(pos=15;pos<=90;pos+=1)
  {
    myservo.write(pos);
    delay(25);
  }
}

//  for(pos = 15; pos<=90; pos+=1)     // goes from 180 degrees to 0 degrees 
//  {                                
//    myservo.write(pos);              // tell servo to go to position in variable 'pos' 
//    delay(25);                       // waits 15ms for the servo to reach the position 
//  } 


void left_screen()
{ 
  int pos;
  for(pos = 90; pos <= 180; pos += 1) // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    myservo.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(25);                       // waits 15ms for the servo to reach the position 
  } 
}
void left_return()
{
  int pos;
  for(pos=180; pos >= 90; pos-=1)
  {
    myservo.write(pos);
    delay(25);
  }
}
//  for(pos=180; pos>90; pos -=1)
//  {
//  myservo.write(pos);
//  delay(25);
//  }

