int lPin1 = 2;
int lPin2 = 4;
int rPin1 = 7;
int rPin2 = 8;
int pwm1=9;
int pwm2=10;
int sensors[] = {0, 0, 0, 0, 0};
int threshold=600;
int i;

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
  go_to_end();
}

void sensors_read()
{ 
for ( i = 1; i < 6; i++)
  {
    sensors[i] = analogRead(i);
  }

}

void halt()
{ 
  digitalWrite(2,LOW);
  digitalWrite(4,LOW);
  digitalWrite(7,LOW);
  digitalWrite(8,LOW);
  delay(5000);
}

void right()
{
    digitalWrite(2,HIGH);
    digitalWrite(4,LOW);
    digitalWrite(7,LOW);  //FOR RIGHT
    digitalWrite(8,LOW);
    analogWrite(10,100);
    delay(1100);
}

void left()
{
    digitalWrite(2,LOW);
    digitalWrite(4,LOW);
    digitalWrite(7,LOW);  //FOR LEFT
    digitalWrite(8,HIGH);
    analogWrite(9,100);
    delay(1100);
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

void back()
{
  digitalWrite(2,HIGH);
  digitalWrite(4,LOW);
  digitalWrite(7,HIGH);
  digitalWrite(8,LOW);
  analogWrite(9,100);
  analogWrite(10,100);
  delay(1500);
}
 
void go_to_end()
{
  //FOR SIPMLE LINE 
  
  if((sensors[1]>threshold)&&(sensors[2]>threshold)&&(sensors[3]<threshold)&&(sensors[4]>threshold)&&(sensors[5]>threshold))    //WHITE-WHITE-BLACK-WHITE-WHITE
    {
      straight();
      Serial.println("F");
  }
    
    else if((sensors[1]<threshold)&&(sensors[2]<threshold)&&(sensors[3]>threshold)&&(sensors[4]>threshold)&&(sensors[5]>threshold))    //BLACK-BLACK-WHITE-WHITE-WHITE
    {
      left();
      Serial.println("L");
    }
    
    else if((sensors[1]<threshold)&&(sensors[2]<threshold)&&(sensors[3]<threshold)&&(sensors[4]>threshold)&&(sensors[5]>threshold))    //BLACK-BLACK-BLACK-WHITE-WHITE
    {
      left();
      Serial.println("L");
    }
    
    else if((sensors[1]>threshold)&&(sensors[2]>threshold)&&(sensors[3]<threshold)&&(sensors[4]<threshold)&&(sensors[5]<threshold))    //WHITE-WHITE-BLACK-BLACK-BLACK
    {
      right();
      Serial.println("R");
    } 
    
    else if((sensors[1]>threshold)&&(sensors[2]>threshold)&&(sensors[3]>threshold)&&(sensors[4]<threshold)&&(sensors[5]<threshold))    //WHITE-WHITE-WHITE-BLACK-BLACK
    {
      right();
      Serial.println("R");
    }   
  
    else if((sensors[0]<threshold)&&(sensors[1]<threshold)&&(sensors[2]<threshold)&&(sensors[3]<threshold)&&(sensors[4]<threshold)&&(sensors[5]<threshold))    //BLACK-BLACK-BLACK-BLACK-BLACK-BLACK
    {
     halt();
     Serial.println("H");
     }
 }  //END OF FOLLOW FUNCTION
  
  
