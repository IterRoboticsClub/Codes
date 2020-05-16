/*
  JoystickLCD by Dominion-Network
  Outputs the direction of the thumb stick to the LCD Screen
 
  This example code is in the public domain.
*/
//Include the LCD Library.
#include <LiquidCrystal.h>
//Declare the LCD object and define pins.
/*
LCD Connection Guide.
LCDPIN          ArduinoPIN
  1               GND
  2               +5V
  3               GND
  4               DigPin12
  5               GND
  6               DigPin11
  7               Not Used
  8               Not Used
  9               Not Used
  10              Not Used
  11              DigPin10
  12              DigPin9
  13              DigPin8
  14              DigPin7
*/

LiquidCrystal lcd(12,11,10,9,8,7);

void setup() {
//Start the LCD object.
lcd.begin(16, 2);
//Start with a clear LCD screen.
lcd.clear();
}

void loop() {
lcd.setCursor(0, 0);
if(analogRead(0) == 513){
lcd.print("STOPPED");
} else if(analogRead(0) < 513) {
lcd.print("REVERSE");
} else if(analogRead(0) > 513) {
lcd.print("FORWARD");
} 
lcd.setCursor(0, 1);
if(analogRead(1) == 513){
lcd.print("STOPPED");
} else if(analogRead(1) < 513) {
lcd.print("LEFT ");
} else if(analogRead(1) > 513) {
lcd.print("RIGHT");
} 
}

