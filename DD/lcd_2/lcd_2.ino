#include <LiquidCrystal.h>
int i=0;
int contr_pin=9;
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup()
{
 lcd.begin(16, 2); //initializes 16x2 LCD
 analogWrite(contr_pin,10);
 lcd.print("16x2 LCD MODULE JHD162A & ARDUINO-UNO"); //text to display
}

void loop()
{
  for(i=0;i<2;i++)
  {
  lcd.scrollDisplayLeft();}   //scrolls display left by two positions
  delay(800);                  //sets the speed at which display moves
}
