/*
 * IRremote: IRrecvDemo - demonstrates receiving IR codes with IRrecv
 * An IR detector/demodulator must be connected to the input RECV_PIN.
 * Version 0.1 July, 2009
 * Copyright 2009 Ken Shirriff
 * http://arcfn.com
 GND=left
 MIDDLE=Vcc
 RIGHT=Out
 */

#include <IRremote.h>

int RECV_PIN = 11;
int cmd=0;
IRrecv irrecv(RECV_PIN);

decode_results results;

void setup()
{
  pinMode(11,INPUT);
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
}

void loop() {
  Serial.print("I m Here");
  if (irrecv.decode(&results)) {
    cmd=results.value;
    //Serial.print("Im Here");
    Serial.print(results.value);
    //Serial.print("I m over");
    
  }
 /* if(cmd== -21166)      //FOR STRAIGHT
  {
    digitalWrite(2,HIGH);
    digitalWrite(4,LOW);
    digitalWrite(7,LOW);
    digitalWrite(8,HIGH);
    analogWrite(9,150);
    analogWrite(10,150);
    Serial.println("GO STRAIGHT");
    delay(100);
  }
  
  else if(cmd == '1D52')    //FOR LEFT
  {
    digitalWrite(2,LOW);
    digitalWrite(4,HIGH);
    digitalWrite(7,LOW);
    digitalWrite(8,HIGH);
    analogWrite(9,150);
    analogWrite(10,150);
    Serial.println("GO LEFT");
    delay(100);
    
  }
  
  
   else if(cmd== 'FFFFEF76')    //FOR RIGHT
  {
    digitalWrite(2,HIGH);
    digitalWrite(4,LOW);
    digitalWrite(7,HIGH);
    digitalWrite(8,LOW);
    analogWrite(9,150);
    analogWrite(10,150);
    Serial.println("GO RIGHT");
    delay(100);
    
  }
  
   else if(cmd== 'FFFF9BCE')    //FOR BACK
  {
    digitalWrite(2,LOW);
    digitalWrite(4,HIGH);
    digitalWrite(7,HIGH);
    digitalWrite(8,LOW);
    analogWrite(9,150);
    analogWrite(10,150);
    Serial.println("GO BACK");
    delay(100);
    
  }
  
   else if(cmd== '2E76')   //FOR STOP
  {
    digitalWrite(2,LOW);
    digitalWrite(4,LOW);
    digitalWrite(7,LOW);
    digitalWrite(8,LOW);
    Serial.println("FOR STOP");
    delay(100);
    
  }
  
  else    //FOR STOP
  {
    digitalWrite(2,LOW);
    digitalWrite(4,LOW);
    digitalWrite(7,LOW);
    digitalWrite(8,LOW);
    Serial.println(" STOPPED");
    delay(100);
    
  }*/
  
  irrecv.resume(); // Receive the next value
  
}
