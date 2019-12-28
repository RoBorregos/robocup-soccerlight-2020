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
      //TODO
      break;
  }
  
}
