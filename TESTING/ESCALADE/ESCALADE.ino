int surface[2]={0, 0};
int sensor[6]={0, 0, 0, 0, 0, 0};
float initial_motor_speed=80;
int left_motor_speed,right_motor_speed;
float Kp=1,Ki=0.0,Kd=0.5;
float error=0, P=0, I=0, D=0, PID_value=0;
float previous_error=0, previous_I=0;
int decide=5;
void setup() 
{
  pinMode(9,OUTPUT); //PWM Pin 1
 pinMode(10,OUTPUT); //PWM Pin 2
 pinMode(2,OUTPUT); //Left Motor Pin 1
 pinMode(4,OUTPUT); //Left Motor Pin 2
 pinMode(7,OUTPUT); //Right Motor Pin 1
 pinMode(8,OUTPUT);  //Right Motor Pin 2
  // put your setup code here, to run once:
Serial.begin(9600);

}

void loop() 
{ 
 // detect_box();    //ULTRASONIC SENSOR HC-SR04
  surface[0]=digitalRead(11);
  surface[1]=digitalRead(12);
  display_values();
  
//FOR BLACK SURFACE AND WHITE LINE 
if((surface[0]==0)&&(surface[1]==0))//||((surface[0]==1)&&(surface[1]==0))||((surface[0]==0)&&(surface[1]==1)))
{
   decide=1;  
   Serial.println(decide);
  pid_white();

  
}
 //FOR WHITE SURFACE AND BLACK LINE
else if(((surface[0]==1)&&(surface[1]==1))||((surface[0]==1)&&(surface[1]==0))||((surface[0]==0)&&(surface[1]==1)))
{
  decide=2;
  pid_black();
  
  Serial.println(decide);
}
/*switch(decide)
{
  case 1:
         break;
  case 2:
         break;
  default:Serial.println("The stop");
}*/
}

void pid_white()
{
      white_read_sensor_values();
      calculate_pid();
      white_motor_control();
      Serial.println("I M PID WHITE");
}

void pid_black()
{
    black_read_sensor_values();
    calculate_pid();
    black_motor_control();
    Serial.print("I M PID_BLACK");
}

