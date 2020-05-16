/* 3.3V accelerometer self test
 analog 1: z-axis
 analog 2: y-axis
 analog 3: x-axis
 
 5V : VCC
 Gnd: GND
*/

#include<LiquidCrystal.h>

LiquidCrystal lcd(12,11,5,4,3,2);
int contr_pin=9;

// these constants describe the pins. They won't change:
const int xpin = A1;                  // x-axis of the accelerometer
const int ypin = A2;                  // y-axis
int X=0;
int Y=0;
int Z=0;

void setup()
{
  lcd.begin(16,2);
  analogWrite(contr_pin,10);
  Serial.begin(9600);
  pinMode(8,INPUT);
  pinMode(9,INPUT);
  pinMode(10,INPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  lcd.clear();
}

void loop()
{
  X=analogRead(xpin);
  Y=analogRead(ypin);
  // print the sensor values:
\
Serial.print(X);
  // print a tab between values:
  Serial.print("\t");
  Serial.print(Y);
  // print a tab between values:
  Serial.print("\t");
  Serial.print(Z);
  Serial.println();
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("X= ");
  lcd.print(X);
  lcd.setCursor(0,1);
  lcd.print("Y= ");
  lcd.print(Y);
  
  if((Y>400)&&(Y<440))
  {
    if(X<220)
    {
      left();
    }
    else if(X>280)
    {
      right();
    }
    
    else 
    {
      halt();
      bulb();
    }
  }
  
  else if((X>245)&&(X<275))
  {
    if(Y>440)
    {
      fwd();
    }
    
    else if(Y<410)
    {
      back();
    }
    
    
    else
    {
      halt();
      bulb();
   }
  }
//  // delay before next reading:
 delay(10); 
}

void fwd()
{
 Serial.println("I m in Forward");
 digitalWrite(6,HIGH);
 digitalWrite(7,LOW);
 digitalWrite(8,LOW);
 digitalWrite(9,HIGH);
 delay(10);
}

void back()
{
 Serial.println("I m in back");
  digitalWrite(6,LOW);
 digitalWrite(7,HIGH);
 digitalWrite(8,HIGH);
 digitalWrite(9,LOW);
  delay(10);
}

void right()
{
  Serial.println("I m in right");
 digitalWrite(6,HIGH);
 digitalWrite(7,LOW);
 digitalWrite(8,HIGH);
 digitalWrite(9,LOW);
 delay(10);
}

void left()
{
  Serial.println("I m in left");
 digitalWrite(6,LOW);
 digitalWrite(7,HIGH);
 digitalWrite(8,LOW);
 digitalWrite(9,HIGH);
 delay(10);
}

void halt()
{
  Serial.println("I m in Halt");
 digitalWrite(6,LOW);
 digitalWrite(7,LOW);
 digitalWrite(8,LOW);
 digitalWrite(9,LOW);
 delay(100);
}

void bulb()
{
  Serial.println("I m in bulb");
//  for(int i=0;i<5;i++)
//  {
//  digitalWrite(13,HIGH);
//  delay(1000);
//  Serial.println("I m in LOOP");
//  digitalWrite(13,LOW);
//  delay(1000);
//  }
}
