const int trigPin = 3;
const int echoPin = 5;
float Kp=1,Ki=0.0,Kd=0.5;
float error=0, P=0, I=0, D=0, PID_value=0;
float previous_error=0, previous_I=0;
int sensor[6]={0, 0, 0, 0, 0, 0};
int initial_motor_speed=90;
int left_motor_speed = 0;
int right_motor_speed =0;
int g=5;

int object_detect();
void read_sensor_values(void);
void calculate_pid(void);
void motor_control(void);

void setup()
{
 pinMode(9,OUTPUT); //PWM Pin 1
 pinMode(10,OUTPUT); //PWM Pin 2
 pinMode(2,OUTPUT); //Left Motor Pin 1
 pinMode(4,OUTPUT); //Left Motor Pin 2
 pinMode(7,OUTPUT); //Right Motor Pin 1
 pinMode(8,OUTPUT);  //Right Motor Pin 2
 
 Serial.begin(9600); //Enable Serial Communications
}

void loop()
{
    /*g=object_detect();
    if(g==1)
    {
      digitalWrite(13,HIGH);
      Serial.print("\nIT IS READY TO GO");
    }
    else 
    {
      digitalWrite(13,LOW);
      Serial.print("\nIt will not Go");
    }*/
 
    read_sensor_values();
    calculate_pid();
    motor_control();
   // display_values();
   // delay(3000);
}

