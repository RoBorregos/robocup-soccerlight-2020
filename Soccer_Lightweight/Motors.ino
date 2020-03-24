void motors(int dir){
  // set motors to move in direction dir degrees
  int power = 255;
  float m1 = cos(degToRad(150-dir));
  float m2 = cos(degToRad(30-dir));
  float m3 = cos(degToRad(270-dir));
  int speedA = int(m1*power);
  int speedB = int(m2*power);
  int speedC = int(m3*power);
  
  if (m1 >= 0){
    analogWrite(MOTOR1A, speedA);
    analogWrite(MOTOR1B, 0);
  }
  else {
    analogWrite(MOTOR1A, 0);
    analogWrite(MOTOR1B, abs(speedA));
  }
  if (m2 >= 0){
    analogWrite(MOTOR2A, speedB);
    analogWrite(MOTOR2B, 0);
  }
  else {
    analogWrite(MOTOR2A, 0);
    analogWrite(MOTOR2B, abs(speedB));
  }
  if (m3 >= 0){
    analogWrite(MOTOR3A, speedC);
    analogWrite(MOTOR3B, 0);
  }
  else {
    analogWrite(MOTOR3A, 0);
    analogWrite(MOTOR3B, abs(speedC));
  }
}


void turn(bool dir, int power = 255){
  // False turns right.
  // True turns left.
  if(dir) {
    analogWrite(MOTOR1A, 0);
    analogWrite(MOTOR1B, power);
    analogWrite(MOTOR2A, 0);
    analogWrite(MOTOR2B, power);
    analogWrite(MOTOR3A, 0);
    analogWrite(MOTOR3B, power);
  }
  if(!dir) {
    analogWrite(MOTOR1A, power);
    analogWrite(MOTOR1B, 0);
    analogWrite(MOTOR2A, power);
    analogWrite(MOTOR2B, 0);
    analogWrite(MOTOR3A, power);
    analogWrite(MOTOR3B, 0);
  }
}


void motorsOff(){
  // Turns Off all motors
  analogWrite(MOTOR1A, 0);
  analogWrite(MOTOR1B, 0);
  analogWrite(MOTOR2A, 0);
  analogWrite(MOTOR2B, 0);
  analogWrite(MOTOR3A, 0);
  analogWrite(MOTOR3B, 0);
}
