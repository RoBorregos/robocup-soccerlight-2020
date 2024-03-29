void center(){
  // Center robot to the goal.
  pixy.ccc.getBlocks();
  if(pixy.ccc.numBlocks && pixy.ccc.blocks[0].m_signature == SIG){
    while(pixy.ccc.blocks[0].m_x < 158 - Ptol || pixy.ccc.blocks[0].m_x > 158 + Ptol){
      if(pixy.ccc.blocks[0].m_x < 158 - Ptol){
        robot.turnLeft(70);
        Serial.println("Pixy Turn Left");
      }
      else if(pixy.ccc.blocks[0].m_x > 158 + Ptol){
        robot.turnRight(70);
        Serial.println("Pixy Turn Right");
      }
      pixy.ccc.getBlocks();
      robot.stopMotors();
    }
    Serial.println("Pixy okay");
    robot.stopMotors();
  }
  else{
    Serial.println("Pixy nothing detected");
  }
}


void pixyUpdate(){
  // Save goal position.
  pixy.ccc.getBlocks();
  if(pixy.ccc.numBlocks && pixy.ccc.blocks[0].m_signature == SIG){
    if(pixy.ccc.blocks[0].m_x < 158 - Ptol){
      Ppos = 1; // Goal to the left.
      Serial.println("Porteria a la izquierda");
    }
    else if(pixy.ccc.blocks[0].m_x > 158 + Ptol){
      Ppos = 3; // Goal to the right.
      Serial.println("Porteria a la derecha");
    }
    else{
      Ppos = 2; // Goal to the front.
      Serial.println("Porteria al frente");
    }
  }
}
