/* 3.3V accelerometer self test
 analog 1: z-axis
 analog 2: y-axis
 analog 3: x-axis
 
 5V : VCC
 Gnd: GND
*/

#include<LiquidCrystal.h>

LiquidCrystal lcd(12,11,A2,A3,A4,A5);

int contr_pin=9;

const int xpin = A0;                  // x-axis of the accelerometer
const int ypin = A1;                  // y-axis
int X=0,Y=0,Z=0,speed1=75,speed2=75; 

void setup()
{
  lcd.begin(16,2);
  analogWrite(contr_pin,10);
  Serial.begin(9600);
  pinMode(2,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(A0,INPUT);
  pinMode(A1,INPUT);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("X= ");
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
  
  //Ref X=220 AND Y=240 -> This was when the sensor was kept in its mean position.
  
  if((Y>220)&&(Y<255))
  {
    if(X>255)
    {
      left();
    }                                    //For left and right tilt do notice that Y used to vary slightly between 230 to 250 dats y in outer if the conditon is 220<Y<255
    else if(X<220)                       //The major change was seen in X axis as X used to change upto 280/290 from reference value of 220 on left tilt  
    {                                     //And similarly for right tilt X used to change to 180/170 from reference value of 220.
      right();
    }
    
    else 
    {
      halt();
      
    }
  }
  
  else if((X>220)&&(X<255))                  // Now same applies for Forward and backward 
  {                                          //Here X doesnt chages too much 
    if(Y>255)
    {
      fwd();                                  //The major change is seen in Y axis as y changes upto 280/290 from reference value of 220 on Forward tilt of the sensor      
    }
    
    else if(Y<220)
    {
      
      back();                                  //And similarly for back tilt Y changeS to 180/170 from reference value of 220.
    }
    
    else
    {
      halt();
   }
  }
  delay(100);
}

void fwd()
{
 Serial.println("I m in Forward");
 lcd.clear();
  lcd.setCursor(0,0);           //-------------------------------------------------------------------------------------------------------------
  lcd.print("X= ");             //
  lcd.setCursor(0,7);           //
  lcd.print("Y= ");             //These codes are for displaying on LCD Module and are in right left turn fucntions and fwd and back functions.
  lcd.setCursor(1,0);           //
  lcd.print("Moving Forward");  //--------------------------------------------------------------------------------------------------------------

 digitalWrite(2,HIGH);
 digitalWrite(4,LOW);
 digitalWrite(7,HIGH);
 digitalWrite(8,LOW);
 analogWrite(9,speed1);
 analogWrite(10,speed2);
 delay(1000);
}

void back()
{
 Serial.println("I m in back");
 lcd.setCursor(0,0);
  lcd.print("X= ");
  lcd.setCursor(0,7);
  lcd.print("Y= ");
  lcd.setCursor(1,0);
  lcd.print("Moving Backward");
  
 digitalWrite(2,LOW);
 digitalWrite(4,HIGH);
 digitalWrite(7,LOW);
 digitalWrite(8,HIGH);
 analogWrite(9,speed1);
 analogWrite(10,speed2);
 delay(1000);
}

void right()
{
 Serial.println("I m in right");
 lcd.setCursor(0,0);
  lcd.print("X= ");
  lcd.setCursor(0,7);
  lcd.print("Y= ");
  lcd.setCursor(1,0);
  lcd.print("Turning Right");
 digitalWrite(2,HIGH);
 digitalWrite(4,LOW);
 digitalWrite(7,LOW);
 digitalWrite(8,HIGH);
 analogWrite(9,75);
 analogWrite(10,75);
 delay(1000);
}

void left()
{
  
 Serial.println("I m in left");
 lcd.setCursor(0,0);
  lcd.print("X= ");
  lcd.setCursor(0,7);
  lcd.print("Y= ");
  lcd.setCursor(1,0);
  lcd.print("Turning Left");
 digitalWrite(2,LOW);
 digitalWrite(4,HIGH);
 digitalWrite(7,HIGH);
 digitalWrite(8,LOW);
 analogWrite(9,75);
 analogWrite(10,75);
 delay(1000);
}

void halt()
{
  Serial.println("I m in Halt");
 digitalWrite(2,LOW);
 digitalWrite(4,LOW);
 digitalWrite(4,LOW);
 digitalWrite(8,LOW);
 analogWrite(9,0);
 analogWrite(10,0);
 delay(100);
}
  
