int lPin1 = 2;
int lPin2 = 4;
int rPin1 = 7;
int rPin2 = 8;
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
  sensors[i] = analogRead(i);
}

void forward()
{
      digitalWrite(2,HIGH);
      digitalWrite(4,LOW);
      digitalWrite(7,LOW);
      digitalWrite(8,HIGH);
      Serial.println("f");
      
}

void left()
{
      digitalWrite(2,LOW);
      digitalWrite(4,LOW);
      digitalWrite(7,LOW);
      digitalWrite(8,HIGH);
      Serial.println("l");
}

void right()
{
      digitalWrite(2,HIGH);
      digitalWrite(4,LOW);
      digitalWrite(7,LOW);
      digitalWrite(8,LOW);
      Serial.println("R");
}
void halt()
{
    digitalWrite(2,HIGH);
    digitalWrite(4,LOW);
    digitalWrite(7,LOW);
    digitalWrite(8,LOW);
    Serial.println("H");
}

void reverse()
{
      digitalWrite(2,LOW);
      digitalWrite(4,HIGH);
      digitalWrite(7,HIGH);
      digitalWrite(8,LOW);
      Serial.println("Rev");
}

void follow()
{
   if((sensors[0]>600)&&(sensors[1]<600)&&(sensors[2]>600))  //WHITE-BLACK-WHITE
    {
      forward();
    }
    
    else if((sensors[0]<600)&&(sensors[1]>600)&&(sensors[2]>600))  //BLACK-WHITE-WHITE
    {
       left();  
    }
       
    else if((sensors[0]>600)&&(sensors[1]>600)&&(sensors[3]<600))  //WHITE-WHITE-BLACK
    {
      right();
    } 
    
    else
     halt();
}
