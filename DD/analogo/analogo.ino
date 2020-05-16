/*
  AnalogReadSerial
  Reads an analog input on pin 0, prints the result to the serial monitor.
  Attach the center pin of a potentiometer to pin A0, and the outside pins to +5V and ground.

 This example code is in the public domain.
 */

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  int sensorValue1 = digitalRead(11);
  int sensorValue2= digitalRead(12);
  // print out the value you read:
  Serial.print("\nValue 1=");
  Serial.println(sensorValue1);
  Serial.print("\nValue 2= ");
  Serial.println(sensorValue2);
  delay(1000);        // delay in between reads for stability
}
