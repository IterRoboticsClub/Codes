
/*
  DTMF.cpp - Example code for DTMF library
  Pin Diagram
 
DTMF     Arduino
Q1   12
Q2   11
Q3   10
Q4   9
STD  8
SPK1     2
SPK2     3
 
*/
 
 
#include<dtmf.h>
 
DTMF dtmf; 
int val=0;
void setup()
{
 Serial.begin(9600);
 pinMode(2,OUTPUT);
 pinMode(3,OUTPUT);
 pinMode(4,OUTPUT);
 pinMode(5,OUTPUT);
 pinMode(6,OUTPUT);
 pinMode(7,OUTPUT);
 pinMode(A0,OUTPUT);
 pinMode(13,OUTPUT);
}
 
void loop()
{
 val=read_value();
 Serial.println(val);

  if(val==0)
  {
    digitalWrite(2,LOW);
    digitalWrite(3,LOW);
    digitalWrite(4,LOW);
    digitalWrite(5,LOW);
    digitalWrite(6,LOW);
    digitalWrite(7,LOW);
    digitalWrite(A0,LOW);
    digitalWrite(13,LOW);
    Serial.println("I m in 0");
    delay(2000);
   }
  
  else if(val==1)
  {
    digitalWrite(2,HIGH);
    digitalWrite(3,LOW);
    digitalWrite(4,LOW);
    digitalWrite(5,LOW);
    digitalWrite(6,LOW);
    digitalWrite(7,LOW);
    digitalWrite(A0,LOW);
    digitalWrite(13,LOW);
    Serial.println("I m in 1");
    delay(2000);
  }

 else if(val==2)
 {
    digitalWrite(2,LOW);
    digitalWrite(3,LOW);
    digitalWrite(4,LOW);
    digitalWrite(5,HIGH);
     digitalWrite(6,LOW);
    digitalWrite(7,LOW);
    digitalWrite(A0,LOW);
    digitalWrite(13,LOW);
    Serial.println("I m in 2");
    delay(2000); 
 }
 
 else if(val==3)
 {
    digitalWrite(2,HIGH);
    digitalWrite(3,LOW);
    digitalWrite(4,LOW);
    digitalWrite(5,HIGH);
     digitalWrite(6,LOW);
    digitalWrite(7,LOW);
    digitalWrite(A0,LOW);
    digitalWrite(13,LOW);
    Serial.println("I m in 3");
delay(2000);
 }
 
 else if(val==4)
 {
    digitalWrite(2,LOW);
    digitalWrite(3,LOW);
    digitalWrite(4,LOW);
    digitalWrite(5,LOW);
    digitalWrite(6,LOW);
    digitalWrite(7,HIGH);
    digitalWrite(A0,LOW);
    digitalWrite(13,LOW); 
    Serial.println("I m in 4");
 delay(2000);
 }
 
  else if(val==5)
 {
    digitalWrite(2,HIGH);
    digitalWrite(3,LOW);
    digitalWrite(4,LOW);
    digitalWrite(5,LOW); 
     digitalWrite(6,LOW);
    digitalWrite(7,HIGH);
    digitalWrite(A0,LOW);
    digitalWrite(13,LOW);
    Serial.println("I m in 5");
 delay(2000);
 }
 
 else if(val==6)
 {
   digitalWrite(2,LOW);
    digitalWrite(3,LOW);
    digitalWrite(4,LOW);
    digitalWrite(5,HIGH);
    digitalWrite(6,LOW);
    digitalWrite(7,HIGH);
    digitalWrite(A0,LOW);
    digitalWrite(13,LOW); 
    Serial.println("I m in 6");
 delay(2000);
 }
 
 else if(val==7)
 {
     digitalWrite(2,HIGH);
    digitalWrite(3,LOW);
    digitalWrite(4,LOW);
    digitalWrite(5,HIGH);
    digitalWrite(6,LOW);
    digitalWrite(7,HIGH);
    digitalWrite(13,LOW);
    digitalWrite(A0,LOW); 
    Serial.println("I m in 7");
 delay(2000);
 } 
 else if(val==8)
 
 {
   digitalWrite(2,LOW);
    digitalWrite(3,LOW);
    digitalWrite(4,LOW);
    digitalWrite(5,LOW);
     digitalWrite(6,LOW);
    digitalWrite(7,LOW);
    digitalWrite(A0,HIGH);
    digitalWrite(13,LOW);
    Serial.println("I m in 8");
 delay(2000);
 }
 else if(val==9)
 {
   digitalWrite(2,HIGH);
    digitalWrite(3,LOW);
    digitalWrite(4,LOW);
    digitalWrite(5,LOW);
     digitalWrite(6,LOW);
    digitalWrite(7,LOW);
    digitalWrite(A0,HIGH);
    digitalWrite(13,LOW);
    Serial.println("I m in 9");
 delay(2000);
 }
 else
   {
     digitalWrite(2,HIGH);
    digitalWrite(3,LOW);
    digitalWrite(4,LOW);
    digitalWrite(5,HIGH);
     digitalWrite(6,LOW);
    digitalWrite(7,HIGH);
    digitalWrite(A0,HIGH);
    digitalWrite(13,LOW);
    Serial.println("I m in else");
    delay(500);
}
}
/*
void straight()
{
digitalWrite(2,HIGH);
digitalWrite(4,LOW);
digitalWrite(7,HIGH);
digitalWrite(13,LOW);
analogWrite(5,175);
analogWrite(6,175);
Serial.println("Straight");
//delay(5000);
}

void left()
{
digitalWrite(2,LOW);
digitalWrite(4,HIGH);
digitalWrite(7,HIGH);
digitalWrite(13,LOW);
analogWrite(5,150);
analogWrite(6,150);
Serial.println("Left");
//delay(470);
}

void right()
{
 digitalWrite(2,HIGH);
digitalWrite(4,LOW);
digitalWrite(7,LOW);
digitalWrite(13,HIGH);
analogWrite(5,140);
analogWrite(6,140);
Serial.println("Right");
//delay(470); 
}

void back()
{
  digitalWrite(2,LOW);
digitalWrite(4,HIGH);
digitalWrite(7,LOW);
digitalWrite(13,HIGH);
analogWrite(5,180);
analogWrite(6,180);
Serial.println("Back");
//delay(2000);
}

void stand()
{
digitalWrite(2,LOW);
digitalWrite(4,LOW);
digitalWrite(7,LOW);
digitalWrite(13,LOW);
Serial.println("Stand");
//delay(2000);  
}
*/
  int read_value()
  {
  // Play a default number with all possibilities
  //dtmf.playDTMF();
   int myDtmf;
  // Read DTMF codes one by one and print it on Serial
  myDtmf = dtmf.getDTMF();  //By default value is -1
 while(myDtmf == -1 )
 {
  myDtmf = dtmf.getDTMF();
  Serial.println("while loop ");
 }
  delay(80); // to avoid getting repeated output.
  return myDtmf;
}