void black_read_sensor_values()    //FOR BLACK LINE
{
  sensor[0]=digitalRead(A0);
  sensor[1]=digitalRead(A1);
  sensor[2]=digitalRead(A2);
  sensor[3]=digitalRead(A3);
  sensor[4]=digitalRead(A4);
  sensor[5]=digitalRead(A5);
  
 
  if((sensor[0]==1)&&(sensor[1]==1)&&(sensor[2]==1)&&(sensor[3]==1)&&(sensor[4]==1)&&(sensor[5]==0))  //1-1-1-1-1-0
  error=3;
  
  else if((sensor[0]==1)&&(sensor[1]==1)&&(sensor[2]==1)&&(sensor[3]==1)&&(sensor[4]==0)&&(sensor[5]==0))  //1-1-1-1-0-0
  error=2;
  
  else if((sensor[0]==1)&&(sensor[1]==1)&&(sensor[2]==1)&&(sensor[3]==0)&&(sensor[4]==0)&&(sensor[5]==1))  //1-1-1-0-0-1
  error=1;
  
  else if((sensor[0]==1)&&(sensor[1]==1)&&(sensor[2]==0)&&(sensor[3]==0)&&(sensor[4]==1)&&(sensor[5]==1))  //1-1-0-0-1-1
  error=0;
  
  else if((sensor[0]==1)&&(sensor[1]==0)&&(sensor[2]==0)&&(sensor[3]==1)&&(sensor[4]==1)&&(sensor[5]==1))  //1-0-0-1-1-1
  error=-1;
  
  else if((sensor[0]==0)&&(sensor[1]==0)&&(sensor[2]==1)&&(sensor[3]==1)&&(sensor[4]==1)&&(sensor[5]==1))  //0-0-1-1-1-1
  error=-2;
  
  else if((sensor[0]==0)&&(sensor[1]==1)&&(sensor[2]==1)&&(sensor[3]==1)&&(sensor[4]==1)&&(sensor[5]==1))  //0-1-1-1-1-1
  error=-3;
    
  else
  {
    if(error==-3)
  error=-4;
 
  else error=4;
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

void black_motor_control() //For Black Line
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
    
    if((sensor[0]==1)&&(sensor[1]==1)&&(sensor[2]==0)&&(sensor[3]==0)&&(sensor[4]==1)&&(sensor[5]==1))    // 1 1 0 0 1 1
    {
    digitalWrite(2,HIGH);
    digitalWrite(4,LOW);
    digitalWrite(7,LOW);
    digitalWrite(8,HIGH);
    analogWrite(9,left_motor_speed);    //intial_motor_speed-PID_value
    analogWrite(10,right_motor_speed);    //intial_motor_speed+PID_value
    }
    

    else if((sensor[0]==1)&&(sensor[1]==0)&&(sensor[2]==0)&&(sensor[3]==1)&&(sensor[4]==1)&&(sensor[5]==1))  // 1 0 0 1 1 1
    {
    digitalWrite(2,LOW);
    digitalWrite(4,HIGH);
    digitalWrite(7,LOW);
    digitalWrite(8,HIGH);
    analogWrite(9,left_motor_speed);    //intial_motor_speed-PID_value
    analogWrite(10,right_motor_speed);    //intial_motor_speed+PID_value
    }
    
    else if((sensor[0]==0)&&(sensor[1]==0)&&(sensor[2]==1)&&(sensor[3]==1)&&(sensor[4]==1)&&(sensor[5]==1))  // 0 0 1 1 1 1
    {
    digitalWrite(2,LOW);
    digitalWrite(4,HIGH);
    digitalWrite(7,LOW);
    digitalWrite(8,HIGH);
    analogWrite(9,left_motor_speed);    //intial_motor_speed-PID_value
    analogWrite(10,right_motor_speed);    //intial_motor_speed+PID_value
    }
    
    else if((sensor[0]==0)&&(sensor[1]==1)&&(sensor[2]==1)&&(sensor[3]==1)&&(sensor[4]==1)&&(sensor[5]==1))  // 0 1 1 1 1 1
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
     digitalWrite(8,HIGH);              //FOR LEFT TURN 90
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
    delay(530);//530
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
    
    else if((sensor[0]==1)&&(sensor[1]==1)&&(sensor[2]==1)&&(sensor[3]==0)&&(sensor[4]==0)&&(sensor[5]=1)) // 1 1 1 0 0 1
    {
    digitalWrite(2,HIGH);
    digitalWrite(4,LOW);
    digitalWrite(7,HIGH);
    digitalWrite(8,LOW);
    analogWrite(9,left_motor_speed);    //intial_motor_speed-PID_value
    analogWrite(10,right_motor_speed);    //intial_motor_speed+PID
    }
    
    
     else if((sensor[0]==1)&&(sensor[1]==1)&&(sensor[2]==1)&&(sensor[3]==1)&&(sensor[4]==0)&&(sensor[5]==0)) // 1 1 1 1 0 0
    {
    digitalWrite(2,HIGH);
    digitalWrite(4,LOW);
    digitalWrite(7,HIGH);
    digitalWrite(8,LOW);
    analogWrite(9,left_motor_speed);    //intial_motor_speed-PID_value
    analogWrite(10,right_motor_speed);    //intial_motor_speed+PID_value
    }
    
    else if((sensor[0]==1)&&(sensor[1]==1)&&(sensor[2]==1)&&(sensor[3]==1)&&(sensor[4]==1)&&(sensor[5]==0))  // 1 1 1 1 1 0
    {
    digitalWrite(2,HIGH);
    digitalWrite(4,LOW);
    digitalWrite(7,HIGH);
    digitalWrite(8,LOW);
    analogWrite(9,left_motor_speed);    //intial_motor_speed-PID_value
    analogWrite(10,right_motor_speed);    //intial_motor_speed+PID_value
    }
    
   /*else if((sensor[0]==0)&&(sensor[1]==0)&&(sensor[2]==0)&&(sensor[3]==0)&&(sensor[4]==0)&&(sensor[5]==0))   // 0 0 0 0 0 0
    {
    digitalWrite(2,HIGH);
    digitalWrite(4,LOW);
    digitalWrite(7,LOW);
    digitalWrite(8,HIGH);
    analogWrite(9,left_motor_speed);    //intial_motor_speed-PID_value
    analogWrite(10,right_motor_speed);    //intial_motor_speed+PID_value
    }*/
    else if((sensor[0]==1)&&(sensor[1]==1)&&(sensor[2]==1)&&(sensor[3]==1)&&(sensor[4]==1)&&(sensor[5]==1))  // 1 1 1 1 1 1
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
    analogWrite(9,110);    //intial_motor_speed-PID_value
    analogWrite(10,110);    //intial_motor_speed+PID_value
    }
    
    Serial.println("\nLeft Motor Speed ");
    Serial.print(left_motor_speed);
    Serial.println("\nRight Motor Speed ");
    Serial.print(right_motor_speed);
  }

 
