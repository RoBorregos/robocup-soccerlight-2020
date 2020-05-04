void seeker(){
  InfraredResult InfraredBall = InfraredSeeker::ReadAC();
  // Get seeker direction.
  Serial.print("Direction = ");
  switch(InfraredBall.Direction){
    case 1: // Back Left.
      ::dirAngle = -180;
      Serial.println("-180");
      break;
    case 2: // Back Left.
      ::dirAngle = -150;
      Serial.println("-150");
      break;
    case 3: // Front Left.
      ::dirAngle = -120;
      Serial.println("-120");
      break;
    case 4: // Front Left.
      ::dirAngle = -90;
      Serial.println("-90");
      break;
    case 5: // Front.
      ::dirAngle = 0;
      Serial.println("0");
      
      VL53L0X_RangingMeasurementData_t measure;
      lox.rangingTest(&measure, false);
      if(measure.RangeStatus != 4 && measure.RangeMilliMeter <= RANGE) {
        Serial.print("Ball in mouth = ");
        Serial.println(measure.RangeMilliMeter);
          pixyUpdate();
          if(pixy.ccc.numBlocks && pixy.ccc.blocks[0].m_signature == SIG){
            if(pixy.ccc.blocks[0].m_width < 250){        
              if(pixy.ccc.blocks[0].m_x < 158 - Ptol || pixy.ccc.blocks[0].m_x > 158 + Ptol){
                do{
                  Serial.println("Loop with pixy");
                  center();
                 robot.moveMotors(::dirAngle, 255);
                  InfraredBall = InfraredSeeker::ReadAC();
                  lox.rangingTest(&measure, false);
                }
                while(InfraredBall.Direction == 5 && measure.RangeMilliMeter <= RANGE);
                }                       
              }              
            }
            
            else if(Ppos == 3 || Ppos == 1){   // Goal is to the right.
              int turn = (Ppos == 3) ? 25 : -25; // turn 25 degrees to the right or to the left.
              do{
                Serial.println("Loop without pixy");
                angleTurn(turn, 20);
               robot.moveMotors(::dirAngle, 255);
                InfraredBall = InfraredSeeker::ReadAC();
                lox.rangingTest(&measure, false);
              }
              while(InfraredBall.Direction == 5 && measure.RangeMilliMeter <= RANGE);
            }
            
          }
          
      break;
    case 6: // Front Right.
      ::dirAngle = 90;
      Serial.println("90");
      break;
    case 7: // Front Right.
      ::dirAngle = 120;
      Serial.println("120");
      break;
    case 8: // Back Right.
      ::dirAngle = 150;
      Serial.println("150");
      break;
    case 9: // Back Right.
      ::dirAngle = 180;
      Serial.println("180");
      break;
  } 
  if(InfraredBall.Direction == 0){ // Fix this.
    ::dirAngle = -130;
   robot.moveMotors(::dirAngle, 255);
    // robot.stopMotors();
    Serial.println("Off");
  }
  else{
   robot.moveMotors(::dirAngle, 255);
  }
}
