void seeker(){
  InfraredResult InfraredBall = InfraredSeeker::ReadAC();
  Serial.print("Seeker Dir = ");
  Serial.println(InfraredBall.Direction);
  switch(InfraredBall.Direction){
    case 1: //Back Left
      ::dirAngle = 180;
      break;
    case 2: //Back Left
      ::dirAngle = -150;
      break;
    case 3: //Front Left
      ::dirAngle = -120;
      break;
    case 4: //Front Left
      ::dirAngle = -90;
      break;
    case 5: //Front
      ::dirAngle = 0;
      break;
    case 6: //Front Right
      ::dirAngle = 90;
      break;
    case 7: //Front Right
      ::dirAngle = 120;
      break;
    case 8: //Back Right
      ::dirAngle = 150;
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
