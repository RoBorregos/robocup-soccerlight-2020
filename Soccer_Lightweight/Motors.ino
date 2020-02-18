void motors(int dir = 0){
  int POWER = 255; // total motor speed
  // set motors to move in direction dir degrees
  float m1 = cos(degToRad(150-dir));
  float m2 = cos(degToRad(30-dir));
  float m3 = cos(degToRad(270-dir));
  int speedA = m1*POWER;
  int speedB = m2*POWER;
  int speedC = m3*POWER;
  
  if(m1 >= 0){
    analogWrite(MOTOR1A, speedA);
    analogWrite(MOTOR1B, 0);
  }
  else {
    analogWrite(MOTOR1A, 0);
    analogWrite(MOTOR1B, abs(speedA));
  }
  if(m2 >= 0){
    analogWrite(MOTOR2A, speedB);
    analogWrite(MOTOR2B, 0);
  }
  else {
    analogWrite(MOTOR2A, 0);
    analogWrite(MOTOR2B, abs(speedB));
  }
  if(m3 >= 0){
    analogWrite(MOTOR3A, speedC);
    analogWrite(MOTOR3B, 0);
  }
  else {
    analogWrite(MOTOR3A, 0);
    analogWrite(MOTOR3B, abs(speedC));
  }
}

void turn(bool dir, int power = 255){
  /*  false turns right
      true turns left */
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
  // turn Off all motors
  analogWrite(MOTOR1A, 0);
  analogWrite(MOTOR1B, 0);
  analogWrite(MOTOR2A, 0);
  analogWrite(MOTOR2B, 0);
  analogWrite(MOTOR3A, 0);
  analogWrite(MOTOR3B, 0);
}
