int lPin1 = 2;
int lPin2 = 4;
int rPin1 = 7;
int rPin2 = 8;
int pwm1=9;
int pwm2=10;
int sensors[] = {0, 0, 0};
int surface[] = {0, 0, 0};
int threshold=700;
int x=0,y=0;
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
  grid();
   
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

void grid()
{
  if((x==0)&&(y!=0))
  {
    straight();
    if(y!=0)
    {
      if((surface[0]==1)&&(surface[1]==1)&&(surface[2]==0)&&(surface[3]==0)&&(surface[4]==0))
      {
        straight();
        y--;
      }
    }
  }
  
  else if((x!=0)&&(y==0))
  {
    right();
    straight();
     if(x!=0)
    {
     if((surface[0]==1)&&(surface[1]==1)&&(surface[2]==0)&&(surface[3]==0)&&(surface[4]==0))
    {
     straight();
     x--; 
    }
    }
  }
  else if((x!=0)&&(y!=0))
  { 
    if((surface[0]==1)&&(surface[1]==1)&&(surface[2]==0)&&(surface[3]==1)&&(surface[4]==1))
  {
    straight();
  }
    else if((surface[0]==1)&&(surface[1]==1)&&(surface[2]==0)&&(surface[3]==0)&&(surface[4]==0))
  {
    right();
  }
    else if((surface[0]==0)&&(surface[1]==0)&&(surface[2]==0)&&(surface[3]==1)&&(surface[4]==1))
  {
    left();
  }
    else if((surface[0]==0)&&(surface[1]==0)&&(surface[2]==0)&&(surface[3]==0)&&(surface[4]==0))
  {
    x--;
    y--;
    follow();
  }
  
   else if(surface[2]!=0)
  {
    if(surface[1]==0)
    {
      right();
    }
    else if(surface[3]==0)
    {
      left();
    }
  }
}
void follow()
{
    if(x>y)
      {
       if(y!=0)
          {
            straight();
          }
        else if(y==0)
          {
            right();
            straight();
            if(x==0)
            {
              halt();
            }
            else if(x!=0)
            {
              straight();
            }
          }
       }
    else if(x<y)
        {  
          if(x!=0)
            {
              right();
              straight();
            }
          else if(x==0)
            {
              straight();        
            }
          }
  }
  void straight()
{
   digitalWrite(2,HIGH);
   digitalWrite(4,LOW);
   digitalWrite(7,LOW);    //FOR STRAIGHT
   digitalWrite(8,HIGH);
   analogWrite(9,100);
   analogWrite(10,100);
}

void right()
{
   digitalWrite(2,HIGH);
   digitalWrite(4,LOW);
   digitalWrite(7,HIGH);  //FOR RIGHT
   digitalWrite(8,LOW);
   analogWrite(9,100);
   analogWrite(10,100);
   delay(1000);
}

void left()
{
   digitalWrite(2,LOW);
   digitalWrite(4,HIGH);
   digitalWrite(7,LOW);  //FOR LEFT
   digitalWrite(8,HIGH);
   analogWrite(9,100);
   analogWrite(10,100);
   delay(1000);
}
