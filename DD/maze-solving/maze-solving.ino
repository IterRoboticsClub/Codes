
float Kp=1,Ki=0.5,Kd=1.0;
float error=0, P=0, I=0, D=0, PID_value=0;
float previous_error=0, previous_I=0;
int sensor[6]={0, 0, 0, 0, 0, 0};
int initial_motor_speed=110;

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
    read_sensor_values();
    calculate_pid();
    display_values();
    decide_path();
    motor_control();
    halt();
}

void halt()
{
  Serial.println("\n\nHALT FOR 1.5 SECONDS ");
  delay(1500);  
}

void decide_path()
{
 if(sensor[5]==1)  //WHITE
 {
    if((sensor[0]==0)&&(sensor[1]==0)&&(sensor[2]==0)&&(sensor[3]==0)&&(sensor[4]==0))  //BLACK-BLACK-BLACK-BLACK-BLACK
   {
     turn_right();
   }
   else if((sensor[0]==1)&&(sensor[1]==1)&&(sensor[2]==0)&&(sensor[3]==0)&&(sensor[4]==0))    //WHITE-WHITE-BLACK-BLACK-BLACK
   {
     turn_right();
   }
   else if((sensor[0]==0)&&(sensor[1]==0)&&(sensor[2]==0)&&(sensor[3]==1)&&(sensor[4]==1)) //BLACK-BLACK-BLACK-WHITE-WHITE
   {
     turn_left();
   }
   else if((sensor[0]==1)&&(sensor[1]==1)&&(sensor[2]==1)&&(sensor[3]==1)&&(sensor[4]==1))  //WHITE-WHITE-WHITE-WHITE-WHITE
   {
     turn_back();
   }
   
   else if(sensor[5]==0)
   {
     if((sensor[0]==1)&&(sensor[1]==1)&&(sensor[2]==0)&&(sensor[3]==0)&&(sensor[4]==0))
     {
       turn_right();
     }
     else if((sensor[0]==0)&&(sensor[1]==0)&&(sensor[2]==0)&&(sensor[3]==1)&&(sensor[4]==1))
     {
       turn_left();
     }
   }
 }
 
 
  
  void turn_left()
  {
    digitalWrite(2,LOW);
    digitalWrite(4,HIGH);
    digitalWrite(7,LOW);
    digitalWrite(8,HIGH);
    analogWrite(9,150);
    analogWrite(10,150);
    delay(1000);
  }
  
  void turn_right()
  {
    digitalWrite(2,HIGH);
    digitalWrite(4,LOW);
    digitalWrite(7,HIGH);
    digitalWrite(8,LOW);
    analogWrite(9,150);
    analogWrite(10,150);
    delay(1000);
  }
  
  void turn_back()
  {
    digitalWrite(2,HIGH);
    digitalWrite(4,LOW);
    digitalWrite(7,HIGH);
    digitalWrite(8,LOW);
    analogWrite(9,150);
    analogWrite(10,150);
    delay(1000);
    
}


void read_sensor_values()
{
  sensor[0]=digitalRead(A0);
  sensor[1]=digitalRead(A1);
  sensor[2]=digitalRead(A2);
  sensor[3]=digitalRead(A3);
  sensor[4]=digitalRead(A4);
  
  if((sensor[0]==1)&&(sensor[1]==1)&&(sensor[2]==1)&&(sensor[3]==1)&&(sensor[4]==0))
  error=4;
  else if((sensor[0]==1)&&(sensor[1]==1)&&(sensor[2]==1)&&(sensor[3]==0)&&(sensor[4]==0))
  error=3;
  else if((sensor[0]==1)&&(sensor[1]==1)&&(sensor[2]==1)&&(sensor[3]==0)&&(sensor[4]==1))
  error=2;
  else if((sensor[0]==1)&&(sensor[1]==1)&&(sensor[2]==0)&&(sensor[3]==0)&&(sensor[4]==1))
  error=1;
  else if((sensor[0]==1)&&(sensor[1]==1)&&(sensor[2]==0)&&(sensor[3]==1)&&(sensor[4]==1))
  error=0;
  else if((sensor[0]==1)&&(sensor[1]==0)&&(sensor[2]==0)&&(sensor[3]==1)&&(sensor[4]==1))
  error=-1;
  else if((sensor[0]==1)&&(sensor[1]==0)&&(sensor[2]==1)&&(sensor[3]==1)&&(sensor[4]==1))
  error=-2;
  else if((sensor[0]==0)&&(sensor[1]==0)&&(sensor[2]==1)&&(sensor[3]==1)&&(sensor[4]==1))
  error=-3;
  else if((sensor[0]==0)&&(sensor[1]==1)&&(sensor[2]==1)&&(sensor[3]==1)&&(sensor[4]==1))
  error=-4;
  //else if((sensor[0]==0)&&(sensor[1]==0)&&(sensor[2]==0)&&(sensor[4]==0)&&(sensor[4]==0))
  
  else
  {
    if(error==-4)
  error=-5;
 
  else error=5;
  }
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
  Serial.println("\n---------------------------------------------------------------------\nP= ");
  Serial.print(P);
  Serial.println("\nI= ");
  Serial.print(I);
  Serial.println("\nD= ");
  Serial.print(D);
  Serial.println("\nPID value = ");
  Serial.print(PID_value);
  Serial.println("\n----------------------------------------------------------------------");
}

void motor_control()
{
    // Calculating the effective motor speed:
    int left_motor_speed = initial_motor_speed-PID_value;
    int right_motor_speed = initial_motor_speed+PID_value;
    
    // The motor speed should not exceed the max PWM value
    constrain(left_motor_speed,0,150);
    constrain(right_motor_speed,0,150);
	
      //Right Motor Speed
    //following lines of code are to make the bot move forward
    /*The pin numbers and high, low values might be different*/
    if((sensor[0]==1)&&(sensor[1]==1)&&(sensor[2]==0)&&(sensor[3]==1)&&(sensor[4]==1))    // 1 1 0 1 1
    {
    digitalWrite(2,HIGH);
    digitalWrite(4,LOW);
    digitalWrite(7,LOW);
    digitalWrite(8,HIGH);
    analogWrite(9,left_motor_speed);    //intial_motor_speed-PID_value
    analogWrite(10,right_motor_speed);    //intial_motor_speed+PID_value
    }
    

    else if((sensor[0]==1)&&(sensor[1]==0)&&(sensor[2]==0)&&(sensor[3]==1)&&(sensor[4]==1))  // 1 0 0 1 1
    {
    digitalWrite(2,HIGH);
    digitalWrite(4,LOW);
    digitalWrite(7,HIGH);
    digitalWrite(8,LOW);
    analogWrite(9,left_motor_speed);    //intial_motor_speed-PID_value
    analogWrite(10,right_motor_speed);    //intial_motor_speed+PID_value
    }
    
    else if((sensor[0]==1)&&(sensor[1]==0)&&(sensor[2]==1)&&(sensor[3]==1)&&(sensor[4]==1))  // 1 0 1 1 1
    {
    digitalWrite(2,HIGH);
    digitalWrite(4,LOW);
    digitalWrite(7,HIGH);
    digitalWrite(8,LOW);
    analogWrite(9,left_motor_speed);    //intial_motor_speed-PID_value
    analogWrite(10,right_motor_speed);    //intial_motor_speed+PID_value
    }
    
    else if((sensor[0]==0)&&(sensor[1]==1)&&(sensor[2]==1)&&(sensor[3]==1)&&(sensor[4]==1))  // 0 1 1 1 1
    {
    digitalWrite(2,HIGH);
    digitalWrite(4,LOW);
    digitalWrite(7,HIGH);
    digitalWrite(8,LOW);
    analogWrite(9,left_motor_speed);    //intial_motor_speed-PID_value
    analogWrite(10,right_motor_speed);    //intial_motor_speed+PID_value
    }
    
    else if((sensor[0]==0)&&(sensor[1]==0)&&(sensor[2]==1)&&(sensor[3]==1)&&(sensor[4]==1)) // 0 0 1 1 1
    {
    digitalWrite(2,HIGH);
    digitalWrite(4,LOW);
    digitalWrite(7,HIGH);
    digitalWrite(8,LOW);
    analogWrite(9,left_motor_speed);    //intial_motor_speed-PID_value
    analogWrite(10,right_motor_speed);    //intial_motor_speed+PID_value
    }
    
    
    //---------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    
    /*else if((sensor[0]==0)&&(sensor[1]==0)&&(sensor[2]==0)&&(sensor[3]==1)&&(sensor[4]==1)) // 0 0 0 1 1
    {
    digitalWrite(2,HIGH);
  digitalWrite(4,LOW);
  digitalWrite(7,LOW);
  digitalWrite(8,HIGH);
  analogWrite(9,150);
  analogWrite(10,150);
  delay(400);
  digitalWrite(2,LOW);
  digitalWrite(4,HIGH);
  digitalWrite(7,LOW);
  digitalWrite(8,HIGH);
  analogWrite(9,150);
  analogWrite(10,150);
  delay(400);                                                                             -----FOR 90 DEGREE LEFT TURN-----

    }*/
    
    //----------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    
    
    
    else if((sensor[0]==1)&&(sensor[1]==1)&&(sensor[2]==1)&&(sensor[3]==0)&&(sensor[4]==1)) // 1 1 1 0 1
    {
    digitalWrite(2,LOW);
    digitalWrite(4,HIGH);
    digitalWrite(7,LOW);
    digitalWrite(8,HIGH);
    analogWrite(9,left_motor_speed);    //intial_motor_speed-PID_value
    analogWrite(10,right_motor_speed);    //intial_motor_speed+PID_value
    }
    
     else if((sensor[0]==1)&&(sensor[1]==1)&&(sensor[2]==1)&&(sensor[3]==0)&&(sensor[4]==1)) // 1 1 0 0 1
    {
    digitalWrite(2,LOW);
    digitalWrite(4,HIGH);
    digitalWrite(7,LOW);
    digitalWrite(8,HIGH);
    analogWrite(9,left_motor_speed);    //intial_motor_speed-PID_value
    analogWrite(10,right_motor_speed);    //intial_motor_speed+PID_value
    }
    
    else if((sensor[0]==1)&&(sensor[1]==1)&&(sensor[2]==1)&&(sensor[3]==1)&&(sensor[4]==0))  // 1 1 1 1 0
    {
    digitalWrite(2,LOW);
    digitalWrite(4,HIGH);
    digitalWrite(7,LOW);
    digitalWrite(8,HIGH);
    analogWrite(9,left_motor_speed);    //intial_motor_speed-PID_value
    analogWrite(10,right_motor_speed);    //intial_motor_speed+PID_value
    }
    
    else if((sensor[0]==1)&&(sensor[1]==1)&&(sensor[2]==1)&&(sensor[3]==0)&&(sensor[4]==0))  // 1 1 1 0 0
    {
    digitalWrite(2,LOW);
    digitalWrite(4,HIGH);
    digitalWrite(7,LOW);
    digitalWrite(8,HIGH);
    analogWrite(9,left_motor_speed);    //intial_motor_speed-PID_value
    analogWrite(10,right_motor_speed);    //intial_motor_speed+PID_value
    }
    
    //------------------------------------------------------------------------------------------------------------------------------------------------------------------
    
  /*  else if((sensor[0]==1)&&(sensor[1]==1)&&(sensor[2]==0)&&(sensor[3]==0)&&(sensor[4]==0)) // 1 1 0 0 0
    {
     digitalWrite(2,HIGH);
  digitalWrite(4,LOW);
  digitalWrite(7,LOW);
  digitalWrite(8,HIGH);
  analogWrite(9,150);
  analogWrite(10,150);
  delay(400);
  digitalWrite(2,HIGH);
  digitalWrite(4,LOW);
  digitalWrite(7,HIGH);
  digitalWrite(8,LOW);
  analogWrite(9,150);
  analogWrite(10,150);
  delay(400);*/                                                                  //  -----------FOR 90 DEGREE RIGHT TURN-----------
    
    
    //-------------------------------------------------------------------------------------------------------------------------------------------------------------------
    
    
    
    else if((sensor[0]==1)&&(sensor[1]==1)&&(sensor[2]==1)&&(sensor[3]==1)&&(sensor[4]==1))   // 1 1 1 1 1
    {
    digitalWrite(2,HIGH);
    digitalWrite(4,LOW);
    digitalWrite(7,LOW);
    digitalWrite(8,HIGH);
    analogWrite(9,left_motor_speed);    //intial_motor_speed-PID_value
    analogWrite(10,right_motor_speed);    //intial_motor_speed+PID_value
    }
    
    else if((sensor[0]==0)&&(sensor[1]==0)&&(sensor[2]==0)&&(sensor[3]==0)&&(sensor[4]==0))  // 0 0 0 0 0
    {
    digitalWrite(2,HIGH);
    digitalWrite(4,LOW);
    digitalWrite(7,LOW);
    digitalWrite(8,HIGH);
    analogWrite(9,left_motor_speed);    //intial_motor_speed-PID_value
    analogWrite(10,right_motor_speed);    //intial_motor_speed+PID_value
    }
    
    else
    {
    digitalWrite(2,HIGH);
    digitalWrite(4,LOW);
    digitalWrite(7,LOW);
    digitalWrite(8,HIGH);
    analogWrite(9,left_motor_speed);    //intial_motor_speed-PID_value
    analogWrite(10,right_motor_speed);    //intial_motor_speed+PID_value
    }
    
    Serial.println("\nLeft Motor Speed ");
    Serial.print(left_motor_speed);
    Serial.println("\nRight Motor Speed ");
    Serial.print(right_motor_speed);
}

void right(left_motor_speed,right_motor_speed)
{
 digitalWrite(2,HIGH);
 digitalWrite(4,LOW);
 digitalWrite(7,HIGH);
 digitalWrite(8,LOW);
 analogWrite(9,left_motor_speed);
 analogWrite(10,right_motor_speed);
}

void left(left_motor_speed,right_motor_speed)
{
 digitalWrite(2,LOW);
 digitalWrite(4,HIGH);
 digitalWrite(7,LOW);
 digitalWrite(8,HIGH);
 analogWrite(9,left_motor_speed);
 analogWrite(10,right_motor_speed);
} 

void straight(left_motor_speed,right_motor_speed)
{
 digitalWrite(2,HIGH);
 digitalWrite(4,LOW);
 digitalWrite(7,LOW);
 digitalWrite(8,HIGH);
 analogWrite(9,left_motor_speed);
 analogWrite(10,right_motor_speed);
} 

  
