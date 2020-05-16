//PROGRAM FOR GRID FOLLOWING ON BLACK LINE WITH WHITE SURFACE.

#define leftCenterSensor   3
#define leftNearSensor     4
#define leftFarSensor      5
#define rightCenterSensor  2
#define rightNearSensor    1
#define rightFarSensor     0

int threshold=750;  //CHANGE THRESHOLD VALUE DURING CALIBRATION
int leftCenterReading;
int leftNearReading;
int leftFarReading;
int rightCenterReading;
int rightNearReading;
int rightFarReading;

#define leftMotor1  10
#define leftMotor2  9
#define rightMotor1 6
#define rightMotor2 5

void setup()
{
 
 pinMode(leftCenterSensor, INPUT);
 pinMode(leftNearSensor, INPUT);
 pinMode(leftFarSensor, INPUT);
 pinMode(rightCenterSensor, INPUT);
 pinMode(rightNearSensor, INPUT);
 pinMode(rightFarSensor, INPUT);
   
 pinMode(leftMotor1, OUTPUT);
 pinMode(leftMotor2, OUTPUT);
 pinMode(rightMotor1, OUTPUT);
 pinMode(rightMotor2, OUTPUT);

}

void loop()
{
  readSensors();
  if(leftNearReading>THRESHOLD && rightNearReading>THRESHOLD && (leftCenterReading<THRESHOLD || rightCenterReading<THRESHOLD))
    {
     straight();
    }
 else
    {
     stayOnLine();
    }
}

void readSensors()
{ 
 leftCenterReading  = analogRead(leftCenterSensor);
 leftNearReading    = analogRead(leftNearSensor);
 leftFarReading     = analogRead(leftFarSensor);
 rightCenterReading = analogRead(rightCenterSensor);
 rightNearReading   = analogRead(rightNearSensor);
 rightFarReading    = analogRead(rightFarSensor);  
}

void stayOnLine()
{
 if(leftNearReading>THRESHOLD && leftCenterReading<THRESHOLD && rightCenterReading<THRESHOLD && rightNearReading<THRESHOLD)
   {
     turnRight();
   }
 if(leftNearReading<THRESHOLD && leftCenterReading<THRESHOLD && rightCenterReading<THRESHOLD && rightNearReading>THRESHOLD)
   {
     turnLeft();
   }
 if(leftNearReading>THRESHOLD && leftCenterReading<THRESHOLD && rightCenterReading>THRESHOLD && rightNearReading>THRESHOLD)
   {
     turnLeft();
   }
 if(leftNearReading>THRESHOLD && leftCenterReading>THRESHOLD && rightCenterReading<THRESHOLD && rightNearReading>THRESHOLD)
   {
     turnRight();
   }
 if(leftNearReading<THRESHOLD && leftCenterReading<THRESHOLD && rightCenterReading<THRESHOLD && rightNearReading<THRESHOLD) 
   {
     endmotion();
   }
}//END OF STAY ONLINE.

 void turnLeft()
 {
     while(analogRead(rightCenterSensor)<THRESHOLD||analogRead(leftCenterSensor)<THRESHOLD)
     {
       digitalWrite(leftMotor1, LOW);
       digitalWrite(leftMotor2, HIGH);
       digitalWrite(rightMotor1, HIGH);
       digitalWrite(rightMotor2, LOW);
       delay(2000);
       digitalWrite(leftMotor1, LOW);
       digitalWrite(leftMotor2, LOW);
       digitalWrite(rightMotor1, LOW);
       digitalWrite(rightMotor2, LOW);
       delay(1000);
     }
   
     while(analogRead(rightCenterSensor)>THRESHOLD)
     {
       digitalWrite(leftMotor1, LOW);
       digitalWrite(leftMotor2, HIGH);
       digitalWrite(rightMotor1, HIGH);
       digitalWrite(rightMotor2, LOW);
       delay(2000);
       digitalWrite(leftMotor1, LOW);
       digitalWrite(leftMotor2, LOW);
       digitalWrite(rightMotor1, LOW);
       digitalWrite(rightMotor2, LOW);
       delay(1000);
     }
 }//END OF TURN LEFT.

void turnRight()
{   
 while(analogRead(rightCenterSensor)<THRESHOLD)
     {
       digitalWrite(leftMotor1, HIGH);
       digitalWrite(leftMotor2, LOW);
       digitalWrite(rightMotor1, LOW);
       digitalWrite(rightMotor2, HIGH);
       delay(2);
       digitalWrite(leftMotor1, LOW);
       digitalWrite(leftMotor2, LOW);
       digitalWrite(rightMotor1, LOW);
       digitalWrite(rightMotor2, LOW);
       delay(1);
     }
 while(analogRead(rightCenterSensor)>THRESHOLD)
    {
      digitalWrite(leftMotor1, HIGH);
      digitalWrite(leftMotor2, LOW);
      digitalWrite(rightMotor1, LOW);
      digitalWrite(rightMotor2, HIGH);
      delay(2);
      digitalWrite(leftMotor1, LOW);
      digitalWrite(leftMotor2, LOW);
      digitalWrite(rightMotor1, LOW);
      digitalWrite(rightMotor2, LOW);
      delay(1);
   }
 while(analogRead(leftCenterSensor)>THRESHOLD)
   {
      digitalWrite(leftMotor1, HIGH);
      digitalWrite(leftMotor2, LOW);
      digitalWrite(rightMotor1, LOW);
      digitalWrite(rightMotor2, HIGH);
      delay(2000);
      digitalWrite(leftMotor1, LOW);
      digitalWrite(leftMotor2, LOW);
      digitalWrite(rightMotor1, LOW);
      digitalWrite(rightMotor2, LOW);
      delay(1000);
   }
}//END OF TURN RIGHT
 
void straight()
   {
     if( analogRead(leftCenterSensor)>THRESHOLD) 
       {
         digitalWrite(leftMotor1, HIGH);
         digitalWrite(leftMotor2, LOW);
         digitalWrite(rightMotor1, HIGH);
         digitalWrite(rightMotor2, LOW);
         delay(1000);
         digitalWrite(leftMotor1, HIGH);
         digitalWrite(leftMotor2, LOW);
         digitalWrite(rightMotor1, LOW);
         digitalWrite(rightMotor2, LOW);
         delay(5000);
         return;
       }
     if(analogRead(rightCenterSensor)>THRESHOLD)
      {
        digitalWrite(leftMotor1, HIGH);
        digitalWrite(leftMotor2, LOW);
        digitalWrite(rightMotor1, HIGH);
        digitalWrite(rightMotor2, LOW);
        delay(1000);
        digitalWrite(leftMotor1, LOW);
        digitalWrite(leftMotor2, LOW);
        digitalWrite(rightMotor1, HIGH);
        digitalWrite(rightMotor2, LOW);
        delay(5000);
        return;
      }
 
   digitalWrite(leftMotor1, HIGH);
   digitalWrite(leftMotor2, LOW);
   digitalWrite(rightMotor1, HIGH);
   digitalWrite(rightMotor2, LOW);
   delay(4000);
   digitalWrite(leftMotor1, LOW);
   digitalWrite(leftMotor2, LOW);
   digitalWrite(rightMotor1, LOW);
   digitalWrite(rightMotor2, LOW);
   delay(1000);
 
}//END OF STRAIGHT
 
void endmotion()
 {
   digitalWrite(leftMotor1, LOW);
   digitalWrite(leftMotor2, LOW);
   digitalWrite(rightMotor1, LOW);
   digitalWrite(rightMotor2, LOW);
 }//END OF ENDMOTION
 
 //END OF PROGRAM
