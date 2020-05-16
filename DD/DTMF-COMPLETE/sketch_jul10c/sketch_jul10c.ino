
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
int p=250,val=0; 
void setup()
{
 Serial.begin(9600);
 pinMode(40,OUTPUT);
 pinMode(41,OUTPUT);
 pinMode(42,OUTPUT);
 pinMode(43,OUTPUT);
 pinMode(3,OUTPUT);
 pinMode(4,OUTPUT);
}
 
void loop()
{
 val=read_value();
// Serial.print("NOT ");
 Serial.println(val);
if(val==2)
 {
   straight();
 }
 else if(val==4)
 {
   left();
 }
 else if(val==6)
 {
   right();
 }
 else if(val==8)
 {
   back();
 }
 else if(val==5)
 {
   stand();
 }
 else
   stand();
}

void straight()
{
digitalWrite(40,HIGH);
digitalWrite(41,LOW);
digitalWrite(42,HIGH);
digitalWrite(43,LOW);
analogWrite(3,p);
analogWrite(4,p);
Serial.println("Straight");
delay(200);
}

void left()
{
digitalWrite(40,LOW);
digitalWrite(41,HIGH);
digitalWrite(42,HIGH);
digitalWrite(43,LOW);
analogWrite(3,p);
analogWrite(4,p);
Serial.println("Left");
delay(200);
}

void right()
{
digitalWrite(40,HIGH);
digitalWrite(41,LOW);
digitalWrite(42,LOW);
digitalWrite(43,HIGH);
analogWrite(3,p);
analogWrite(4,p);
Serial.println("Right");
delay(200); 
}

void back()
{
  digitalWrite(40,LOW);
digitalWrite(41,HIGH);
digitalWrite(42,LOW);
digitalWrite(43,HIGH);
analogWrite(3,p);
analogWrite(4,p);
Serial.println("Back");
delay(200);
}

void stand()
{
digitalWrite(40,LOW);
digitalWrite(41,LOW);
digitalWrite(42,LOW);
digitalWrite(43,LOW);
Serial.println("Stand");
delay(200);  
}
  int read_value()
  {
  // Play a default number with all possibilities
  //dtmf.playDTMF();
   
  // Read DTMF codes one by one and print it on Serial
  int myDtmf;
  myDtmf = dtmf.getDTMF();
 while(myDtmf == -1)
 {
  myDtmf = dtmf.getDTMF();
  Serial.println("while loop ");
 } 
  //delay(80); // to avoid getting repeated output.
  return myDtmf;
}
