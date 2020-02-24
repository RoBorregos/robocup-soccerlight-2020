int error(float actual, float final = 0){ 
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
  if(millis() < angleFixTime + 50){
    return;
  }
  imu::Vector<3> euler = bno.getVector(Adafruit_BNO055::VECTOR_EULER);
  angleFixTime = millis();
  ::fix = error(euler.x());
  
  if(abs(::fix) > TOLERANCE){
    while(abs(::fix) > TOLERANCE){
      if(::fix > 0){
        turn(false, 255);
        Serial.println("Turn Right");
      }
      else{
        turn(true, 255);
        Serial.println("Turn Left");
      }
      imu::Vector<3> euler = bno.getVector(Adafruit_BNO055::VECTOR_EULER);
      ::fix = error(euler.x());
      motorsOff();
    }
    motorsOff();
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
        turn(false, 255);
        Serial.println("Turn Right");
      }
      else{
        turn(true, 255);
        Serial.println("Turn Left");
      }
      imu::Vector<3> euler = bno.getVector(Adafruit_BNO055::VECTOR_EULER);
      ::fix = error(euler.x(), dirTurn);
      motorsOff();
    }
    motorsOff();
  } 
  Serial.println("BNO055 within tolerance");
  Serial.println(euler.x());
}
