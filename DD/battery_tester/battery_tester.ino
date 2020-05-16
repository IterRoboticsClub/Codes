// Project 6 - Creating a Single-Cell Battery Tester 
#define newLED 2  // green LED  'new' 
#define okLED  4  // yellow LED 'ok' 
#define oldLED 6  // red LED    'old'


int ledDelay = 2000;
void setup() 
{
 Serial.begin(9600); 
  pinMode(newLED, OUTPUT);
  pinMode(okLED, OUTPUT);
  pinMode(oldLED, OUTPUT);
  
}

void loop() {
  int analogValue = 0;
float voltage = 0;
  
  analogValue = analogRead(0);
  voltage = 0.00*analogValue;
  if ( voltage >= 1.6 )
  {    
    digitalWrite(newLED, HIGH);
    delay(ledDelay);
    digitalWrite(newLED, LOW);
    Serial.println("N= ");
    Serial.println(voltage);
    Serial.println(analogValue);
  } 
  else if ( voltage < 1.6 && voltage > 0.8 )
  {
    digitalWrite(okLED, HIGH);
    delay(ledDelay);
    digitalWrite(okLED, LOW);
    Serial.println("OK= ");
    Serial.println(voltage); 
    Serial.println(analogValue);
  }
  else if ( voltage <= 0.8 )   
{    
  digitalWrite(oldLED, HIGH);
  delay(ledDelay);
  digitalWrite(oldLED, LOW);
  Serial.println("OLD= ");
  Serial.println(voltage);  
  Serial.println(analogValue);

}
}
