void setup() 
{
pinMode(41,OUTPUT);
pinMode(40,OUTPUT);
Serial.begin(9600);
}

void loop() 
{
  digitalWrite(40,HIGH);
  delay(6000);
  digitalWrite(40,LOW);
  delay(6000);
  digitalWrite(41,HIGH);
  delay(6000);
  digitalWrite(41,LOW);
//   digitalWrite(10,HIGH);
//  delay(3000);
//  digitalWrite(10,LOW);
//  delay(3000);  

}
