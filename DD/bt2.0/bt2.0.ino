//////////////////////////////////////////////////////////////////////////////////
// REMIXED BY: TECHBITAR (HAZIM BITAR)
// LICENSE: PUBLIC DOMAIN
// DATE: MAY 2, 2012
// CONTACT: techbitar at gmail dot com

int counter =0;

void setup() {
  Serial.begin(9600); 
  delay(50);
}

void loop() {
  counter++;
  Serial.print("Arduino counter: ");
  Serial.println(counter);
  delay(500); // wait half a sec
}
