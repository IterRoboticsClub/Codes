int lPin1 = 2;
int lPin2 = 4;
int rPin1 = 7;
int rPin2 = 8;
int pwm1=9;
int pwm2=10;
int sensors[] = {0, 0, 0};
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

void follow()
{
   start:
   if((sensors[0]>970)&&(sensors[1]<970)&&(sensors[4]<970)&&(sensors[2]>970))
    {
    digitalWrite(2,HIGH);
    digitalWrite(4,LOW);
    digitalWrite(7,LOW);
    digitalWrite(8,HIGH);
    }
    
    else if((sensors[0]<970)&&(sensors[1]>970)&&(sensors[4]>970)&&(sensors[2]>970))
    {
       digitalWrite(2,LOW);
    digitalWrite(4,LOW);
    digitalWrite(7,LOW);
    digitalWrite(8,HIGH);
    
    }
       
    else if((sensors[0]>970)&&(sensors[1]>970)&&(sensors[4]>970)&&(sensors[3]<970))
    {
    digitalWrite(2,HIGH);
    digitalWrite(4,LOW);
    digitalWrite(7,LOW);
    digitalWrite(8,LOW);
    } 
    
    else if((sensors[0]<970)&&(sensors[1]<970)&&(sensors[4]<970)&&(sensors[2]<970))
    {
    digitalWrite(2,HIGH);
    digitalWrite(4,LOW);
    digitalWrite(7,LOW);
    digitalWrite(8,HIGH);
    }
    
    else if((sensors[0]<970)&&(sensors[1]<970)&&(sensors[4]>970)&&(sensors[2]<970))
    {
    digitalWrite(2,HIGH);
    digitalWrite(4,LOW);
    digitalWrite(7,LOW);
    digitalWrite(8,LOW);
    delay(500);
    }
    
    else
    {
    digitalWrite(2,HIGH);
    digitalWrite(4,LOW);
    digitalWrite(7,LOW);
    digitalWrite(8,HIGH);
    
    }
}
