bool bouncing(){
  bool sidesMotors = false;
  bool sidesSeeker = false;
  bool reset = false;
  if (timeTrack + 30000 > millis()){
    sidesMotors = false;
    sidesSeeker = false;
    if ((abs(::dirAngle) > 0 + 45 && abs(::dirAngle < 180 - 45)) || (abs(::dirAngle) > 180 + 45 && abs(::dirAngle < 360 - 45))) {
      sidesMotors = true;
    }
    InfraredResult InfraredBall = InfraredSeeker::ReadAC();
    if (InfraredBall.Direction == 4 || InfraredBall.Direction == 5 || InfraredBall.Direction == 6 || InfraredBall.Direction == 0){
      sidesSeeker = true;
    }
    if (linesCount > 2 && sidesMotors){
      if (sidesSeeker){
        ::dirAngle = (InfraredBall.Direction == 0) ? 120 : 0;
      }
      else{
        ::dirAngle = (InfraredBall.Direction >= 1 && InfraredBall.Direction <= 3) ? 90 : -90;
      }
      motors(::dirAngle);
      reset = true;
    }    
    timeTrack = millis();
    linesCount = 0;
  }
  return reset;
}
