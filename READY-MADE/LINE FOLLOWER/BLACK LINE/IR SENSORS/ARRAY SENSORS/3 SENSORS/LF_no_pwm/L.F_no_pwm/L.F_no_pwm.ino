
long sensors[] = {0, 0, 0};
void setup()
{
 pinMode(A0,INPUT);  //LEFT MOST SENSOR
 pinMode(A1,INPUT);  //MIDDLE SENSOR
 pinMode(A2,INPUT);  //RIGHT MOST SENSOR
 pinMode(2,OUTPUT); //Left Motor Pin 1
 pinMode(4,OUTPUT); //Left Motor Pin 2
 pinMode(7,OUTPUT); //Right Motor Pin 1
 pinMode(8,OUTPUT);  //Right Motor Pin 2
 pinMode(9,OUTPUT);  //LEFT PWM PIN
 pinMode(10,OUTPUT);  //RIGHT PWN PIN
 Serial.begin(9600); //Enable Serial Communications

}

void loop()
{
  sensor[0] = digitalRead(A0);      //left most sensor
  sensor[1] = digitalRead(A1);      //Center Sensor
  sensor[2] = digitalRead(A2);      //Right Most Sensor
  follow();
   
}

 
void forward()
{
      digitalWrite(2,HIGH);
      digitalWrite(4,LOW);
      digitalWrite(7,HIGH);
      digitalWrite(8,LOW;
      analogWrite(9,150);
      analogWrite(10,150);
      delay(500);
      Serial.println("f");
      
}

void left()
{
      digitalWrite(2,LOW);
      digitalWrite(4,HIGH);
      digitalWrite(7,HIGH);
      digitalWrite(8,LOW);
      analogWrite(9,150);
      analogWrite(10,150);
      delay(500);
      Serial.println("l");
}

void right()
{
      digitalWrite(2,HIGH);
      digitalWrite(4,LOW);
      digitalWrite(7,LOW);
      digitalWrite(8,HIGH);
      analogWrite(9,150);
      analogWrite(10,150);
      delay(500);
      Serial.println("R");
}
void halt()
{
      digitalWrite(2,LOW);
      digitalWrite(4,LOW);
      digitalWrite(7,LOW);
      digitalWrite(8,LOW);
      analogWrite(9,0);
      analogWrite(10,0);
      delay(500);
    Serial.println("H");
}

void reverse()
{
      digitalWrite(2,LOW);
      digitalWrite(4,HIGH);
      digitalWrite(7,LOW);
      digitalWrite(8,HIGH);
      analogWrite(9,150);
      analogWrite(10,150);
      delay(500);
      Serial.println("Rev");
}

void follow()
{
   if((sensors[0]==1)&&(sensors[1]==0)&&(sensors[2]==1))  //WHITE-BLACK-WHITE
    {
      forward();
      halt();
    }
    
    else if((sensors[0]=0)&&(sensors[1]==1)&&(sensors[2]==1))  //BLACK-WHITE-WHITE
    {
     left();
     halt();  
    }
       
    else if((sensors[0]==1)&&(sensors[1]==1)&&(sensors[3]==0))  //WHITE-WHITE-BLACK
    {
      right();
      halt();
    } 
  
  else if((sensors[0]==1)&&(sensors[1]==1)&&(sensors[3]==1))  //WHITE-WHITE-WHITE
    {
      halt();
    } 
    else
     forward();
}
