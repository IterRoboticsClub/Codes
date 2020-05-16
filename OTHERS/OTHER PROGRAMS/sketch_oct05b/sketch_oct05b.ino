int lPin1 = 2;
int lPin2 = 4;
int leftPWM = 9;
int rPin1 = 7;
int rPin2 = 8;
int rightPWM = 10;
int left=180;
int right=180;
long sensors[] = {0, 0, 0};
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
  follow();
   
}

void sensors_read()
{ 
for (int i = 0; i < 3; i++)
  sensors[i] = analogRead(i);
}


void follow()
{
   if((sensors[0]<700)&&(sensors[1]>700)&&(sensors[2]<700))//Forward
    {
    digitalWrite(2,HIGH);
    digitalWrite(4,LOW);
    digitalWrite(7,LOW);
    digitalWrite(8,HIGH);
    analogWrite(9,left);   //Left Motor Speed
    analogWrite(10,right);
    }
    
    else if((sensors[0]<700)&&(sensors[1]>700)&&(sensors[2]>700))//Right 90
    {
    digitalWrite(2,HIGH);
    digitalWrite(4,LOW);
    digitalWrite(7,HIGH);
    digitalWrite(8,LOW);
    analogWrite(9,left);   //Left Motor Speed
    analogWrite(10,right);
    delay(100);
    }
    
    else if((sensors[0]<700)&&(sensors[1]<700)&&(sensors[2]>700))//Right 
    {
    digitalWrite(2,HIGH);
    digitalWrite(4,LOW);
    digitalWrite(7,HIGH);
    digitalWrite(8,LOW);
    analogWrite(9,left);   //Left Motor Speed
    analogWrite(10,right);
    //delay();
    }
    
    else if((sensors[0]>700)&&(sensors[1]>700)&&(sensors[2]>700))//Junction
    {
    digitalWrite(2,HIGH);
    digitalWrite(4,LOW);
    digitalWrite(7,HIGH);
    digitalWrite(8,LOW);
    analogWrite(9,left);   //Left Motor Speed
    analogWrite(10,right);
    delay(100);
    }
    
    else if((sensors[0]>700)&&(sensors[1]>700)&&(sensors[2]<700))//Left 90
    {
    digitalWrite(2,LOW);
    digitalWrite(4,HIGH);
    digitalWrite(7,LOW);
    digitalWrite(8,HIGH);
    analogWrite(9,left);   //Left Motor Speed
    analogWrite(10,right);
    delay(100);
    }
    
     else if((sensors[0]>700)&&(sensors[1]<700)&&(sensors[2]<700))//Left 
    {
    digitalWrite(2,LOW);
    digitalWrite(4,HIGH);
    digitalWrite(7,LOW);
    digitalWrite(8,HIGH);
    analogWrite(9,left);   //Left Motor Speed
    analogWrite(10,right);
    //delay(100);
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


 
