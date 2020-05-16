
int led1=9;
int led2=10;
int val;

void setup() 
{
pinMode(9,OUTPUT);
pinMode(10,OUTPUT);
Serial.begin(9600);
}

void loop() 
{
Serial.println("Press \n1 To blink red \n2 To fade red \n3. To blink Yellow \n4. To Fade Red\n ");
while(!Serial.available());
val = Serial.read();
if( val== '1')
{
  digitalWrite(led1,HIGH);
  digitalWrite(led2,LOW);
  delay(100);
  digitalWrite(led1,LOW);
  digitalWrite(led2,LOW);
  delay(100);
}

else if( val=='2')
{
  for(int i=0;i<255;i+=5)
  {
    analogWrite(led1,i);
    analogWrite(led2,0);
    delay(70);
  }
  for(int i=255;i>=0;i -=5)
  {
    analogWrite(led1,i);
    analogWrite(led2,0);
    delay(70);
  }
}

else if( val== '3')
{
  digitalWrite(led2,HIGH);
  digitalWrite(led1,LOW);
  delay(100);
  digitalWrite(led2,LOW);
  digitalWrite(led1,LOW);
  delay(100);
}

else if(val == '4')
{
  for(int i=0;i<=255;i+=5)
  {
      analogWrite(led2,i);
      analogWrite(led1,0);
      delay(70);
  }
  
  for(int i=255 ;i >=0;i-=5)
  {
      analogWrite(led2,i);
      analogWrite(led1,0);
      delay(70);
  }
}

else
{
  digitalWrite(led1,LOW);
  digitalWrite(led2,LOW);
}
}
