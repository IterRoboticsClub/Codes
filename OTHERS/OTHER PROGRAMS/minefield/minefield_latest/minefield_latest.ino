
int x,y;
int motor_speed=100;

void read_accelometer_values(void);
void fwd(void);
void rev(void);
void rt(void);
void lt(void);
void st(void);

void setup()
{
 pinMode(9,OUTPUT); //PWM Pin 1
 pinMode(10,OUTPUT);
 pinMode(2,OUTPUT);
 pinMode(4,OUTPUT);
 pinMode(7,OUTPUT);
 pinMode(8,OUTPUT);
 //Left Motor Pin 2 //Right Motor Pin 2
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
			if(x<310)
			{
				rt(); //turn left
                                
			}
			else if(x>360)
			{        
                                 lt();
				 //turn right
                               
			}
			else
			{
				st(); //stop
                                
			}
		}
					
		else if(x>310 & x<360)
		{	
			if(y<300)
			{
				fwd(); //forward
                                
			}
			else if(y>370)
			{
				rev(); //reverse
                                
                                //delay(500);
			}
			else
			{
				st(); //stop
                                
			}
		}

}


void fwd()
{
  Serial.println("Fwd motor function");
    digitalWrite(2,HIGH);
    digitalWrite(4,LOW);
    analogWrite(9,motor_speed);
    digitalWrite(7,LOW);
    digitalWrite(8,HIGH);
    analogWrite(10,motor_speed);
    
}

void rev()
{
    Serial.println("Rev motor function");
    digitalWrite(2,LOW);
    digitalWrite(4,HIGH);
    analogWrite(9,motor_speed);
    digitalWrite(7,HIGH);
    digitalWrite(8,LOW);
    analogWrite(10,motor_speed);
    

}

void rt()
{
    Serial.println("Rt motor function");
    digitalWrite(2,HIGH);
    digitalWrite(4,LOW);
    digitalWrite(7,HIGH);
    digitalWrite(8,LOW);
    analogWrite(9,100);
    analogWrite(10,100);
    
    Serial.println("RT function runing");
}

void lt()
{
    Serial.println("lt motor function");
    digitalWrite(2,LOW);
    digitalWrite(4,HIGH);
    
    analogWrite(9,100);
    digitalWrite(7,HIGH);
    digitalWrite(8,LOW);
    
    analogWrite(10,100);
    
   
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

