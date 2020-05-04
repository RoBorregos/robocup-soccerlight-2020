int error(float actual, float final = BNO_START){ 
  // Actual and final are angles in degrees.
  // Function returns an angle in degrees.
  // Positive angle signals right.
  // Negative angle signals left.
  int total = final-actual;
  if(total > 180){
    total = -(360-total);
  }
  else if(total < -180){
    total = 360 + total;
  }
  return total;
}


void angleFix(){
  // Sets angle back to 0.
  if(millis() < angleFixTime + 150){
    return;
  }
  imu::Vector<3> euler = bno.getVector(Adafruit_BNO055::VECTOR_EULER);
  angleFixTime = millis();
  ::fix = error(euler.x());
  if(abs(::fix) > TOLERANCE){
    while(abs(::fix) > TOLERANCE){
      if(::fix > 0){
        robot.turnRight(50+75*abs(::fix)/180);
        Serial.println("Turn Right");
        Serial.println(euler.x());
      }
      else{
        robot.turnLeft(50+75*abs(::fix)/180);
        Serial.println("Turn Left");
        Serial.println(euler.x());
      }
      euler = bno.getVector(Adafruit_BNO055::VECTOR_EULER);
      ::fix = error(euler.x());
      robot.stopMotors();
    }
    robot.stopMotors();
  } 
  Serial.println("BNO055 within tolerance");
  Serial.println(euler.x());
}


void angleTurn(int dirTurn, int tolerance){
  // Function sets angle to dirTurn.
  imu::Vector<3> euler = bno.getVector(Adafruit_BNO055::VECTOR_EULER);
  ::fix = error(euler.x(), dirTurn);
  if(abs(::fix) > tolerance){
    while(abs(::fix) > tolerance){
      if(::fix > 0){
        robot.turnRight(50+75*abs(::fix)/180);
        Serial.println("AT Turn Right");
      }
      else{
        robot.turnLeft(50+75*abs(::fix)/180);
        Serial.println("AT Turn Left");
      }
      euler = bno.getVector(Adafruit_BNO055::VECTOR_EULER);
      ::fix = error(euler.x(), dirTurn);
      robot.stopMotors();
    }
    robot.stopMotors();
  } 
  Serial.println("AT BNO055 within tolerance");
  Serial.println(euler.x());
}
