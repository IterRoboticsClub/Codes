#include<Servo.h>

Servo myservo; //TO acces functions of header file ie Servo.h
#define trigpin 13 //We use #define to set the value of a variable as a constant
#define echopin 12

int F=80;    //For speed control
int th=10;   //Threshold distance for object detection(comes in Centimeters)

void setup()                  //For setting the intial conditions of the Arduino
{

  Serial.begin(9600);          //For enabling Serial Comunications
  pinMode(trigpin,OUTPUT);
  pinMode(echopin,INPUT);
  pinMode(2,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  
  myservo.attach(3);    //Declares servo control pin attached to pin 3 of arduino
  myservo.write(90);    //By default the postion of servo will be 90 degree
}

void loop() 
{
  float nR,nL;
  int d=0;
  d=ping();            //D stores the distance
  
  if(d>=th)         //TH= minimum distance u need    
  {                                                                                                                                                                                                                                                                                                                                                                
      forward();  
  }

  else if(d<th)
    {
      halt();
      right_screen();       //Rotates to its right side
      nR=ping();            //Calculates distance at right side 
      right_return();       //Returns to original postion
      left_screen();        //Now goes to its left side
      nL=ping();            //Calculates distance at its left side
      left_return();        //Returns to it original position
      
      if(nR>nL)
      {
        right();          //if Right path has distance with object more, then turn towards right
      }
      
      else if(nR<nL)        //if Left path has distance with object more, then turn towards left
      {
        left();
      }
}
}

int ping()                    //Function for calculating distance
{
  float duration,distance;
  digitalWrite(trigpin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigpin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigpin,LOW);
  duration=pulseIn(echopin,HIGH);
  distance=duration/29/2;
  Serial.println("\nDISTANCE = ");
  Serial.print(distance);
  Serial.println(" \nDURATION = ");
  Serial.print(duration);
  return distance;
}

void forward()
{
  digitalWrite(2,HIGH);
  digitalWrite(4,LOW);
  digitalWrite(7,LOW);
  digitalWrite(8,HIGH);
  analogWrite(5,F);                      //FOR LEFT MOTOR SPEED CONTROL USING PWM
  analogWrite(6,F);                      //FOR RIGHT MOTOR SPEED CONTROL USING PWM
  Serial.println("I m in fwd ");         //FOR DEBUGGING PURPOSES
  delay(100);
}

void right()
{
  digitalWrite(2,HIGH);
  digitalWrite(4,LOW);
  digitalWrite(7,HIGH);
  digitalWrite(8,LOW);
  analogWrite(5,F);                           //FOR LEFT MOTOR SPEED CONTROL USING PWM
  analogWrite(6,F);                           //FOR RIGHT MOTOR SPEED CONTROL USING PWM
  Serial.println("I will go RIGHT ");         //FOR DEBUGGING PURPOSES        
  delay(800);
}

void halt()
{
  digitalWrite(2,LOW);
  digitalWrite(4,LOW);
  digitalWrite(7,LOW);
  digitalWrite(8,LOW);
  Serial.println("I will stop");            //FOR DEBUGGING PURPOSES
}

void back()
{
  digitalWrite(2,LOW);
  digitalWrite(4,HIGH);
  digitalWrite(7,HIGH);
  digitalWrite(8,LOW);
  analogWrite(5,F);                          //FOR LEFT MOTOR SPEED CONTROL USING PWM
  analogWrite(6,F);                          //FOR RIGHT MOTOR SPEED CONTROL USING PWM
  Serial.println("I will go back");          //FOR DEBUGGING PURPOSES
  delay(1000);
}

void left()
{
   digitalWrite(2,LOW);
   digitalWrite(4,HIGH);
   digitalWrite(7,LOW);
   digitalWrite(8,HIGH);
   analogWrite(5,F);                          //FOR LEFT MOTOR SPEED CONTROL USING PWM
   analogWrite(6,F);                          //FOR RIGHT MOTOR SPEED CONTROL USING PWM
   Serial.println("I will go left");          //FOR DEBUGGING PURPOSES
   delay(800);
}

void right_screen()
{
  int pos;
   for(pos = 90; pos >= 0; pos -= 1) // goes from 90 degrees to 0 degrees ie TOWARDS RIGHT
  {                                  // in steps of 1 degree 
    myservo.write(pos);              // this is used for angle rotation
    delay(25);                       // waits 25ms for the servo to reach the position 
  } 
}
void right_return()                  //goes from 0 degree to 90 degree ie TOWARDS RIGHT
{
  int pos;
  for(pos=0;pos<=90;pos+=1)
  {
    myservo.write(pos);
    delay(25);
  }
} 

void left_screen()
{ 
  int pos;
  for(pos = 90; pos <= 180; pos += 1) // goes from 90 degrees to 180 degrees IE TOWARDS LEFT 
  {                                  // in steps of 1 degree 
    myservo.write(pos);              // thi is usd for angle rotation 
    delay(25);                       // waits 25ms for the servo to reach the position 
  } 
}
void left_return()                    //goes from 180 to 90 degrees ie again towards centre 
{
  int pos;                            //operation same as above
  for(pos=180; pos >= 90; pos-=1)
  {
    myservo.write(pos);
    delay(25);
  }
}

