#include<LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);  // sets the interfacing pins
int
contr_pin=9;
void setup()
{
 lcd.begin(16, 2);  // initializes the 16x2 LCD
 analogWrite(contr_pin,10);
}

void loop()
{
  
  lcd.setCursor(0,0);           //sets the cursor at row 0 column 0
  lcd.print("16x2 LCD MODULE"); // prints 16x2 LCD MODULE
  lcd.setCursor(2,1);           //sets the cursor at row 1 column 2
  lcd.print("HELLO WORLD");     // prints HELLO WORLD
}
