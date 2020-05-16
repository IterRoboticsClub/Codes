#include<Servo.h>
Servo servoMain; // Define our Servo

void setup()
{
   servoMain.attach(9); // servo on digital pin 10
   servoMain.write(90);   
}

void loop()
{
   servoMain.write(0);
   delay(1000);
   servoMain.write(160);
   delay(500);
}
