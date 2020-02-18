void center(){
  pixy.ccc.getBlocks();
  if(pixy.ccc.numBlocks && pixy.ccc.blocks[0].m_signature == SIG){
    while(pixy.ccc.blocks[0].m_x < 158 - Ptol || pixy.ccc.blocks[0].m_x > 158 + Ptol){
      if(pixy.ccc.blocks[0].m_x < 158 - Ptol){
        turn(false, 255);
        Serial.println("Pixy Turn Right");
      }
      else if(pixy.ccc.blocks[0].m_x > 158 + Ptol){
        turn(true, 255);
        Serial.println("Pixy Turn Left");
      }
      pixy.ccc.getBlocks();
      motorsOff();
    }
  motorsOff();
  }
}

void PixyUpdate(){
  // save goal position
  pixy.ccc.getBlocks();
  if(pixy.ccc.numBlocks && pixy.ccc.blocks[0].m_signature == SIG){
    if(pixy.ccc.blocks[0].m_x < 158 - Ptol){
      Ppos = 1; // porteria a la izquierda
    }
    else if(pixy.ccc.blocks[0].m_x > 158 + Ptol){
      Ppos = 3; // porteria a la derecha
    }
    else{
      Ppos = 2;
    }
  }
}
