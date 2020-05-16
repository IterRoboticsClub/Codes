#define trigPin 13
#define echoPin 12


void setup() 
{
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop()
{
  float duration, distance;
  digitalWrite(trigPin, LOW);  // Added this line
  delayMicroseconds(2); // Added this line
  digitalWrite(trigPin, HIGH);
//  delayMicroseconds(1000); - Removed this line
  delayMicroseconds(10); // Added this line
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  Serial.println("Duration = ");
  Serial.print(duration);
  distance=duration / 29 / 2;
  //distance = (duration/2) / 29.1;
  Serial.println("\nDistance = ");
  Serial.print(distance);
  /*if (distance < 4) {  // This is where the LED On/Off happens
    

}
  else {
  }*/
  if (distance >= 200 || distance <= 0){
    Serial.println("Out of range");
  }
  else {
    Serial.print(distance);
    Serial.println(" cm");
  }
  delay(500);
}