void detect_box()
{
  //ULTRASONIC SENSOR
}


void white_read_sensor_values()    //FOR WHITE LINE
{
  sensor[0]=digitalRead(A0);
  sensor[1]=digitalRead(A1);
  sensor[2]=digitalRead(A2);
  sensor[3]=digitalRead(A3);
  sensor[4]=digitalRead(A4);
  sensor[5]=digitalRead(A5);
    
  if((sensor[0]==0)&&(sensor[1]==0)&&(sensor[2]==0)&&(sensor[3]==0)&&(sensor[4]==0)&&(sensor[5]==1))  //0-0-0-0-0-1
  error=3;
  
  else if((sensor[0]==0)&&(sensor[1]==0)&&(sensor[2]==0)&&(sensor[3]==0)&&(sensor[4]==1)&&(sensor[5]==1))  //0-0-0-0-1-1
  error=2;
  
  else if((sensor[0]==0)&&(sensor[1]==0)&&(sensor[2]==0)&&(sensor[3]==1)&&(sensor[4]==1)&&(sensor[5]==0))  //0-0-0-1-1-0
  error=1;
  
  else if((sensor[0]==0)&&(sensor[1]==0)&&(sensor[2]==1)&&(sensor[3]==1)&&(sensor[4]==0)&&(sensor[5]==0))  //0-0-1-1-0-0
  error=0;
  
  else if((sensor[0]==0)&&(sensor[1]==1)&&(sensor[2]==1)&&(sensor[3]==0)&&(sensor[4]==0)&&(sensor[5]==0))  //0-1-1-0-0-0
  error=-1;
  
  else if((sensor[0]==1)&&(sensor[1]==1)&&(sensor[2]==0)&&(sensor[3]==0)&&(sensor[4]==0)&&(sensor[5]==0))  //1-1-0-0-0-0
  error=-2;
  
  else if((sensor[0]==1)&&(sensor[1]==0)&&(sensor[2]==0)&&(sensor[3]==0)&&(sensor[4]==0)&&(sensor[5]==0))  //1-0-0-0-0-0
  error=-3;
    
  else
  {
    if(error==-3)
  error=-4;
 
  else error=4;
  }
}

