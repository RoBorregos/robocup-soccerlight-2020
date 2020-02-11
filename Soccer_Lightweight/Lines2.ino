void lines2(){
  /* Read data from arduino nano and act accordingly */
  Serial.println("Linea detectada");

  linesCount++;

  
  if(::dirAngle > 0){
    ::dirAngle -= 180;
  }
  else{
    ::dirAngle += 180;
  }

  motors(::dirAngle);

  //turn(true);

  bool nano;
  
  do{
    nano = digitalRead(NANOPIN1); 
  }
  while(nano);
  
  delayMicroseconds(500000); // 100,000 ms = 0.1 s
}
