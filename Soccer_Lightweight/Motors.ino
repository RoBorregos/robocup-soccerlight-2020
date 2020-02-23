void motors(int dir){
  int POWER = 255; // total motor speed
  // set motors to move in direction dir degrees
  int speed1 = cos(degToRad(150-dir))*POWER;
  int speed2 = cos(degToRad(30-dir))*POWER;
  int speed3 = cos(degToRad(270-dir))*POWER;
  
  if(speed1 >= 0){
    analogWrite(MOTOR1A, speed1);
    analogWrite(MOTOR1B, 0);
  }
  else {
    analogWrite(MOTOR1A, 0);
    analogWrite(MOTOR1B, abs(speed1));
  }
  if(speed2 >= 0){
    analogWrite(MOTOR2A, speed1);
    analogWrite(MOTOR2B, 0);
  }
  else {
    analogWrite(MOTOR2A, 0);
    analogWrite(MOTOR2B, abs(speed2));
  }
  if(speed3 >= 0){
    analogWrite(MOTOR3A, speed2);
    analogWrite(MOTOR3B, 0);
  }
  else {
    analogWrite(MOTOR3A, 0);
    analogWrite(MOTOR3B, abs(speed2));
  }
}

void turn(bool dir, int power){
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
