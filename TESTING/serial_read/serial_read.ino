void setup()
{
 Serial.begin(9600);
 pinMode(A2,INPUT);
  Serial.println("I m in SETUP");
}

void loop()
{
  char ch;
  ch=Serial.read();
  while(!Serial.available())
  {
    Serial.println("I m in Loop");
    ch=Serial.read();
  }
  
//  if(ch==10)
//  {
//    ch=0;
//  }
  Serial.println("The value is:- ");
  Serial.println(ch);
  
  delay(1000);
}
