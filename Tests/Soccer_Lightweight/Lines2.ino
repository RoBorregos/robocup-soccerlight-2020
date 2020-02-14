void lines2(){
  /* Read data from arduino nano and act accordingly */
  Serial.println("Linea detectada");

  linesCount++;

  ::dirAngle += 180;
  motors(::dirAngle);

  bool front = digitalRead(NANOPIN1);
  bool right = digitalRead(NANOPIN2);
  bool left = digitalRead(NANOPIN3);
  /*
  bool backright = digitalRead(NANOPIN4);
  bool backleft = digitalRead(NANOPIN5);
  */

  while(front || left || front){
    front = digitalRead(NANOPIN1);    
    right = digitalRead(NANOPIN2);
    left = digitalRead(NANOPIN3);
  }
  /*
  if(left || backleft){
    while(left || backleft){
      left = digitalRead(NANOPIN3);
      backleft = digitalRead(NANOPIN5);
    }
  }
  else if(right || backright){
    while(right || backright){
      right = digitalRead(NANOPIN2);
      backright = digitalRead(NANOPIN4);
    }
  }
  */
  // delayMicroseconds(100000); // 100,000 = 0.1 seconds
}
