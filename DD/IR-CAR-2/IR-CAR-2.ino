/*
 * Sketch modified by Enjoying Electronics: http://www.instructables.com/member/Enjoying+Electronics/
 Code based off of: 
 * IRremote
 * Version 0.1 July, 2009 
 * Copyright 2009 Ken Shirriff
 * For details, see http://arcfn.com/2009/08/multi-protocol-infrared-remote-library.html
 
 * Special thanks to dablondeemu http://www.instructables.com/member/dablondeemu/
 * and his instructable listed below, IR Remote Controlled Color Changing Cloud (Arduino) 
 * http://www.instructables.com/id/IR-Remote-Controlled-Color-Changing-Cloud-Arduino/  
 
 
 * Lets get started:
 
 The IR sensor's pins are attached to Arduino as so:(FROM RIGHT TO LEFT)
 Pin 1 to Vout (pin 11 on Arduino)
 Pin 2 to GND
 Pin 3 to Vcc (+5v from Arduino)

*/

/*******************CODE BEGINS HERE********************/

#include <IRremote.h>


int IRpin = 11;
IRrecv irrecv(IRpin);
decode_results results;

void setup()
{
  Serial.begin(9600);
  pinMode(2,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  irrecv.enableIRIn(); // Start the receiver
}

void loop() 
{
  if (irrecv.decode(&results)) 
    {
      Serial.println(results.value, DEC); // Print the Serial 'results.value'
      delay(100);
      if(results.value == 116567378)
      {
      Serial.println("GO STRT");
      digitalWrite(2,HIGH);
      digitalWrite(4,LOW);
      digitalWrite(7,LOW);
      digitalWrite(8,HIGH);
      analogWrite(9,150);
      analogWrite(10,150);
      //delay(1000);
      }
      
      else if(results.value == 1480519542)
      {
        Serial.println("Go Right");
        digitalWrite(2,HIGH);
        digitalWrite(4,LOW);
        digitalWrite(7,HIGH);
        digitalWrite(8,LOW);
        analogWrite(9,150);
        analogWrite(10,150);
        //delay(1000);
      }
      
      else if(results.value == 556637134)
      {
      Serial.println("GO BACK");
      digitalWrite(2,LOW);
      digitalWrite(4,HIGH);
      digitalWrite(7,HIGH);
      digitalWrite(8,LOW);
      analogWrite(9,150);
      analogWrite(10,150);
      delay(1000);
      }
      
      else if(results.value ==1874140498)
      {
      Serial.println("GO LEFT");
      digitalWrite(2,LOW);
      digitalWrite(4,HIGH);
      digitalWrite(7,LOW);
      digitalWrite(8,HIGH);
      analogWrite(9,150);
      analogWrite(10,150);
      delay(1000);
      }
      
      else if(results.value==1277505142)
      {
        Serial.println("STOP");
        digitalWrite(2,LOW);
        digitalWrite(4,LOW);
        digitalWrite(7,LOW);
        digitalWrite(8,LOW);
        delay(1000);
      }
      else
      {
        Serial.println("IN ELSE CONDITION");
        digitalWrite(2,LOW);
        digitalWrite(4,LOW);
        digitalWrite(7,LOW);
        digitalWrite(8,LOW);
      }
      irrecv.resume();   // Receive the next value
      delay(10);
    } 
}
