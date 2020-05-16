int lPin1 = 2;
int lPin2 = 4;
int rPin1 = 7;
int rPin2 = 8;
int pwm1=9;
int pwm2=10;
int sensors[]={0};
int surface[]={0};
int c;
int threshold=0;
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
  gap();
  delay(5000);
}

void sensors_read()
{
  sensors[0]=analogRead(0);
if(sensors[0]<threshold)
{
  surface[0]=0;
}
else if(sensors[0]>threshold)
{
  surface[0]=1;
}
}

void gap()
{
  for(c=0;surface[0]!=0;c++)
  {
  digitalWrite(2,HIGH);
  digitalWrite(4,LOW);
  digitalWrite(7,LOW);
  digitalWrite(8,HIGH);
  }
}

