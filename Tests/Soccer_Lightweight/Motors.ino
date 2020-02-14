void motors(int dir = 0){
  // set motors to move in direction dir degrees
  float m1 = cos(degToRad(150-dir));
  float m2 = cos(degToRad(30-dir));
  float m3 = cos(degToRad(270-dir));

  Serial.println("TEST");
  Serial.println(degToRad(150-dir));
  
  
  int speedA = m1*POWER;
  int speedB = m2*POWER;
  int speedC = m3*POWER;

  Serial.print("m1 = ");
  Serial.println(m1);
  Serial.print("s1 = ");
  Serial.println(speedA);
  Serial.print("m2 = ");
  Serial.println(m2);
  Serial.print("s2 = ");
  Serial.println(speedB);
  Serial.print("m3 = ");
  Serial.println(m3);
  Serial.print("s3 = ");
  Serial.println(speedC);
  
  delay(1000);
  
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

void turn(bool dir){
  /*  true turns right
      false turns left */
  if (dir) {
    analogWrite(MOTOR1A, 0);
    analogWrite(MOTOR1B, POWER);
    analogWrite(MOTOR2A, 0);
    analogWrite(MOTOR2B, POWER);
    analogWrite(MOTOR3A, 0);
    analogWrite(MOTOR3B, POWER);
  }
  if (!dir) {
    analogWrite(MOTOR1A, POWER);
    analogWrite(MOTOR1B, 0);
    analogWrite(MOTOR2A, POWER);
    analogWrite(MOTOR2B, 0);
    analogWrite(MOTOR3A, POWER);
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
