
int a;

void setup() 
{
  
  pinMode(13, OUTPUT);
  Serial.begin(9600);
  
}

void loop() 
{
  a = Serial.read();
  Serial.println(" Enter ur Choice = " );

    while(Serial.available() <1)
    {
        Serial.println(" I M IN WHILE ");
         a=Serial.read(); 
    
        if (a == 49)
            {
              digitalWrite(13, HIGH);   
              delay(1000);
            }
    
          else if(a == 50)
                  {
                    digitalWrite(13, LOW);    
                    delay(1000);             
                  }

          Serial.println(a);
      }
}
