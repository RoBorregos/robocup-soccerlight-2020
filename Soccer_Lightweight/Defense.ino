void defense(){
  InfraredResult InfraredBall = InfraredSeeker::ReadAC(); 
  // Get seeker direction.
  Serial.print("Direction = ");
  switch(InfraredBall.Direction){
    case 1: // Back Left.
      ::dirAngle = 180;
      Serial.println("180");
      break;
    case 2: // Back Left.
      ::dirAngle = -150;
      Serial.println("-150");
      break;
    case 3: // Front Left.
      ::dirAngle = -90;
      Serial.println("-120");
      break;
    case 4: // Front Left.
      ::dirAngle = -90;
      Serial.println("-90");
      break;
    case 5: // Front.
      ::dirAngle = 0;
      Serial.println("0");
      break;
    case 6: // Front Right.
      ::dirAngle = 90;
      Serial.println("90");
      break;
    case 7: // Front Right.
      ::dirAngle = 90;
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
  if(InfraredBall.Direction == 0){
    motorsOff();
    Serial.println("Off");
  }
  else{
    motors(::dirAngle);
  }
}
