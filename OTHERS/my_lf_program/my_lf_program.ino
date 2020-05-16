int lPin1 = 2;
int lPin2 = 4;
int rPin1 = 7;
int rPin2 = 8;
int pwm1=9;
int pwm2=10;
int sensors[] = {0, 0, 0};
int surface[] = {0, 0, 0};
int threshold=700;
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
  {sensors[i] = analogRead(i);
  
  if(sensors[i]<threshold)
  {
    surface[i]=0;
  }
  else if(sensors[i]>threshold)
  {
    surface[i]=1;
  }
  }
}
void follow()
{
   start:
   if((surface[0]==1)&&(surface[1]==0)&&(surface[2]==1))    //WHITE-BLACK-WHITE
    {
    digitalWrite(2,HIGH);
    digitalWrite(4,LOW);
    digitalWrite(7,LOW);    //FOR STRAIGHT
    digitalWrite(8,HIGH);
    }
    
    else if((surface[0]==0)&&(surface[1]==1)&&(surface[2]==1))    //BLACK-WHITE-WHITE
    {
    digitalWrite(2,LOW);
    digitalWrite(4,LOW);
    digitalWrite(7,LOW);  //FOR LEFT
    digitalWrite(8,HIGH);
    
    }
       
    else if((sensors[0]==1)&&(sensors[1]==1)&&(surface[2]==0))    //WHITE-WHITE-BLACK
    {
    digitalWrite(2,HIGH);
    digitalWrite(4,LOW);
    digitalWrite(7,LOW);  //FOR RIGHT
    digitalWrite(8,LOW);
    } 
    
    else
    {
    digitalWrite(2,HIGH);
    digitalWrite(4,LOW);      //FOR GAP
    digitalWrite(7,LOW);
    digitalWrite(8,HIGH);
    
    }
}

