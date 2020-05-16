

/*
halt
ch1=1500
ch2=1500

fwd 
ch1 =1500
ch2 =1870 (max)

bck
ch1=1500  f 
ch2=1085(min)

left
ch1=1952(max)
ch2=1500

right
ch1=1075(min)
ch2=1500

*/

int cha1=A0;
int cha2=A1;
int cha3=A2;
int cha4=A3;

int channel_1;
int channel_2;
int channel_3;
int channel_4;

void setup() 
{
  
  pinMode(cha1,INPUT);
  pinMode(cha2,INPUT);
  pinMode(cha3,INPUT);
  pinMode(cha4,INPUT);
  Serial.begin(9600);
  Serial.println("Ready \n");
}
void loop() 
{
  // put your main code here, to run repeatedly:
channel_1 =(pulseIn(cha1,HIGH));
channel_2 =(pulseIn(cha2,HIGH));
channel_3 =(pulseIn(cha3,HIGH));
channel_4 =(pulseIn(cha4,HIGH));
Serial.print("Channel 1 is = ");
Serial.println(channel_1);


Serial.print("Channel 2 is = ");
Serial.println(channel_2);

Serial.print("Channel 3 is = ");
Serial.println(channel_3);


Serial.print("Channel 4 is = ");
Serial.println(channel_4);

delay(1000);

}
