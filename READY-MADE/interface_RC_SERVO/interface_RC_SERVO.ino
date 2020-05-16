#include <Servo.h>

Servo steer;  // create servo object to control a servo 
                // twelve servo objects can be created on most boards
 
int pos = 0;    // variable to store the servo position

int cha1=13;
int cha2=12;


int channel_1;
int channel_2;
void setup() 
{
  pinMode(cha1,INPUT);
  pinMode(cha2,INPUT);
  pinMode(9,OUTPUT);
  pinMode(13,INPUT);
  Serial.begin(9600);
  Serial.println("Ready \n");
  digitalWrite(10,LOW);
  steer.attach(9);  // attaches the servo on pin 9 to the servo object 
}

void loop() 
{
channel_1 =(pulseIn(cha1,HIGH));
Serial.print("Channel 1 is = ");
Serial.println(channel_1);
if((channel_1<1400)&&(channel_1>1080))
{
  pos = map(channel_1, 1080, 1400, 0,90);    // scale it to use it with the servo (value between 0 and 180) 
}

else if((channel_1>1400)&&(channel_1<1500))
{
  pos=90;
  Serial.println("I m in straight");
}

else if((channel_1>1500)&&(channel_1<1870))
{
  pos = map(channel_1, 1500, 1870, 90, 180);     // scale it to use it with the servo (value between 0 and 180)

  Serial.println("I m in RIGHT"); //  myservo.write(pos);                         // sets the servo position according to the scaled value   
}

else pos=0;

steer.write(pos);
Serial.println(pos);
//delay(1000);
}
