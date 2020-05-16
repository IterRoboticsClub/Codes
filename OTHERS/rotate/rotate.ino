#include <ArduinoRobot.h>
#include<Wire.h>
void setup(){
  Serial.begin(9600);
  Robot.begin();
}
void loop(){
  Robot.turn(90); //Make the robot turn 90 degrees right
  delay(1000);
}
