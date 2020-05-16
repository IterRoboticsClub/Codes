int lPin1 = 2;
int lPin2 = 4;
int rPin1 = 7;
int rPin2 = 8;
int pwm1=9;
int pwm2=10;
long sensors[] = {0, 0, 0};
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
  sensors[i] = digitalRead(i);
}

void forward()
{
      digitalWrite(2,HIGH);
      digitalWrite(4,LOW);
      digitalWrite(7,LOW);
      digitalWrite(8,HIGH);
      analogWrite(9,100);
      analogWrite(10,100);
      
}

void left()
{
      digitalWrite(2,LOW);
      digitalWrite(4,LOW);
      digitalWrite(7,LOW);
      digitalWrite(8,HIGH);
      analogWrite(10,100);
}

void right()
{
      digitalWrite(2,HIGH);
      digitalWrite(4,LOW);
      digitalWrite(7,LOW);
      digitalWrite(8,LOW);
      analogWrite(9,100);
}
void halt()
{
    digitalWrite(2,HIGH);
    digitalWrite(4,LOW);
    digitalWrite(7,LOW);
    digitalWrite(8,LOW);
}

void reverse()
{
      digitalWrite(2,LOW);
      digitalWrite(4,HIGH);
      digitalWrite(7,HIGH);
      digitalWrite(8,LOW);
}

void follow()
{
   if((sensors[0]==1)&&(sensors[1]==0)&&(sensors[2]==1))  //WHITE-BLACK-WHITE
    {
      forward();
    }
    
    else if((sensors[0]==0)&&(sensors[1]==1)&&(sensors[2]==1))  //BLACK-WHITE-WHITE
    {
       left();  
    }
       
    else if((sensors[0]==1)&&(sensors[1]==1)&&(sensors[2]==0))  //WHITE-WHITE-BLACK
    {
      right();
    } 
    
    else
    halt();
}
