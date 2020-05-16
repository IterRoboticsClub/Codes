#include <Servo.h>  
Servo myservo1; 
Servo myservo2; 
Servo myservo3; 
int pos1 = 0;  
int pos2 = 0; 
int pos3 = 0;  
void setup() 
{ 
  myservo1.attach(11);
  myservo2.attach(10); 
  myservo3.attach(9);  
} 
 
void loop() 
{ 
  for(pos1 = 0; pos1 <= 180; pos1 += 1) 
  {                                 
    myservo1.write(pos1);               
    delay(5);                       
  } 
  for(pos1 = 180; pos1>=0; pos1-=1)   
  {                                
    myservo1.write(pos1);             
    delay(5);                    
  } 
  
    for(pos2 = 0; pos2 <= 180; pos2 += 1) 
  {                                 
    myservo2.write(pos2);               
    delay(5);                       
  } 
  for(pos2 = 180; pos2>=0; pos2-=1)   
  {                                
    myservo2.write(pos2);             
    delay(5);                    
  } 
  
    for(pos3 = 0; pos3 <= 180; pos3 += 1) 
  {                                 
    myservo3.write(pos3);               
    delay(5);                       
  } 
  for(pos3 = 180; pos3>=0; pos3-=1)   
  {                                
    myservo3.write(pos3);             
    delay(5);                    
  } 
} 

