#include<Servo.h>
Servo servoMain; // Define our Servo

void setup()
{
   servoMain.attach(9); // servo on digital pin 10
}

void loop()
{
   servoMain.write(87);  // Turn Servo Left to 45 degrees
   delay(1000);          // Wait 1 second
   servoMain.write(85);   // CLOCKWISE
   delay(1840);          // Wait 1 second
   servoMain.write(87);
   delay(1000);
   servoMain.write(89);  // ANTI-CLOCKWISE
   delay(2020);          // Wait 1 second
   servoMain.write(87);
   delay(1000);  
   servoMain.write(89);  //ANTI-CLOCKWISE
   delay(2020);
   servoMain.write(87);
   delay(1000);
   servoMain.write(85);  //CLOCKWISE
   delay(1840);
}
