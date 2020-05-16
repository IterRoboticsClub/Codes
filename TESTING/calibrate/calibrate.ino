int sensor[6]={0, 0, 0, 0, 0, 0};
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:

  sensor[0]=digitalRead(A0);
  sensor[1]=digitalRead(A1);
  sensor[2]=digitalRead(A2);
  sensor[3]=digitalRead(A3);
  sensor[4]=digitalRead(A4);
  sensor[5]=digitalRead(A5);
  Serial.print("\nA0=");
  Serial.print(sensor[0]);
  Serial.print("\nA1=");
  Serial.print(sensor[1]);
  Serial.print("\nA2=");
  Serial.print(sensor[2]);
  Serial.print("\nA3=");
  Serial.print(sensor[3]);
  Serial.print("\nA4=");
  Serial.print(sensor[4]);
  Serial.print("\nA5=");
  Serial.print(sensor[5]);
  delay(1000);
}
