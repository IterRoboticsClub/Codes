
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
 
 
 
#include "dtmf.h"
 
DTMF dtmf; 
 
void setup()
{
 Serial.begin(9600);

}
 
void loop()
{
 
  // Play a default number with all possibilities
  //dtmf.playDTMF();
   
  // Read DTMF codes one by one and print it on Serial
  int myDtmf;
  myDtmf = dtmf.getDTMF();
  if(myDtmf != -1) 
  Serial.println(myDtmf);
  delay(80); // to avoid getting repeated output.
  
}
