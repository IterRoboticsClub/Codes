
int sensors[] = {0, 0, 0};
int s=100;


void setup()
{
 
 pinMode(6,OUTPUT); //Left Motor Pin 1
 pinMode(7,OUTPUT); //Left Motor Pin 2
 pinMode(9,OUTPUT); //Right Motor Pin 1
 pinMode(10,OUTPUT);  //Right Motor Pin 2
 pinMode(A0,INPUT);
 pinMode(A1,INPUT);
 pinMode(A2,INPUT);
 pinMode(A5,OUTPUT);
 digitalWrite(A5,HIGH);
 Serial.begin(9600); //Enable Serial Communications

}

void loop()
{
  sensors_read();
  follow();  
}

void sensors_read()
{
  
  sensors[0] = digitalRead(A0);
  sensors[1]=digitalRead(A1);
  sensors[2]=digitalRead(A2);
  Serial.println("left= ");
  Serial.print(sensors[0]);
   Serial.println("middle= ");
  Serial.print(sensors[1]);
   Serial.println("right= ");
  Serial.print(sensors[2]);
}

void straight()
{
   Serial.println("S");
  analogWrite(6,s);
  analogWrite(7,0);
  analogWrite(9,0); 
  analogWrite(10,s);
  delay(100);
 
}

void left()
{
   Serial.println("L");
    analogWrite(6,0);
    analogWrite(7,s);
    analogWrite(9,0);
    analogWrite(10,s);
    delay(100);
    
}

void right()
{
    analogWrite(6,s);
    analogWrite(7,0);
    analogWrite(9,s);  
    analogWrite(10,0);
    delay(100);
}

void halt()
{
 analogWrite(6,0);
 analogWrite(7,0);
 analogWrite(9,0);  
 analogWrite(10,0);
 Serial.println("H");
}
  
void follow()
{

   if((sensors[0]==1)&&(sensors[1]==0)&&(sensors[2]==1))     //WHITE-BLACK-WHITE 
    {
      straight();
    }
    
    else if((sensors[0]==0)&&(sensors[1]==1)&&(sensors[2]==1))    //BLACK-WHITE-WHITE
    {
      right();
    }
       
    else if((sensors[0]==1)&&(sensors[1]==1)&&(sensors[2]==0))    //WHITE-WHITE-BLACK
    {
      left();
    } 
    
    else
    {
      straight();
      halt();
    }
}

