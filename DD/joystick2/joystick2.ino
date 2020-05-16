/*
  JoystickLCD by Dominion-Network
  Outputs the direction of the thumb stick to the LCD Screen
 
  This example code is in the public domain.
*/
//Include the LCD Library.
#include <LiquidCrystal.h>
int val1;
int val2;
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
/* JOYSTICK CONNECTIONS
   
   Leftmost is 5V
   Middlemost is analog
   Rightmost is GND

*/
LiquidCrystal lcd(12,11,10,9,8,7);

void setup() {
//Start the LCD object.
Serial.begin(9600);
lcd.begin(16, 2);
//Start with a clear LCD screen.
lcd.clear();
}

void loop()
{ 
  val1=analogRead(0);
  val2=analogRead(1);
  Serial.println(val1);
  Serial.println(val2);
  delay(1000);
  
}
/*lcd.setCursor(0, 0);
if(analogRead(0) == 506)
{
Serial.println("STOPPED");
delay(2000);
}
else if(analogRead(0) < 506) 
{
Serial.println("REVERSE");
Serial.println(analogRead(0));
delay(2000);
} 
else if(analogRead(0) > 506) 
{
Serial.println("FORWARD");
Serial.println(analogRead(0));
delay(2000);
} 
//lcd.setCursor(0, 1);
else if(analogRead(1) == 513)
{
Serial.println("STOPPED");
Serial.println(analogRead(1));
delay(2000);
}
 else if(analogRead(1) < 513) 
{
Serial.println("LEFT ");
Serial.println(analogRead(1));
delay(2000);
} 
else if(analogRead(1) > 513) 
{
Serial.println("RIGHT");
Serial.println(analogRead(1));
delay(2000);
} 
}

/*int read_motion()
{
  int val;
  val=analogRead(0);
  retur*/
