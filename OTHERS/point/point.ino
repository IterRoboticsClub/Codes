#include <ArduinoRobot.h>

void setup(){
  Robot.begin();
  Robot.pointTo(90); //The robot will turn to 90, by the value of compass
}
void loop(){
}
