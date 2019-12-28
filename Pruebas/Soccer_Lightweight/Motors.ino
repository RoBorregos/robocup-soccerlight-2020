float degToRad(float dir){
  return (dir) * M_PI / 180;
}

void motors(int dir = 0){
  // set motors to move in direction dir degrees
  dir = 360 - dir;
  float m1 = cos(degToRad(150-dir));
  float m2 = cos(degToRad(30-dir));
  float m3 = cos(degToRad(270-dir));
  int speedA = int(m1*255);
  int speedB = int(m2*255);
  int speedC = int(m3*255);
  
  if (m1 >= 0){
    analogWrite(motor1A, speedA);
    analogWrite(motor1B, 0);
  }
  else {
    analogWrite(motor1A, 0);
    analogWrite(motor1B, abs(speedA));
  }
  if (m2 >= 0){
    analogWrite(motor2A, speedB);
    analogWrite(motor2B, 0);
  }
  else {
    analogWrite(motor2A, 0);
    analogWrite(motor2B, abs(speedB));
  }
  if (m3 >= 0){
    analogWrite(motor3A, speedC);
    analogWrite(motor3B, 0);
  }
  else {
    analogWrite(motor3A, 0);
    analogWrite(motor3B, abs(speedC));
  }
}

void turn(bool dir){
  /*  true turns right
      false turns left */
  if (dir) {
    analogWrite(motor1A, 0);
    analogWrite(motor1B, 255);
    analogWrite(motor2A, 0);
    analogWrite(motor2B, 255);
    analogWrite(motor3A, 0);
    analogWrite(motor3B, 255);
  }
  if (!dir) {
    analogWrite(motor1A, 255);
    analogWrite(motor1B, 0);
    analogWrite(motor2A, 255);
    analogWrite(motor2B, 0);
    analogWrite(motor3A, 255);
    analogWrite(motor3B, 0);
  }
}

void motorsOff(){
  // turn Off all motors
  analogWrite(motor1A, 0);
  analogWrite(motor1B, 0);
  analogWrite(motor2A, 0);
  analogWrite(motor2B, 0);
  analogWrite(motor3A, 0);
  analogWrite(motor3B, 0);
}
