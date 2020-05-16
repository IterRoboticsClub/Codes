int F=120;

void setup()
{
  pinMode(2,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
}


void loop()
{ 
  digitalWrite(2,HIGH);
  digitalWrite(4,LOW);
  digitalWrite(7,HIGH);
  digitalWrite(8,LOW);
  analogWrite(9,F);
  analogWrite(10,F);
 delay(1000);
// 
// digitalWrite(2,LOW);
//  digitalWrite(4,LOW);
//  digitalWrite(7,LOW);
//  digitalWrite(8,LOW);
//  analogWrite(9,0);
//  analogWrite(10,0);
// delay(1000);
// 
// digitalWrite(2,HIGH);
//  digitalWrite(4,LOW);
//  digitalWrite(7,LOW);
//  digitalWrite(8,HIGH);
//  analogWrite(9,F);
//  analogWrite(10,F);
// delay(1000);
// 
// digitalWrite(2,LOW);
//  digitalWrite(4,LOW);
//  digitalWrite(7,LOW);
//  digitalWrite(8,LOW);
//  analogWrite(9,0);
//  analogWrite(10,0);
// delay(1000);
//
//   digitalWrite(2,LOW);
//  digitalWrite(4,HIGH);
//  digitalWrite(7,HIGH);
//  digitalWrite(8,LOW);
//  analogWrite(9,F);
//  analogWrite(10,F);
// delay(1000);
// 
// digitalWrite(2,LOW);
//  digitalWrite(4,LOW);
//  digitalWrite(7,LOW);
//  digitalWrite(8,LOW);
//  analogWrite(9,0);
//  analogWrite(10,0);
// delay(1000);
// 
// digitalWrite(2,LOW);
//  digitalWrite(4,HIGH);
//  digitalWrite(7,LOW);
//  digitalWrite(8,HIGH);
//  analogWrite(9,F);
//  analogWrite(10,F);
// delay(1000);
// 
// digitalWrite(2,LOW);
//  digitalWrite(4,LOW);
//  digitalWrite(7,LOW);
//  digitalWrite(8,LOW);
//  analogWrite(9,0);
//  analogWrite(10,0);
// delay(1000);
}
