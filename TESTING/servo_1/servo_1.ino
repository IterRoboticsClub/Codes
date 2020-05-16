/*
  Servo Test Code
  Bascially user inputs no. between 0-180 from the serial monitor
  Arduino turns the servo to that position
*/
#include <Servo.h> 
Servo myservo;  // create servo object to control a servo 
void setup() 
{ 
  // Begin Serial library
  Serial.begin(9600);
  // attaches the servo on pin 6 to the servo object 
  myservo.attach(9);  
} 
void loop() 
{ 
  // Whenever there is some data input from serial monitor, i.e whenever user enters a number(position)
  // command arduino to move to the postion 
  if(Serial.available()) 
  {
    // Move the servo to the postion as specified by user
    myservo.write(Serial.parseInt());
    // wait for some time
    delay(1000);
  }
    else 
    {myservo.write(88);}  
} 
