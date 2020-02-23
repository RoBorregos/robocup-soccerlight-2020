void center(){
  // center robot to the goal
  pixy.ccc.getBlocks();
  if(pixy.ccc.numBlocks && pixy.ccc.blocks[0].m_signature == SIG){
    while(pixy.ccc.blocks[0].m_x < 158 - Ptol || pixy.ccc.blocks[0].m_x > 158 + Ptol){
      if(pixy.ccc.blocks[0].m_x < 158 - Ptol){
        turn(true, 255);
        Serial.println("Pixy Turn Left");
      }
      else if(pixy.ccc.blocks[0].m_x > 158 + Ptol){
        turn(false, 255);
        Serial.println("Pixy Turn Right");
      }
      pixy.ccc.getBlocks();
      motorsOff();
    }
    Serial.println("Pixy okay");
  motorsOff();
  }
  else{
    Serial.println("nothing detected");
  }
}

void PixyUpdate(){
  // save goal position
  pixy.ccc.getBlocks();
  if(pixy.ccc.numBlocks && pixy.ccc.blocks[0].m_signature == SIG){
    if(pixy.ccc.blocks[0].m_x < 158 - Ptol){
      Ppos = 1; // porteria a la izquierda
      Serial.println("Porteria a la izquierda");
    }
    else if(pixy.ccc.blocks[0].m_x > 158 + Ptol){
      Ppos = 3; // porteria a la derecha
      Serial.println("Porteria a la derecha");
    }
    else{
      Ppos = 2; // porteria al frente
      Serial.println("Porteria al frente");
    }
  }
}
