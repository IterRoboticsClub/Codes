//int motorsPinEnable = 7;
int i=0,k=0,m=0;

void initAll(){
  /*** Hardware initialization ***/
  Serial.begin(9600);
  //for(int i = 0; i < 5; i++){
   // pinMode(lineArray[i], INPUT);
  }
  
void setup()
{  
        initAll();
	//pinMode(motorsPinEnable, OUTPUT);
	//digitalWrite(motorsPinEnable,HIGH);
	DDRC = 0x00;
	DDRD = 0xFF;
}
void loop()
{
    while(1)
    {
        i = PINC;
	k = i & 0xFF;
        Serial.print("i=");
        Serial.print(i);
        Serial.print("k=");
        Serial.print(k);
        delay(1500);
    }
}

