int lPin1 = 2;
int lPin2 = 4;
int rPin1 = 7;
int rPin2 = 8;
int pwm1=9;
int pwm2=10;
int threshold=200;
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
  
   if((sensors[0]<threshold)&&(sensors[1]<threshold)&&(sensors[2]>threshold)&&(sensors[3]<threshold)&&(sensors[4]<threshold)) // 1.BLACK-BLACK-WHITE-BLACK-BLACK
    {
      straight();
      Serial.println("STRAIGHT");
    }
    
    else if((sensors[0]<threshold)&&(sensors[1]>threshold)&&(sensors[2]<threshold)&&(sensors[3]<threshold)&&(sensors[4]<threshold))    // 2.BLACK-WHITE-BLACK-BLACK-BLACK
    {
      left();
      Serial.println("L.1");
    }
    
    else if((sensors[0]>threshold)&&(sensors[1]<threshold)&&(sensors[2]<threshold)&&(sensors[3]<threshold)&&(sensors[4]<threshold))    // 3.WHITE-BLACK-BLACK-BLACK-BLACK
    {
      left();  
      Serial.println("L.2");  
    }
       
     else if((sensors[0]>threshold)&&(sensors[1]>threshold)&&(sensors[2]<threshold)&&(sensors[3]<threshold)&&(sensors[4]<threshold))    // 4.WHITE-WHITE-BLACK-BLACK-BLACK
    {
      left();
       Serial.println("L.3");
    }
    
     else if((sensors[0]<threshold)&&(sensors[1]>threshold)&&(sensors[2]>threshold)&&(sensors[3]<threshold)&&(sensors[4]<threshold))    // 5.BLACK-WHITE-WHITE-BLACK-BLACK
    {
      left();
       Serial.println("L.4");
    }
    else if((sensors[0]<threshold)&&(sensors[1]<threshold)&&(sensors[2]<threshold)&&(sensors[3]<threshold)&&(sensors[4]>threshold))    // 6.BLACK-BLACK-BLACK-BLACK-WHITE
    {
      right();
       Serial.println("R.1");
    } 
     else if((sensors[0]<threshold)&&(sensors[1]<threshold)&&(sensors[2]<threshold)&&(sensors[3]>threshold)&&(sensors[4]<threshold))    // 7.BLACK-BLACK-BLACK-WHITE-BLACK
    {
      right();
       Serial.println("R.2");
    }
    
     else if((sensors[0]<threshold)&&(sensors[1]<threshold)&&(sensors[2]<threshold)&&(sensors[3]>threshold)&&(sensors[4]>threshold))    //  8.BLACK-BLACK-BLACK-WHITE-WHITE
    {
      right();
       Serial.println("R.3");
    }
    
     else if((sensors[0]<threshold)&&(sensors[1]<threshold)&&(sensors[2]>threshold)&&(sensors[3]>threshold)&&(sensors[4]<threshold))    // 9.BLACK-BLACK-WHITE-WHITE-BLACK
    {
      right();
       Serial.println("R.4");
    }    
   
     else if((sensors[0]>threshold)&&(sensors[1]>threshold)&&(sensors[2]>threshold)&&(sensors[3]>threshold)&&(sensors[4]>threshold))    // 10.WHITE-WHITE-WHITE-WHITE-WHITE
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
    analogWrite(9,100);
    analogWrite(10,100);
  }
  
  void right()
  {
    digitalWrite(2,HIGH);
    digitalWrite(4,LOW);
    digitalWrite(7,LOW);
    digitalWrite(8,LOW);
    analogWrite(9,90);
  }
   
   void left()
  {
   digitalWrite(2,LOW);
   digitalWrite(4,LOW);
   digitalWrite(7,LOW);
   digitalWrite(8,HIGH);
   analogWrite(10,90);
  }
  
  void halt()
  {
    digitalWrite(2,LOW);
   digitalWrite(4,LOW);
   digitalWrite(7,LOW);
   digitalWrite(8,LOW);
  }
  