/*int object_detect()
{
  // establish variables for duration of the ping, 
  // and the distance result in inches and centimetersg=:
  long duration, inches, cm;
  int d=5;
  // The sensor is triggered by a HIGH pulse of 10 or more microseconds.
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
  pinMode(trigPin, OUTPUT);
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
 
  // Read the signal from the sensor: a HIGH pulse whose
  // duration is the time (in microseconds) from the sending
  // of the ping to the reception of its echo off of an object.
  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);
 
  // convert the time into a distance
  inches = microsecondsToInches(duration);
  cm = microsecondsToCentimeters(duration);
  
  Serial.print(inches);
  Serial.print("in, ");
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();
  
  delay(1000);
  if(cm>10)
  {
    d=1;
  }
  
  else d=0;
  return d;
}

long microsecondsToInches(long microseconds)
{
  // According to Parallax's datasheet for the PING))), there are
  // 73.746 microseconds per inch (i.e. sound travels at 1130 feet per
  // second).  This gives the distance travelled by the ping, outbound
  // and return, so we divide by 2 to get the distance of the obstacle.
  // See: http://www.parallax.com/dl/docs/prod/acc/28015-PING-v1.3.pdf
  return microseconds / 74 / 2;
}
 
long microsecondsToCentimeters(long microseconds)
{
  // The speed of sound is 340 m/s or 29 microseconds per centimeter.
  // The ping travels out and back, so to find the distance of the
  // object we take half of the distance travelled.
  return microseconds / 29 / 2;
}
*/
void read_sensor_values()
{
  
  sensor[0]=digitalRead(A0);
  sensor[1]=digitalRead(A1);
  sensor[2]=digitalRead(A2);
  sensor[3]=digitalRead(A3);
  sensor[4]=digitalRead(A4);
  sensor[5]=digitalRead(A5);
  
  if(((sensor[0]==1)&&(sensor[1]==1)&&(sensor[2]==1)&&(sensor[3]==1)&&(sensor[4]==1)&&(sensor[5]==0))  // (1-1-1-1-1-0)
  error=3;
  else if((sensor[0]==0)&&(sensor[1]==0)&&(sensor[2]==0)&&(sensor[3]==0)&&(sensor[4]==0)&&(sensor[5]==1))  // (0-0-0-0-0-1)
  error=3;
  else if((sensor[0]==1)&&(sensor[1]==1)&&(sensor[2]==1)&&(sensor[3]==1)&&(sensor[4]==0)&&(sensor[5]==0)) //  (1-1-1-1-0-0)
  error=2;
  else if((sensor[0]==0)&&(sensor[1]==0)&&(sensor[2]==0)&&(sensor[3]==0)&&(sensor[4]==1)&&(sensor[5]==1))  // (0-0-0-0-1-1)
  error=2;
  else if(((sensor[0]==1)&&(sensor[1]==1)&&(sensor[2]==1)&&(sensor[3]==0)&&(sensor[4]==0)&&(sensor[5]==1))  //(1-1-1-0-0-1)
  error=1;
  else if((sensor[0]==0)&&(sensor[1]==0)&&(sensor[2]==0)&&(sensor[3]==1)&&(sensor[4]==1)&&(sensor[5]==0)))  // (0-0-0-1-1-0)
  error=1;
  else if(((sensor[0]==1)&&(sensor[1]==1)&&(sensor[2]==0)&&(sensor[3]==0)&&(sensor[4]==1)&&(sensor[5]==1))   //(1-1-0-0-1-1)
  error=0;
  else if((sensor[0]==0)&&(sensor[1]==0)&&(sensor[2]==1)&&(sensor[3]==1)&&(sensor[4]==0)&&(sensor[5]==0)))  //  (0-0-1-1-0-0)
  error=0;
  else if(((sensor[0]==1)&&(sensor[1]==0)&&(sensor[2]==0)&&(sensor[3]==1)&&(sensor[4]==1)&&(sensor[5]==1))  // (1-0-0-1-1-1)
  error=-1;
  else if((sensor[0]==0)&&(sensor[1]==1)&&(sensor[2]==1)&&(sensor[3]==0)&&(sensor[4]==0)&&(sensor[5]==0)))  // (0-1-1-0-0-0)
  error=-1;
  
  else if(((sensor[0]==0)&&(sensor[1]==0)&&(sensor[2]==1)&&(sensor[3]==1)&&(sensor[4]==1)&&(sensor[5]==1))  // (0-0-1-1-1-1)
  error=-2;
  else if((sensor[0]==1)&&(sensor[1]==1)&&(sensor[2]==0)&&(sensor[3]==0)&&(sensor[4]==0)&&(sensor[5]==0)))  // (1-1-0-0-0-0)
  error=-2;
  else if(((sensor[0]==0)&&(sensor[1]==1)&&(sensor[2]==1)&&(sensor[3]==1)&&(sensor[4]==1)&&(sensor[5]==1))||((sensor[0]==1)&&(sensor[1]==0)&&(sensor[2]==0)&&(sensor[3]==0)&&(sensor[4]==0)&&(sensor[5]==0)))  // (0-1-1-1-1-1) && (1-0-0-0-0-0)
  error=-3;
  //else if((sensor[0]==0)&&(sensor[1]==0)&&(sensor[2]==0)&&(sensor[3]==0)&&(sensor[4]==0))
  
 /* else
  {
    if(error==-4)
  error=-5;
 
  else error=5;
  }*/
}

void calculate_pid()
{
    P = error;
    I = I + error;
    D = error-previous_error;
    
    PID_value = (Kp*P) + (Ki*I) + (Kd*D);
    
    previous_I=I;
    previous_error=error;
}

void display_values()
{
  Serial.print("\n---------------------------------------------------------------------\nP= ");
  Serial.print(P);
  Serial.print("\nI= ");
  Serial.print(I);
  Serial.print("\nD= ");
  Serial.print(D);
  Serial.print("\nPID value = ");
  Serial.print(PID_value);
  Serial.print("\nLEFT MOTOR SPEED= ");
  Serial.print(left_motor_speed);
  Serial.print("\nRIGHT MOTOR SPEED= ");
  Serial.print(right_motor_speed);
  Serial.println("\n----------------------------------------------------------------------");
}

void motor_control()
{
    // Calculating the effective motor speed:
    left_motor_speed = initial_motor_speed-PID_value;
    right_motor_speed = initial_motor_speed+PID_value;
    
    // The motor speed should not exceed the max PWM value
    constrain(left_motor_speed,0,150);
    constrain(right_motor_speed,0,150);
	
      //Right Motor Speed
    //following lines of code are to make the bot move forward
    /*The pi-*n numbers and high, low values might be different*/
    
    //if((sensor[0]==1)&&(sensor[1]==1)&&(sensor[2]==0)&&(sensor[3]==0)&&(sensor[4]==1)&&(sensor[5]==1))    // 1 1 0 0 1 1
    if(((sensor[0]==1)&&(sensor[1]==1)&&(sensor[2]==0)&&(sensor[3]==0)&&(sensor[4]==1)&&(sensor[5]==1))||((sensor[0]==0)&&(sensor[1]==0)&&(sensor[2]==1)&&(sensor[3]==1)&&(sensor[4]==0)&&(sensor[5]==0)))  // (1-1-0-0-1-1) && (0-0-1-1-0-0)
    {
    digitalWrite(2,HIGH);
    digitalWrite(4,LOW);
    digitalWrite(7,LOW);
    digitalWrite(8,HIGH);
    analogWrite(9,left_motor_speed);    //intial_motor_speed-PID_value
    analogWrite(10,right_motor_speed);    //intial_motor_speed+PID_value
    }
    

    //else if((sensor[0]==1)&&(sensor[1]==0)&&(sensor[2]==0)&&(sensor[3]==1)&&(sensor[4]==1)&&(sensor[5]==1))  // 1 0 0 1 1 1
   else if(((sensor[0]==1)&&(sensor[1]==0)&&(sensor[2]==0)&&(sensor[3]==1)&&(sensor[4]==1)&&(sensor[5]==1))||((sensor[0]==0)&&(sensor[1]==1)&&(sensor[2]==1)&&(sensor[3]==0)&&(sensor[4]==0)&&(sensor[5]==0)))  // (1-0-0-1-1-1) && (0-1-1-0-0-0 
    {
    digitalWrite(2,LOW);
    digitalWrite(4,HIGH);
    digitalWrite(7,LOW);
    digitalWrite(8,HIGH);
    analogWrite(9,left_motor_speed); //intial_motor_speed-PID_value
    analogWrite(10,right_motor_speed);    //intial_motor_speed+PID_value
    }
    
    //else if((sensor[0]==0)&&(sensor[1]==0)&&(sensor[2]==1)&&(sensor[3]==1)&&(sensor[4]==1)&&(sensor[5]==1))  // 0 0 1 1 1 1   
     else if(((sensor[0]==0)&&(sensor[1]==0)&&(sensor[2]==1)&&(sensor[3]==1)&&(sensor[4]==1)&&(sensor[5]==1))||((sensor[0]==1)&&(sensor[1]==1)&&(sensor[2]==0)&&(sensor[3]==0)&&(sensor[4]==0)&&(sensor[5]==0)))  // (0-0-1-1-1-1) && (1-1-0-0-0-0)
    {
    digitalWrite(2,LOW);
    digitalWrite(4,HIGH);
    digitalWrite(7,LOW);
    digitalWrite(8,HIGH);
    analogWrite(9,left_motor_speed);    //intial_motor_speed-PID_value
    analogWrite(10,right_motor_speed);    //intial_motor_speed+PID_value
    }
    
   // else if((sensor[0]==0)&&(sensor[1]==1)&&(sensor[2]==1)&&(sensor[3]==1)&&(sensor[4]==1)&&(sensor[5]==1))  // 0 1 1 1 1 1
    else if(((sensor[0]==0)&&(sensor[1]==1)&&(sensor[2]==1)&&(sensor[3]==1)&&(sensor[4]==1)&&(sensor[5]==1))||((sensor[0]==1)&&(sensor[1]==0)&&(sensor[2]==0)&&(sensor[3]==0)&&(sensor[4]==0)&&(sensor[5]==0)))  // (0-1-1-1-1-1) && (1-0-0-0-0-0)
    {
    digitalWrite(2,LOW);
    digitalWrite(4,HIGH);
    digitalWrite(7,LOW);
    digitalWrite(8,HIGH);
    analogWrite(9,left_motor_speed);    //intial_motor_speed-PID_value
    analogWrite(10,right_motor_speed);    //intial_motor_speed+PID_value
    }
    
    
      else if((sensor[0]==0)&&(sensor[1]==0)&&(sensor[2]==0)&&(sensor[3]==0)&&(sensor[4]==1)&&(sensor[5]==1)) // 0 0 0 0 1 1
    {
     halt();
     forward();
     digitalWrite(2,LOW);
     digitalWrite(4,HIGH);
     digitalWrite(7,LOW);
     digitalWrite(8,HIGH);    //FOR LEFT TURN 90
     analogWrite(9,110); 
     analogWrite(10,110);
     delay(530);//530
     halt();
     forward();
     }
     
     else if((sensor[0]==0)&&(sensor[1]==0)&&(sensor[2]==0)&&(sensor[3]==1)&&(sensor[4]==1)&&(sensor[5]==1))  //0-0-0-1-1-1
     {
       halt();
     forward();
     digitalWrite(2,LOW);
     digitalWrite(4,HIGH);
     digitalWrite(7,LOW);    //FOR LEFT TURN 90
     digitalWrite(8,HIGH);
     analogWrite(9,110); 
     analogWrite(10,110);
     delay(530);//530
     halt();
     forward();
     }
     
     else if((sensor[0]==0)&&(sensor[1]==0)&&(sensor[2]==0)&&(sensor[3]==0)&&(sensor[4]==0)&&(sensor[5]==1))  //0-0-0-0-0-1
     {
       halt();
     forward();
     digitalWrite(2,LOW);
     digitalWrite(4,HIGH);
     digitalWrite(7,LOW);
     digitalWrite(8,HIGH);    //FOR LEFT 90 TURN
     analogWrite(9,110); 
     analogWrite(10,110);
     delay(530);//530
     halt();
     forward();
     }
        
    else if((sensor[0]==1)&&(sensor[1]==1)&&(sensor[2]==0)&&(sensor[3]==0)&&(sensor[4]==0)&&(sensor[5]==0)) // 1 1 0 0 0 0
    {
      
    halt();
    forward();
    digitalWrite(2,HIGH);
    digitalWrite(4,LOW);
    digitalWrite(7,HIGH);
    digitalWrite(8,LOW);    //FOR RIGHT TURN 90
    analogWrite(9,110);
    analogWrite(10,110);
    delay(530);//530
    halt();
    forward();
    }
    
     else if((sensor[0]==1)&&(sensor[1]==1)&&(sensor[2]==1)&&(sensor[3]==0)&&(sensor[4]==0)&&(sensor[5]==0)) // 1 1 1 0 0 0
    {
      
    halt();
    forward();
    digitalWrite(2,HIGH);
    digitalWrite(4,LOW);
    digitalWrite(7,HIGH);
    digitalWrite(8,LOW);    //FOR RIGHT TURN 90
    analogWrite(9,110);
    analogWrite(10,110);
    delay(480);//530
    halt();
    forward();
    }
    
     else if((sensor[0]==1)&&(sensor[1]==0)&&(sensor[2]==0)&&(sensor[3]==0)&&(sensor[4]==0)&&(sensor[5]==0)) // 1 0 0 0 0 0
    {
      
    halt();
    forward();
    digitalWrite(2,HIGH);
    digitalWrite(4,LOW);
    digitalWrite(7,HIGH);
    digitalWrite(8,LOW);    //FOR RIGHT TURN 90
    analogWrite(9,110);
    analogWrite(10,110);
    delay(530);//530
    halt();
    forward();
    }
    
    else if((sensor[0]==1)&&(sensor[1]==1)&&(sensor[2]==1)&&(sensor[3]==1)&&(sensor[4]==0)&&(sensor[5]==0)) // 1 1 1 1 0 0
    {
     halt();
     forward();
     digitalWrite(2,LOW);
     digitalWrite(4,HIGH);
     digitalWrite(7,LOW);
     digitalWrite(8,HIGH);    //FOR LEFT TURN 90
     analogWrite(9,110); 
     analogWrite(10,110);
     delay(530);//530
     halt();
     forward();
     }
     
     else if((sensor[0]==1)&&(sensor[1]==1)&&(sensor[2]==1)&&(sensor[3]==0)&&(sensor[4]==0)&&(sensor[5]==0))  //1-1-1-0-0-0
     {
       halt();
     forward();
     digitalWrite(2,LOW);
     digitalWrite(4,HIGH);
     digitalWrite(7,LOW);    //FOR LEFT TURN 90
     digitalWrite(8,HIGH);
     analogWrite(9,110); 
     analogWrite(10,110);
     delay(530);//530
     halt();
     forward();
     }
     
     else if((sensor[0]==1)&&(sensor[1]==1)&&(sensor[2]==1)&&(sensor[3]==1)&&(sensor[4]==1)&&(sensor[5]==0))  //1-1-1-1-1-0
     {
       halt();
     forward();
     digitalWrite(2,LOW);
     digitalWrite(4,HIGH);
     digitalWrite(7,LOW);
     digitalWrite(8,HIGH);    //FOR LEFT 90 TURN
     analogWrite(9,110); 
     analogWrite(10,110);
     delay(530);//530
     halt();
     forward();
     }
        
    else if((sensor[0]==0)&&(sensor[1]==0)&&(sensor[2]==1)&&(sensor[3]==1)&&(sensor[4]==1)&&(sensor[5]==1)) // 0 0 1 1 1 1
    {  
    halt();
    forward();
    digitalWrite(2,HIGH);
    digitalWrite(4,LOW);
    digitalWrite(7,HIGH);
    digitalWrite(8,LOW);    //FOR RIGHT TURN 90
    analogWrite(9,110);
    analogWrite(10,110);
    delay(530);//530
    halt();
    forward();
    }
    
     else if((sensor[0]==0)&&(sensor[1]==0)&&(sensor[2]==0)&&(sensor[3]==1)&&(sensor[4]==1)&&(sensor[5]==1)) // 0 0 0 1 1 1
    {
      
    halt();
    forward();
    digitalWrite(2,HIGH);
    digitalWrite(4,LOW);
    digitalWrite(7,HIGH);
    digitalWrite(8,LOW);    //FOR RIGHT TURN 90
    analogWrite(9,110);
    analogWrite(10,110);
    delay(480);//530
    halt();
    forward();
    }
    
     else if((sensor[0]==0)&&(sensor[1]==1)&&(sensor[2]==1)&&(sensor[3]==1)&&(sensor[4]==1)&&(sensor[5]==1)) // 0 1 1 1 1 1
    {
      
    halt();
    forward();
    digitalWrite(2,HIGH);
    digitalWrite(4,LOW);
    digitalWrite(7,HIGH);
    digitalWrite(8,LOW);    //FOR RIGHT TURN 90
    analogWrite(9,110);
    analogWrite(10,110);
    delay(530);//530
    halt();
    forward();
    }
    //else if((sensor[0]==1)&&(sensor[1]==1)&&(sensor[2]==1)&&(sensor[3]==0)&&(sensor[4]==0)&&(sensor[5]=1)) // 1 1 1 0 0 1
     else if(((sensor[0]==1)&&(sensor[1]==1)&&(sensor[2]==1)&&(sensor[3]==0)&&(sensor[4]==0)&&(sensor[5]==1))||((sensor[0]==0)&&(sensor[1]==0)&&(sensor[2]==0)&&(sensor[3]==1)&&(sensor[4]==1)&&(sensor[5]==0)))  // (1-1-1-0-0-1) && (0-0-0-1-1-0
    {
    digitalWrite(2,HIGH);
    digitalWrite(4,LOW);
    digitalWrite(7,HIGH);
    digitalWrite(8,LOW);
    analogWrite(9,left_motor_speed);    //intial_motor_speed-PID_value
    analogWrite(10,right_motor_speed);    //intial_motor_speed+PID_value
    }
    
    
    // else if((sensor[0]==1)&&(sensor[1]==1)&&(sensor[2]==1)&&(sensor[3]==1)&&(sensor[4]==0)&&(sensor[5]==0)) // 1 1 1 1 0 0
    else if(((sensor[0]==1)&&(sensor[1]==1)&&(sensor[2]==1)&&(sensor[3]==1)&&(sensor[4]==0)&&(sensor[5]==0))||((sensor[0]==0)&&(sensor[1]==0)&&(sensor[2]==0)&&(sensor[3]==0)&&(sensor[4]==1)&&(sensor[5]==1)))  // (1-1-1-1-0-0) && (0-0-0-0-1-1)
    {
    digitalWrite(2,HIGH);
    digitalWrite(4,LOW);
    digitalWrite(7,HIGH);
    digitalWrite(8,LOW);
    analogWrite(9,left_motor_speed);    //intial_motor_speed-PID_value
    analogWrite(10,right_motor_speed);    //intial_motor_speed+PID_value
    }
    
   // else if((sensor[0]==1)&&(sensor[1]==1)&&(sensor[2]==1)&&(sensor[3]==1)&&(sensor[4]==1)&&(sensor[5]==0))  // 1 1 1 1 1 0
    if(((sensor[0]==1)&&(sensor[1]==1)&&(sensor[2]==1)&&(sensor[3]==1)&&(sensor[4]==1)&&(sensor[5]==0))||((sensor[0]==0)&&(sensor[1]==0)&&(sensor[2]==0)&&(sensor[3]==0)&&(sensor[4]==0)&&(sensor[5]==1)))  // (1-1-1-1-1-0) && (0-0-0-0-0-1)
    {
    digitalWrite(2,HIGH);
    digitalWrite(4,LOW);
    digitalWrite(7,HIGH);
    digitalWrite(8,LOW);
    analogWrite(9,left_motor_speed);    //intial_motor_speed-PID_value
    analogWrite(10,right_motor_speed);    //intial_motor_speed+PID_value
    }
     
    
   /* else if((sensor[0]==1)&&(sensor[1]==1)&&(sensor[2]==1)&&(sensor[3]==1)&&(sensor[4]==1))   // 1 1 1 1 1
    {
    digitalWrite(2,HIGH);
    digitalWrite(4,LOW);
    digitalWrite(7,LOW);
    digitalWrite(8,HIGH);
    analogWrite(9,left_motor_speed);    //intial_motor_speed-PID_value
    analogWrite(10,right_motor_speed);    //intial_motor_speed+PID_value
    }*/
    
    else if(((sensor[0]==0)&&(sensor[1]==0)&&(sensor[2]==0)&&(sensor[3]==0)&&(sensor[4]==0)&&(sensor[5]==0))||((sensor[0]==1)&&(sensor[1]==1)&&(sensor[2]==1)&&(sensor[3]==1)&&(sensor[4]==1)&&(sensor[5]==1)))   // 0 0 0 0 0 0
    {
      halt();
    digitalWrite(2,HIGH);
    digitalWrite(4,LOW);
    digitalWrite(7,HIGH);
    digitalWrite(8,LOW);
    analogWrite(9,110);
    analogWrite(10,110);
    delay(1000);
      halt();
    }
      
    else
    {
    digitalWrite(2,HIGH);
    digitalWrite(4,LOW);
    digitalWrite(7,LOW);
    digitalWrite(8,HIGH);
    analogWrite(9,100);    //intial_motor_speed-PID_value
    analogWrite(10,100);    //intial_motor_speed+PID_value
    }
    
    Serial.println("\nLeft Motor Speed ");
    Serial.print(left_motor_speed);
    Serial.println("\nRight Motor Speed ");
    Serial.print(right_motor_speed);
}

void halt()

{
  digitalWrite(2,LOW);
  digitalWrite(4,LOW);
  digitalWrite(7,LOW);
  digitalWrite(8,LOW);
  delay(1000);
}

void forward()
{
  digitalWrite(2,HIGH);
  digitalWrite(4,LOW);
  digitalWrite(7,LOW);
  digitalWrite(8,HIGH);
  analogWrite(9,110);
  analogWrite(10,110);
  delay(123);
}

