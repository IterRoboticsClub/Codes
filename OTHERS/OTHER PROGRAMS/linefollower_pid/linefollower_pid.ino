
int x,y;
int motor_speed=255;

void read_accelometer_values(void);
void fwd(void);
void rev(void);
void rt(void);
void lt(void);
void st(void);

void setup()
{
 pinMode(9,OUTPUT); //PWM Pin 1
 pinMode(10,OUTPUT); //PWM Pin 2
 pinMode(2,OUTPUT);
 pinMode(4,OUTPUT);
 //Left Motor Pin 2
 pinMode(7,OUTPUT); //Right Motor Pin 1
 pinMode(8,OUTPUT);  //Right Motor Pin 2
 Serial.begin(9600); //Enable Serial Communications
}

void loop()
{
    read_accelometer_values();
}

void read_accelometer_values()
{
  x=analogRead(A0);
  y=analogRead(A1);
  if(y>320 & y<350)
		{	
			if(x<320)
			{
				rt(); //turn left
                                Serial.println("Left");
			}
			else if(x>360)
			{        
                                 lt();
				 //turn right
                                Serial.println("Right");
			}
			else
			{
				st(); //stop
                                Serial.println("Stop");
			}
		}
					
		else if(x>32 0 & x<360)
		{	
			if(y<300)
			{
				fwd(); //forward
                                Serial.println("Forward");
			}
			else if(y>370)
			{
				rev(); //reverse
                                Serial.println("Reverse");
                                Serial.println(x);
                                Serial.println(y);
                                //delay(500);
			}
			else
			{
				st(); //stop
                                Serial.println("Stop");
			}
		}

}


void fwd()
{
  Serial.println("Fwd motor function");
    digitalWrite(2,HIGH);
    digitalWrite(4,LOW);
    digitalWrite(7,LOW);
    digitalWrite(8,HIGH);
    analogWrite(9,motor_speed);
    analogWrite(10,motor_speed);
    
}

void rev()
{
    Serial.println("Rev motor function");
    digitalWrite(2,LOW);
    digitalWrite(4,HIGH);
    digitalWrite(7,HIGH);
    digitalWrite(8,LOW);
    analogWrite(9,motor_speed);
    analogWrite(10,motor_speed);
    Serial.println("Motor function runing");
}

void rt()
{
    Serial.println("Rt motor function");
    digitalWrite(2,HIGH);
    digitalWrite(4,LOW);
    digitalWrite(7,HIGH);
    digitalWrite(8,LOW);
    analogWrite(9,motor_speed);
    analogWrite(10,motor_speed-55);
    Serial.println("RT function runing");
}

void lt()
{
    Serial.println("Rt motor function");
    digitalWrite(2,LOW);
    digitalWrite(4,HIGH);
    digitalWrite(7,LOW);
    digitalWrite(8,HIGH);
    analogWrite(9,motor_speed-55);
    analogWrite(10,motor_speed);
    Serial.println("LT function runing");
}

void st()
{
    digitalWrite(2,LOW);
    digitalWrite(4,LOW);
    digitalWrite(7,LOW);
    digitalWrite(8,LOW);
    analogWrite(9,0);
    analogWrite(10,0);
}

