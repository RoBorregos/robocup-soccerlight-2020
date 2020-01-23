void seeker(){
  InfraredResult InfraredBall = InfraredSeeker::ReadAC();
  switch(InfraredBall.Direction){
    case 1: //Back Left
      motors(180);
      break;
    case 2: //Back Left
      motors(180);
      break;
    case 3: //Front Left
      motors(-120);
      break;
    case 4: //Front Left
      motors(-120);
      break;
    case 5: //Front
      motors();
      VL53L0X_RangingMeasurementData_t measure;
      lox.rangingTest(&measure, false);
      if (measure.RangeStatus != 4 && measure.RangeMilliMeter <= RANGE) { 
          pixy.ccc.getBlocks();
          if (pixy.ccc.numBlocks){
            if(pixy.ccc.blocks[0].m_width < 100){
              if(pixy.ccc.blocks[0].m_x < 0 + 80){
                motors(-45); 
              }
              if(pixy.ccc.blocks[0].m_x > 316 - 80){
                motors(45); 
              }
            }
          }
        }
      break;
    case 6: //Front Right
      motors(120);
      break;
    case 7: //Front Right
      motors(120);
      break;
    case 8: //Back Right
      motors(180);
      break;
    case 9: //Back Right
      motors(180);
      break;
    case 0: //Back
      motors(120);
      break;
  } 
}
