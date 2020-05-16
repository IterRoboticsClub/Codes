int lPin1 = 2;
int lPin2 = 4;
int rPin1 = 7;
int rPin2 = 8;
int pwm1=9;
int pwm2=10;
int sensors[] = {0, 0, 0 ,0, 0};
int threshold=700;
int x=1,y=1;
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
for (int i=0 ; i < 5; i++)
  {
    sensors[i] = analogRead(i);
  }
}

void grid()
{
   
      if((surface[0]==1)&&(surface[1]==1)&&(surface[2]==1)&&(surface[3]==1)&&(surface[4]==1))  // WHITE-WHITE-WHITE-WHITE-WHITE
      {
       if(y<6)
         {       
          x++;
          if(x=1)
            {
              if(y%2==0)
              {
                rotate_right();
              }
              else if(y%2==1)
              {
                rotate_left();
              }
              Serial.println("Line fully chaged");
           }			//end of if
       
	  else if(x<5)
            {
             straight();
             Serial.println("NODE");
            }
           
          else if(x>=5) 
            {
             if(y%2==1)
               {
                rotate_right();
               }
             else if(y%2==0)
               {  
                rotate_left();
               }
              x=10;
              y++;
              Serial.println("Changing the line");
           }			//end of else if
      	 }			//end of if
        
	else if(y>=5)
	{
		halt();
                Serial.println("HALT");
	}
     }				//end of node condition
      else if(surface[0]==0)&&(surface[1]==0)&&(surface[2]==1)&&(surface[3]==0)&&(surface[4]==0))
      {
	if(y<5)
        {
	 straight();
         Serial.println("ST");
       }
	
	else if(y>=5)
	{
		halt();
		Serial.println("HALT");
	}
      
      }			//end of if condition 

}		        //end of straight condition
}	                //end of grid   
        
  void straight()
{
   digitalWrite(2,HIGH);
   digitalWrite(4,LOW);
   digitalWrite(7,LOW);    //FOR STRAIGHT
   digitalWrite(8,HIGH);
   analogWrite(9,100);
   analogWrite(10,100);
}

void rotate_right()
{
   digitalWrite(2,HIGH);
   digitalWrite(4,LOW);
   digitalWrite(7,HIGH);  //FOR RIGHT
   digitalWrite(8,LOW);
   analogWrite(9,100);
   analogWrite(10,100);
   delay(1000);
}

void rotate_left()
{
   digitalWrite(2,LOW);
   digitalWrite(4,HIGH);
   digitalWrite(7,LOW);  //FOR LEFT
   digitalWrite(8,HIGH);
   analogWrite(9,100);
   analogWrite(10,100);
   delay(1000);
}

void halt()
{
   digitalWrite(2,LOW);
   digitalWrite(4,LOW);
   digitalWrite(7,LOW);  //FOR HALT
   digitalWrite(8,LOW);
   analogWrite(9,0);
   analogWrite(10,0);
   delay(3000);
}

