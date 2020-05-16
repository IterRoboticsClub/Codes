long sensors_average;
int sensors_sum;
int pos;
long sensors[] = {0, 0, 0, 0, 0}; // Array used to store 5 readings for 5 sensors.
void setup()
{ Serial.begin(9600);
}
void loop()
{ sensors_average = 0;
sensors_sum = 0;
for (int i = 0; i < 5; i++)
{sensors[i] = analogRead(i);
sensors_average += sensors[i] * i * 1000; //Calculating the weighted mean
sensors_sum += int(sensors[i]);} //Calculating sum of sensor readings
pos = int(sensors_average / sensors_sum);
Serial.println("average");
Serial.println(sensors_average);
Serial.println("sensor sum");
Serial.println(sensors_sum);
Serial.println("pos");
Serial.println(pos);
Serial.println();
delay(2000);
}
