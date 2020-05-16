int xPin=0;//Connect x pin of adxl335 to pin A0
int yPin=1;//Connect y pin of adxl335 to pin A1

void setup() 
{
 pinMode(13,OUTPUT);
  Serial.begin(9600);//Initialise the serial connection
}

void loop() 
{
  int i=5;
  int xval=analogRead(xPin);
  int yval=analogRead(yPin);
  int x=xval;
  int y=yval;
  Serial.print("xval=");
  Serial.println(xval);//Use xval to determine threshold for different directions
  
  Serial.print("yval=");
  Serial.println(yval); //Use yval to determine threshold for different directions
  delay(2000); //used to display values after 2s delay
  
  Serial.print("\n");//print after 2s in a new line
  if(y>270)
  {
    Serial.println("I m Down");
    while(i!=0)
    {
      digitalWrite(13,HIGH);
      delay(1000);
      digitalWrite(13,LOW);
      delay(1000);
      i--;
    }
    
  }
  
  else if(y>250&&y<270)
  {
    
    digitalWrite(13,LOW);
    delay(100);
    digitalWrite(13,LOW);
    delay(100);
    Serial.println("I m in Center");
  }
  
  else if(y<250)
  {
    Serial.println("I m in Up");
        while(i!=0)
        {
          digitalWrite(13,HIGH);
          delay(100);
          digitalWrite(13,LOW);
          delay(100);
          i--;
        }
   }
}
