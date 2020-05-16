int motor1Pin1 = 2;
int motor1Pin2 = 4;
int motor2Pin1 = 7;
int motor2Pin2 = 8;
int pwm1=9;
int pwm2=10;
int i=0,k=0,m=0;
  
void setup()
{  
        Serial.begin(9600);
	pinMode(motor1Pin1, OUTPUT);
	pinMode(motor1Pin2, OUTPUT);
	pinMode(motor2Pin1, OUTPUT);
	pinMode(motor2Pin2, OUTPUT);
        pinMode(pwm1, OUTPUT);
	pinMode(pwm2, OUTPUT);
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
	if(m != k) {
		switch (k) {
		case 0x02: {
			forward();
			m=k;
			continue;
                        break;
		}
		
		case 0x04: {
			left();
			m=k;
			continue;
                        break;
		}
                case 0x05:{
                            stop1();
                            m=k;
                            continue;
                            break;
                }
		case 0x06: {
			right();
			m=k;
			continue;
                        break;
		}
                case 0x08: {
			backward();
			m=k;
			continue;
                        break;
		}
                default: 
                {
			m=k;
			continue;
                        break;
		}
		}
}	}
 }
void forward()
{
	//digitalWrite(motorsPinEnable,HIGH);
	digitalWrite(motor1Pin1, LOW);
	digitalWrite(motor1Pin2, HIGH);
	digitalWrite(motor2Pin1, HIGH);
	digitalWrite(motor2Pin2, LOW);
        analogWrite(pwm1,150);
        analogWrite(pwm2,150);
        Serial.println("I m in Forward ");
	//delay(1000);
	//digitalWrite(motorsPinEnable,LOW);
}
void backward()
{
	//digitalWrite(motorsPinEnable,HIGH);
	digitalWrite(motor1Pin1, HIGH);
	digitalWrite(motor1Pin2, LOW);
	digitalWrite(motor2Pin1, LOW);
	digitalWrite(motor2Pin2, HIGH);
        analogWrite(pwm1,150);
        analogWrite(pwm2,150);
        Serial.println("I m in Backward ");
	//delay(1000);
	//digitalWrite(motorsPinEnable,LOW);
}
void left()
{
	//digitalWrite(motorsPinEnable,HIGH);
	digitalWrite(motor1Pin1, LOW);
	digitalWrite(motor1Pin2, HIGH);
	digitalWrite(motor2Pin1, LOW);
	digitalWrite(motor2Pin2, HIGH);
        analogWrite(pwm1,150);
        analogWrite(pwm2,150);
        Serial.println("I m in left ");
	//delay(1000);
	//digitalWrite(motorsPinEnable,LOW);
}
void right()
{
	//digitalWrite(motorsPinEnable,HIGH);
	digitalWrite(motor1Pin1, HIGH);
	digitalWrite(motor1Pin2, LOW);
	digitalWrite(motor2Pin1, HIGH);
	digitalWrite(motor2Pin2, LOW);
        analogWrite(pwm1,150);
        analogWrite(pwm2,150);
        Serial.println("I m in Right ");
	//delay(1000);
	//digitalWrite(motorsPinEnable,LOW);
}

void stop1()
{
	//digitalWrite(motorsPinEnable,HIGH);
	digitalWrite(motor1Pin1, LOW);
	digitalWrite(motor1Pin2, LOW);
	digitalWrite(motor2Pin1, LOW);
	digitalWrite(motor2Pin2, LOW);
        analogWrite(pwm1,0);
        analogWrite(pwm2,0);
        Serial.println("I m in Stop ");
	//delay(1000);
	//digitalWrite(motorsPinEnable,LOW);
}

