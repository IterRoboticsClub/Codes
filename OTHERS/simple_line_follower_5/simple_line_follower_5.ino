int lPin1 = 2;
int lPin2 = 4;
int rPin1 = 7;
int rPin2 = 8;
int pwm1=9;
int pwm2=10;
int sensors[] = {0, 0, 0, 0, 0};
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
for (int i = 0; i < 5; i++)
  sensors[i] = analogRead(i);
}

void follow()
{
  
   if((sensors[0]>90)&&(sensors[1]>110)&&(sensors[2]<600)&&(sensors[3]>400)&&(sensors[4]>190)) // 1.WHITE-WHITE-BLACK-WHITE-WHITE
    {
      straight();
      Serial.println("STRAIGHT");
    }
    
    else if((sensors[0]>90)&&(sensors[1]<110)&&(sensors[2]>600)&&(sensors[3]>400)&&(sensors[4]>190))    // 2.WHITE-BLACK-WHITE-WHITE-WHITE
    {
      left();
      Serial.println("L.1");
    }
    
    else if((sensors[0]<90)&&(sensors[1]>110)&&(sensors[2]>600)&&(sensors[3]>400)&&(sensors[4]>190))    // 3.BLACK-WHITE-WHITE-WHITE-WHITE
    {
      left();  
      Serial.println("L.2");  
    }
       
     else if((sensors[0]<90)&&(sensors[1]>110)&&(sensors[2]>600)&&(sensors[3]>400)&&(sensors[4]>190))    // 4.BLACK-BLACK-WHITE-WHITE-WHITE
    {
      left();
       Serial.println("L.3");
    }
    
     else if((sensors[0]<90)&&(sensors[1]>110)&&(sensors[2]>600)&&(sensors[3]>400)&&(sensors[4]>190))    // 5.WHITE-BLACK-BLACK-WHITE-WHITE
    {
      left();
       Serial.println("L.4");
    }
    else if((sensors[0]>90)&&(sensors[1]>110)&&(sensors[2]>600)&&(sensors[3]>400)&&(sensors[4]<190))    // 6.WHITE-WHITE-WHITE-WHITE-BLACK
    {
      right();
       Serial.println("R.1");
    } 
     else if((sensors[0]>90)&&(sensors[1]>110)&&(sensors[2]>600)&&(sensors[3]<400)&&(sensors[4]>190))    // 7.WHITE-WHITE-WHITE-BLACK-WHITE
    {
      right();
       Serial.println("R.2");
    }
    
     else if((sensors[0]>90)&&(sensors[1]>110)&&(sensors[2]>600)&&(sensors[3]<400)&&(sensors[4]<190))    //  8.WHITE-WHITE-WHITE-BLACK-BLACK
    {
      right();
       Serial.println("R.3");
    }
    
     else if((sensors[0]>90)&&(sensors[1]>110)&&(sensors[2]<600)&&(sensors[3]<400)&&(sensors[4]>190))    // 9.WHITE-WHITE-BLACK-BLACK-WHITE
    {
      right();
       Serial.println("R.4");
    }DD 
    
   
     else if((sensors[0]<90)&&(sensors[1]<110)&&(sensors[2]<600)&&(sensors[3]<400)&&(sensors[4]<190))    // 10.BLACK-BLACK-BLACK-BLACK-BLACK
    {
      halt();
      Serial.println("HALT");
    }
    
    else 
    {
    straight();
    Serial.println("ELSE_STRAIGHT");
    }  
}

  void straight()
  {
    digitalWrite(2,HIGH);
    digitalWrite(4,LOW);
    digitalWrite(7,LOW);
    digitalWrite(8,HIGH);
    analogWrite(9,80);
    analogWrite(10,80);
  }
  
  void right()
  {
    digitalWrite(2,HIGH);
    digitalWrite(4,LOW);
    digitalWrite(7,LOW);
    digitalWrite(8,LOW);
    analogWrite(9,100);
  }
   
   void left()
  {
   digitalWrite(2,LOW);
   digitalWrite(4,LOW);
   digitalWrite(7,LOW);
   digitalWrite(8,HIGH);
   analogWrite(10,100);
  }
  
  void halt()
  {
    digitalWrite(2,LOW);
   digitalWrite(4,LOW);
   digitalWrite(7,LOW);
   digitalWrite(8,LOW);
  }
  
