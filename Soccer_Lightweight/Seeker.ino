void seeker(){
  InfraredResult InfraredBall = InfraredSeeker::ReadAC(); // get seeker direction
  Serial.print("Direction = ");
  switch(InfraredBall.Direction){
    case 1: //Back Left
      ::dirAngle = 180;
      Serial.println("180");
      break;
    case 2: //Back Left
      ::dirAngle = -150;
      Serial.println("-150");
      break;
    case 3: //Front Left
      ::dirAngle = -120;
      Serial.println("-120");
      break;
    case 4: //Front Left
      ::dirAngle = -90;
      Serial.println("-90");
      break;
    case 5: //Front
      ::dirAngle = 0;
      Serial.println("0");
      
      VL53L0X_RangingMeasurementData_t measure;
      lox.rangingTest(&measure, false);
      if(measure.RangeStatus != 4 && measure.RangeMilliMeter <= RANGE) { // 45 degree turn to aproach ball in corners
          PixyUpdate();
          if(pixy.ccc.numBlocks && pixy.ccc.blocks[0].m_signature == SIG){
            if(pixy.ccc.blocks[0].m_width < 200){        
              if(pixy.ccc.blocks[0].m_x < 158 - Ptol || pixy.ccc.blocks[0].m_x > 158 + Ptol){
                do{
                  center();
                  // kicker
                  motors(::dirAngle);
                  InfraredResult InfraredBall = InfraredSeeker::ReadAC();
                  VL53L0X_RangingMeasurementData_t measure;
                  lox.rangingTest(&measure, false);
                }
                while(InfraredBall.Direction == 5 && measure.RangeStatus != 4 && measure.RangeMilliMeter <= RANGE);
                }                        
              }              
            }
            else if(Ppos == 3){   // esta a la derecha
              int turn = 25; // calibrar
              // vuelta 45 a derecha
            }
            else if(Ppos == 1){   // esta a la izquierda
              int turn = -25; // calibrar
              // vuelta 45 a izquierda
            }
            do{
              angleTurn(turn, 15);
              motors(::dirAngle);
              InfraredResult InfraredBall = InfraredSeeker::ReadAC();
              VL53L0X_RangingMeasurementData_t measure;
              lox.rangingTest(&measure, false);
            }
            while(InfraredBall.Direction == 5 && measure.RangeStatus != 4 && measure.RangeMilliMeter <= RANGE);
          }
          
      break;
    case 6: //Front Right
      ::dirAngle = 90;
      Serial.println("90");
      break;
    case 7: //Front Right
      ::dirAngle = 120;
      Serial.println("120");
      break;
    case 8: //Back Right
      ::dirAngle = 150;
      Serial.println("150");
      break;
    case 9: //Back Right
      ::dirAngle = 180;
      Serial.println("180");
      break;
  } 
  if(InfraredBall.Direction == 0){
    motorsOff();
    Serial.println("Off");
  }
  else{
    motors(::dirAngle);
  }
}
