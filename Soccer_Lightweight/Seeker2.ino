void seeker2(){
  InfraredResult InfraredBall = InfraredSeeker::ReadAC(); // get seeker direction
  switch(InfraredBall.Direction){
    case 1: //Back Left
      ::dirAngle = 180;
      break;
    case 2: //Back Left
      ::dirAngle = 180;
      break;
    case 3: //Front Left
      ::dirAngle = -120;
      break;
    case 4: //Front Left
      ::dirAngle = -120;
      break;
    case 5: //Front
      ::dirAngle = 0;
      VL53L0X_RangingMeasurementData_t measure;
      lox.rangingTest(&measure, false);
      if (measure.RangeStatus != 4 && measure.RangeMilliMeter <= RANGE) { // 45 degree turn to aproach ball in corners
          pixy.ccc.getBlocks();
          if (pixy.ccc.numBlocks){
            if(pixy.ccc.blocks[0].m_width < 100){
              if(pixy.ccc.blocks[0].m_x < 0 + 80){
                angleTurn(-45, 15);
              }
              if(pixy.ccc.blocks[0].m_x > 316 - 80){
                angleTurn(45, 15); 
              }
              ::dirAngle = 0;
              motors(::dirAngle);
              do {
                InfraredResult InfraredBall = InfraredSeeker::ReadAC();
                VL53L0X_RangingMeasurementData_t measure;
                lox.rangingTest(&measure, false);
              }
              while(InfraredBall.Direction == 5 && measure.RangeStatus != 4 && measure.RangeMilliMeter <= RANGE);
              }
            }
          }
      break;
    case 6: //Front Right
      ::dirAngle = 120;
      break;
    case 7: //Front Right
      ::dirAngle = 120;
      break;
    case 8: //Back Right
      ::dirAngle = 180;
      break;
    case 9: //Back Right
      ::dirAngle = 180;
      break;
    case 0: //Back
      ::dirAngle = 120;
      break;
  } 
  motors(::dirAngle);
}
