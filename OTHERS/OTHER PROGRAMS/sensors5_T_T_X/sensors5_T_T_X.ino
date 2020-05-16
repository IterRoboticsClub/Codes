int lPin1 = 2;
int lPin2 = 4;
int rPin1 = 7;
int rPin2 = 8;
long sensors[] = {0, 0, 0, 0, 0};
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
for (int i = 0; i < 4; i++)
  sensors[i] = analogRead(i);
}

void forward()
{
      digitalWrite(2,HIGH);
      digitalWrite(4,LOW);
      digitalWrite(7,LOW);
      digitalWrite(8,HIGH);
      
}

void left()
{
      digitalWrite(2,LOW);
      digitalWrite(4,LOW);
      digitalWrite(7,LOW);
      digitalWrite(8,HIGH);
      digitalWrite(9,240);
      digitalWrite(10,240);
}

void right()
{
      digitalWrite(2,HIGH);
      digitalWrite(4,LOW);
      digitalWrite(7,LOW);
      digitalWrite(8,LOW);
      digitalWrite(9,240);
      digitalWrite(10,240);
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
   start:
   if((sensor[0]>700)&&(sensor[1]>700)&&(sensor[2]<700)&&(sensor[3]>700)&&(sensor[4]>700))
    {
      forward();
    }
    
    else if((sensor[0]>700)&&(sensor[1]<700)&&(sensor[2]<700)&&(sensor[3]>700)&&(sensor[4]>700))    //Plz Check this    //white,black,black,white,white
    {
      left();
      
    }
    else if((sensor[0]<700)&&(sensor[1]<700)&&(sensor[2]>700)&&(sensor[3]>700)&&(sensor[4]>700))    //Black,black,white,white,white
    {
      left();
    }
    
    else if((sensor[0]<700)&&(sensor[1]<700)&&(sensor[2]<700)&&(sensor[3]>700)&&(sensor[4]>700))    //Black,Black,Black,white,white(for 90 left)
    {
      left();  //Plz insert another fn for 90 degree rotation
    }
    
    else if((sensors[0]>700)&&(sensors[1]>700)&&(sensors[2]>700)&&(sensors[3]>700)&&(sensors[4]<700))    //White,white,white,white,Black
    {  
      
       right();
    }
       
    else if((sensors[0]>700)&&(sensors[1]>700)&&(sensors[2]>700)&&(sensors[3]<700)&&(sensors)[4]<700))      //White,White,White,Black,Black
    {
      
      right();
    } 
    
    else if((sensors[0]>700)&&(sensors[1]>700)&&(sensors[2]<700)&&(sensors[3]<700)&&(sensors[4]<700))      //White,White,black,Black,Black(90 right)
    {
      right();
    }    
    /*else if((sensors[0]<700)&&(sensors[1]<700)&&(sensors[2]<700))
    {
      forward();
    
      if((sensors[0]>700)&&(sensors[1]<700)&&(sensors[2]>700))
        {follow();}
     
      reverse();
      follow();
  
     }*/
   /*else if((sensors[0]>700)&&(sensors[1]>700)&&(sensors[2]>700))
     reverse();*/
    else
     forward();
}
