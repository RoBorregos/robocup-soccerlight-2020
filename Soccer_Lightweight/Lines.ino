void lines(){
  // Read data from arduino nano & reverse motors.
  Serial.println("Linea detectada");

  linesCount++;

  // Change direction of motors by 180.
  // ::dirAngle = (::dirAngle >= 0) ? ::dirAngle -= 180 : ::dirAngle += 180;
  
  if(::dirAngle > 0){
    ::dirAngle -= 180;
  }
  else{
    ::dirAngle += 180;
  }
  
 robot.moveMotors(::dirAngle, 255);

  bool nano;

  // Delay given by digitalRead.
  do{
    nano = digitalRead(NANOPIN1); 
  }
  while(nano);
  
  delayMicroseconds(500000); // 100,000 ms = 0.1 s
}
