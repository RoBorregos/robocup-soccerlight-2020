void seeker2(){
  InfraredResult InfraredBall = InfraredSeeker::ReadAC();
  switch(InfraredBall.Direction){
    case 1: //Back Left
      ::dirAngle = 0;
      break;
    case 2: //Back Left
      ::dirAngle = 0;
      break;
    case 3: //Front Left
      ::dirAngle = 0;
      break;
    case 4: //Front Left
      ::dirAngle = 0;
      break;
    case 5: //Front
      ::dirAngle = 0;
      break;
    case 6: //Front Right
      ::dirAngle = 0;
      break;
    case 7: //Front Right
      ::dirAngle = 0;
      break;
    case 8: //Back Right
      ::dirAngle = 0;
      break;
    case 9: //Back Right
      ::dirAngle = 0;
      break;
    case 0: //Back
      ::dirAngle = 0;
      break;
  } 
  motors(::dirAngle);
}
