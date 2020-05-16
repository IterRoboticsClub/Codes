#define LOST    50

/**** Hardware Pins ******/
int lPin1 = 2;
int lPin2 = 4;
int leftPWM = 9;
int rPin1 = 7;
int rPin2 = 8;
int rightPWM = 10;
int lineArray[5] = {
  A4, A3, A2, A1, A0
};

/*** Global variables ***/
int lineState[5];
int updateTime;
int thres = 640;
float baseSpeed = 180;
int timeOld, timeNew;
/*** PID Variables ***/
float PIDval;
float leftSpeed;
float rightSpeed;
float error, errorOld;
float Kp, Ki, Kd;
float prop, sum = 0, diff;

/*** Initialize the hardware, variable, etc ***/
void initAll(){
  /*** Hardware initialization ***/
  Serial.begin(9600);
  for(int i = 0; i < 5; i++){
    pinMode(lineArray[i], INPUT);
  }
  pinMode(lPin1, OUTPUT);
  pinMode(lPin2, OUTPUT);
  pinMode(rPin1, OUTPUT);
  pinMode(rPin2, OUTPUT);
  pinMode(leftPWM, OUTPUT);
  pinMode(rightPWM, OUTPUT);
  pinMode(4, OUTPUT);
  digitalWrite(4, HIGH);

  /*** Initialze Variables ***/
  timeOld = millis();
  timeNew = 0;
  PIDval = 0;
  error = 0;
  errorOld = 0;
  sum = 0;
  prop = 0;
  diff = 0;

  updateTime = 20; 	// Update cycle

  /*** Set PID Value here ***/
  /*
  Kp = 10; 
  Ki = 1; 
  Kd = 1;
  */
  Kp = 0; 
  Ki = 0; 
  Kd = 0;
}

void setup(){
  initAll();
}

void loop(){
  /*
  while(Serial.available()){
    char temp[4] = Serial.read();
    char c;
    if(temp == '0'){
      c = Serial.read();
      Kp = atoi(&c);
      // Ki = Serial.read();
      // Kd = Serial.read();
    }
  }
  Serial.print("PID Const: ");
  Serial.print(Kp);
  Serial.print(" ");
  Serial.print(Ki);
  Serial.print(" ");
  Serial.print(Kd);  
  Serial.print(" ");
  */

  // Checks loop time - can be removed
  timeNew = millis();
  Serial.print(timeNew - timeOld);
  timeOld = timeNew;
  Serial.print("ms ");

  /*** Update the sensors ***/
  for(int i = 0; i < 5; i++){
    lineState[i] = analogRead(lineArray[i]);

    /* Configure black on white or white on black here
     * Convention is that 1 represents the line
     * Current sensor gives > thres value for black
     */
    if(lineState[i] > thres) lineState[i] = 0;
    else lineState[i] = 1;

    Serial.print(lineState[i]);
  }

  Serial.print(", E=");

  /*** Calculate Error ***/
  /* Positive when the robot needs to turn left  => Increase right speed
   * Negative when the robot needs to turn right => Increase left speed
   * When lineState==1, it means on the line
   * This is a five line array whose values are stored in lineState[]
   * 0 - Left Most
   * 1 - Left
   * 2 - Middle
   * 3 - Right
   * 4 - Right Most
   */
  if(lineState[2] == 1){
    if(lineState[1] == lineState[3]) error = 0;
    else if(lineState[1] == 1) error = 1;
    else error = -1;
  } 
  else if(lineState[1] == 1){
    if(lineState[0] == 1) error = 3;
    else error = 2;
  }
  else if(lineState[0] == 1){
    error = 5;
  }
  else if(lineState[3] == 1){
    if(lineState[4] == 1) error = -3;
    else error = -2;
  }
  else if(lineState[4] == 1){
    error = -5;
  }
  else{
    // LOST - ADD SOME CODE HERE!!!!
    error = LOST;
    sum = 0;
    errorOld = 0;
  }

  if(error != LOST){
    /*** Calculate PID Value ***/
    Serial.print(error);
    Serial.print(", L=");
    prop = Kp * error;
    sum += Ki * error;
    sum = saturate(sum, 25);
    diff = Kd * (error - errorOld);

    PIDval = prop + sum + diff;
    errorOld = error;
    PIDval = saturate(PIDval, 60);

    /*** Write to motors ***/
    // Set motor speeds
    leftSpeed = baseSpeed-PIDval;
    rightSpeed = baseSpeed+PIDval;
    // Run motors
    leftMotor(leftSpeed);    
    rightMotor(rightSpeed);
    
    // Outputs speed
    Serial.print(leftSpeed);
    Serial.print(", R=");
    Serial.print(rightSpeed);
  }
  else {
    // Robot is lost so stop it
    leftMotor(0);
    rightMotor(0);
  }
  
  delay(20);
  Serial.println();
}

// Set left motor speed - Front if positive, back if negative
void leftMotor(int value){
  int v2 = saturate(value,255);
  if(value >= 0){
    digitalWrite(lPin1,0 );
    digitalWrite(lPin2,1);
    analogWrite(leftPWM, v2);
  } 
  else {
    digitalWrite(lPin1, 1);
    digitalWrite(lPin2, 0);
    analogWrite(leftPWM, -v2);
  }
}

// Set right motor speed - Front if positive, back if negative
void rightMotor(int value){
  int v2 = saturate(value,255);  
  if(value >= 0){
    digitalWrite(rPin1,0 );
    digitalWrite(rPin2,1);
    analogWrite(rightPWM, v2);
  } 
  else {
    digitalWrite(rPin1, 1);
    digitalWrite(rPin2, 0);
    analogWrite(rightPWM, -v2);
  }
}

// Saturates between -mmax and +mmax
int saturate(int val, int mmax){
  if(val > mmax) return mmax;
  if(val < -mmax) return -mmax;
  else return val;
}






