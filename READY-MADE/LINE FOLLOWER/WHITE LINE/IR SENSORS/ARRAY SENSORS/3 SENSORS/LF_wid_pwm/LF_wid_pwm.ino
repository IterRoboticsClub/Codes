int lPin1 = 2;
int lPin2 = 4;
int rPin1 = 7;
int rPin2 = 8;
int pwm1=9;
int pwm2=10;
int sensors[] = {0, 0, 0};
int t=300;
void setup()
{
 
 pinMode(2,OUTPUT); //Left Motor Pin 1
 pinMode(4,OUTPUT); //Left Motor Pin 2
 pinMode(7,OUTPUT); //Right Motor Pin 1
 pinMode(8,OUTPUT);  //Right Motor Pin 2
 Serial.begin(9600); //Enable Serial Communications

}

void loop()
{
  sensors_read();
  follow();  
}

void sensors_read()
{ 
for (int i = 0; i < 3; i++)
  sensors[i] = analogRead(i);
}

void straight()
{
  digitalWrite(2,HIGH);
  digitalWrite(4,LOW);
  digitalWrite(7,LOW); 
  digitalWrite(8,HIGH);
  analogWrite(9,130);
  analogWrite(10,130);
  Serial.println("S");
}

void left()
{
    digitalWrite(2,LOW);
    digitalWrite(4,LOW);
    digitalWrite(7,LOW);
    digitalWrite(8,HIGH);
    analogWrite(10,200);
    Serial.println("L");
}

void right()
{
    digitalWrite(2,HIGH);
    digitalWrite(4,LOW);
    digitalWrite(7,LOW);  
    digitalWrite(8,LOW);
    analogWrite(9,200);
    Serial.println("R");
}

void halt()
{
 digitalWrite(2,LOW);
 digitalWrite(4,LOW);
 digitalWrite(7,LOW);  
 digitalWrite(8,LOW);
 Serial.println("H");
}
  
void follow()
{
   start:
   if((sensors[0]>t)&&(sensors[1]<t)&&(sensors[2]>t))     //WHITE-BLACK-WHITE 
    {
      straight();
    }
    
    else if((sensors[0]<t)&&(sensors[1]>t)&&(sensors[2]>t))    //BLACK-WHITE-WHITE
    {
      left();
    }
       
    else if((sensors[0]>t)&&(sensors[1]>t)&&(sensors[2]<t))    //WHITE-WHITE-BLACK
    {
      right();
    } 
    
    else
    {
      straight();
    }
}

