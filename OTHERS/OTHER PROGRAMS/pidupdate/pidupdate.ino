long sensors_average=0;
long sensors_sum=0;
int pos=0;
int error_value=0;
long sensors[] = {0, 0, 0, 0, 0}; // Array used to store 5 readings for 5 sensors.
int set_point=2030;
int proportional=0;
int max_speed=240;
int Kp=10, Ki=0, Kd=0;
int lPin1 = 2;
int lPin2 = 4;
int leftPWM = 9;
int rPin1 = 7;
int rPin2 = 8;
int rightPWM = 10;
int last_proportional=0,derivative=0,integral=0;
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
  sensors_read();
  pid_calc();
  calc_turn();
   
}

void sensors_read()
{ 
sensors_average = 0;
sensors_sum = 0;
for (int i = 0; i < 5; i++)
{
sensors[i] = analogRead(i);
sensors_average += sensors[i] * i * 1000; //Calculating the weighted mean
sensors_sum += sensors[i];//Calculating sum of sensor readings
} 
}

void pid_calc()
{ 

pos = int(sensors_average/sensors_sum);
proportional=pos-set_point; // Replace set_point by your set point
integral = integral + proportional;
derivative = proportional - last_proportional;
last_proportional = proportional;
error_value = int(proportional * Kp + integral * Ki + derivative * Kd);

}

void calc_turn()
{ //Restricting the error value between +256.
int left_speed;
int right_speed;
if (error_value< -256)
{
error_value = -256;
}
if (error_value> 256)
{
error_value = 256;
}
// If error_value is less than zero calculate right turn speed values
if (error_value< 0)
{
right_speed = max_speed + error_value;
left_speed = max_speed;
}
// Iferror_value is greater than zero calculate left turn values
else
{
right_speed = max_speed;
left_speed = max_speed - error_value;
}

follow(left_speed,right_speed);    
}

void follow(int left, int right)
{
   if((sensors[0]>640)&&(sensors[1]>640)&&(sensors[2]<640)&&(sensors[3]>640)&&(sensors[4]>640))
    {
    digitalWrite(2,HIGH);
    digitalWrite(4,LOW);
    digitalWrite(7,LOW);
    digitalWrite(8,HIGH);
    analogWrite(9,left);   //Left Motor Speed
    analogWrite(10,right);
    }
    
    else if((sensors[0]>640)&&(sensors[1]<640)&&(sensors[2]>640)&&(sensors[3]>640)&&(sensors[4]>640))
    {
    digitalWrite(2,HIGH);
    digitalWrite(4,LOW);
    digitalWrite(7,LOW);
    digitalWrite(8,LOW);
    analogWrite(9,left);   //Left Motor Speed
    analogWrite(10,right);
    }
    
    else if((sensors[0]<640)&&(sensors[1]>640)&&(sensors[2]>640)&&(sensors[3]>640)&&(sensors[4]>640))
    {
    digitalWrite(2,HIGH);
    digitalWrite(4,LOW);
    digitalWrite(7,LOW);
    digitalWrite(8,LOW);
    analogWrite(9,left);   //Left Motor Speed
    analogWrite(10,right);
    }
    
    else if((sensors[0]<640)&&(sensors[1]<640)&&(sensors[2]>640)&&(sensors[3]>640)&&(sensors[4]>640))
    {
    digitalWrite(2,HIGH);
    digitalWrite(4,LOW);
    digitalWrite(7,LOW);
    digitalWrite(8,LOW);
    analogWrite(9,left);   //Left Motor Speed
    analogWrite(10,right);
    }
    
    else if((sensors[0]>640)&&(sensors[1]>640)&&(sensors[2]>640)&&(sensors[3]<640)&&(sensors[4]>640))
    {
    digitalWrite(2,LOW);
    digitalWrite(4,LOW);
    digitalWrite(7,LOW);
    digitalWrite(8,HIGH);
    analogWrite(9,left);   //Left Motor Speed
    analogWrite(10,right);
    }
    
    else if((sensors[0]>640)&&(sensors[1]>640)&&(sensors[2]>640)&&(sensors[3]>640)&&(sensors[4]<640))
    {
    digitalWrite(2,LOW);
    digitalWrite(4,LOW);
    digitalWrite(7,LOW);
    digitalWrite(8,HIGH);
    analogWrite(9,left);   //Left Motor Speed
    analogWrite(10,right);
    }
    
    else if((sensors[0]>640)&&(sensors[1]>640)&&(sensors[2]>640)&&(sensors[3]<640)&&(sensors[4]<640))
    {
    digitalWrite(2,LOW);
    digitalWrite(4,LOW);
    digitalWrite(7,LOW);
    digitalWrite(8,HIGH);
    analogWrite(9,left);   //Left Motor Speed
    analogWrite(10,right);
    }
    
    else if((sensors[0]>640)&&(sensors[1]>640)&&(sensors[2]>640)&&(sensors[3]>640)&&(sensors[4]>640640))
    {
    digitalWrite(2,HIGH);
    digitalWrite(4,LOW);
    digitalWrite(7,LOW);
    digitalWrite(8,HIGH);
    analogWrite(9,left);   //Left Motor Speed
    analogWrite(10,right);
    }
    
    else if((sensors[0]<640)&&(sensors[1]<640)&&(sensors[2]<640)&&(sensors[3]<640)&&(sensors[4]<640))
    {
    digitalWrite(2,HIGH);
    digitalWrite(4,LOW);
    digitalWrite(7,LOW);
    digitalWrite(8,HIGH);
    analogWrite(9,left);   //Left Motor Speed
    analogWrite(10,right);
    }
    
    else
    {
    digitalWrite(2,HIGH);
    digitalWrite(4,LOW);
    digitalWrite(7,LOW);
    digitalWrite(8,HIGH);
    analogWrite(9,left);   //Left Motor Speed
    analogWrite(10,right);
    }
}


// Saturates between -mmax and +mmax
int saturate(int val, int mmax){
  if(val > mmax) return mmax;
  if(val < -mmax) return -mmax;
  else return val;
} 