void white_motor_control()   //FOR WHITE LINE
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
    if((sensor[0]==0)&&(sensor[1]==0)&&(sensor[2]==1)&&(sensor[3]==1)&&(sensor[4]==0)&&(sensor[5]==0))    // 0 0 1 1 0 0
    {
    digitalWrite(2,HIGH);
    digitalWrite(4,LOW);
    digitalWrite(7,LOW);
    digitalWrite(8,HIGH);
    analogWrite(9,left_motor_speed);    //intial_motor_speed-PID_value
    analogWrite(10,right_motor_speed);    //intial_motor_speed+PID_value
    }
    

    else if((sensor[0]==0)&&(sensor[1]==1)&&(sensor[2]==1)&&(sensor[3]==0)&&(sensor[4]==0)&&(sensor[5]==0))  // 0 1 1 0 0 0
    {
    digitalWrite(2,LOW);
    digitalWrite(4,HIGH);
    digitalWrite(7,LOW);
    digitalWrite(8,HIGH);
    analogWrite(9,left_motor_speed);    //intial_motor_speed-PID_value
    analogWrite(10,right_motor_speed);    //intial_motor_speed+PID_value
    }
    
    else if((sensor[0]==1)&&(sensor[1]==1)&&(sensor[2]==0)&&(sensor[3]==0)&&(sensor[4]==0)&&(sensor[5]==0))  // 1 1 0 0 0 0
    {
    digitalWrite(2,LOW);
    digitalWrite(4,HIGH);
    digitalWrite(7,LOW);
    digitalWrite(8,HIGH);
    analogWrite(9,left_motor_speed);    //intial_motor_speed-PID_value
    analogWrite(10,right_motor_speed);    //intial_motor_speed+PID_value
    }
    
    else if((sensor[0]==1)&&(sensor[1]==0)&&(sensor[2]==0)&&(sensor[3]==0)&&(sensor[4]==0)&&(sensor[5]==0))  // 1 0 0 0 0 0
    {
    digitalWrite(2,LOW);
    digitalWrite(4,HIGH);
    digitalWrite(7,LOW);
    digitalWrite(8,HIGH);
    analogWrite(9,left_motor_speed);    //intial_motor_speed-PID_value
    analogWrite(10,right_motor_speed);    //intial_motor_speed+PID_value
    }
     
    //---------------------------------------------------------------------------------------------------------------------------------------------------------------------------
   
       else if((sensor[0]==1)&&(sensor[1]==1)&&(sensor[2]==1)&&(sensor[3]==1)&&(sensor[4]==0)&&(sensor[5]==0)) // 1 1 1 1 0 0
    {
     halt();
     forward();
     digitalWrite(2,LOW);
     digitalWrite(4,HIGH);
     digitalWrite(7,LOW);
     digitalWrite(8,HIGH);              //FOR LEFT TURN 90
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
    delay(530);//530
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
    
   
    //----------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    
    
    
    else if((sensor[0]==0)&&(sensor[1]==0)&&(sensor[2]==0)&&(sensor[3]==1)&&(sensor[4]==1)&&(sensor[5]==0)) // 0 0 0 1 1 0
    {
    digitalWrite(2,HIGH);
    digitalWrite(4,LOW);
    digitalWrite(7,HIGH);
    digitalWrite(8,LOW);
    analogWrite(9,left_motor_speed);    //intial_motor_speed-PID_value
    analogWrite(10,right_motor_speed);    //intial_motor_speed+PID_value
    }
    
     else if((sensor[0]==0)&&(sensor[1]==0)&&(sensor[2]==0)&&(sensor[3]==0)&&(sensor[4]==1)&&(sensor[5]==1)) // 0 0 0 0 1 1
    {
    digitalWrite(2,HIGH);
    digitalWrite(4,LOW);
    digitalWrite(7,HIGH);
    digitalWrite(8,LOW);
    analogWrite(9,left_motor_speed);    //intial_motor_speed-PID_value
    analogWrite(10,right_motor_speed);    //intial_motor_speed+PID_value
    }
    
    else if((sensor[0]==0)&&(sensor[1]==0)&&(sensor[2]==0)&&(sensor[3]==0)&&(sensor[4]==0)&&(sensor[5]==1))  // 0 0 0 0 0 1
    {
    digitalWrite(2,HIGH);
    digitalWrite(4,LOW);
    digitalWrite(7,HIGH);
    digitalWrite(8,LOW);
    analogWrite(9,left_motor_speed);    //intial_motor_speed-PID_value
    analogWrite(10,right_motor_speed);    //intial_motor_speed+PID_value
    }
    
    //------------------------------------------------------------------------------------------------------------------------------------------------------------------
  
    
    //-------------------------------------------------------------------------------------------------------------------------------------------------------------------
    
    
     else if((sensor[0]==0)&&(sensor[1]==0)&&(sensor[2]==0)&&(sensor[3]==0)&&(sensor[4]==0)&&(sensor[5]==0))   // 0 0 0 0 0 0
    {
    digitalWrite(2,HIGH);
    digitalWrite(4,LOW);
    digitalWrite(7,HIGH);
    digitalWrite(8,LOW);
    analogWrite(9,110);    //180 DEGREE RIGHT TURN
    analogWrite(10,110);
    delay(1060);
    
    }
    
    /*else if((sensor[0]==1)&&(sensor[1]==1)&&(sensor[2]==1)&&(sensor[3]==1)&&(sensor[4]==1)&&(sensor[5]==1))  // 1 1 1 1 1 1
    {
    digitalWrite(2,HIGH);
    digitalWrite(4,LOW);
    digitalWrite(7,LOW);
    digitalWrite(8,HIGH);
    analogWrite(9,left_motor_speed);    //intial_motor_speed-PID_value
    analogWrite(10,right_motor_speed);    //intial_motor_speed+PID_value
    }*/
    
   else
   {
   digitalWrite(2,HIGH);
   digitalWrite(4,LOW);
   digitalWrite(7,LOW);
   digitalWrite(8,HIGH);
   analogWrite(9,110);    //intial_motor_speed-PID_value
   analogWrite(10,110);    //intial_motor_speed+PID_value
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
