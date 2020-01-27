void lines2(){
  /* Read data from arduino nano and act accordingly */
  Serial.println("Linea detectada");
  
  // regresar angulo
  
  int nano1 = digitalRead(NANOPIN1);
  int nano2 = digitalRead(NANOPIN2);
  int nano3 = digitalRead(NANOPIN3);
  int nano4 = digitalRead(NANOPIN4);
  int nano5 = digitalRead(NANOPIN5);

  int whites[5] = {nano1, nano2, nano3, nano4, nano5};
  /* [ Front, Right, Left, Back Right, Back Left ] */ 
  /* Aerial View */
  int sum_whites = 0;
  for (int i: whites){
    sum_whites += i;
  }
  if (sum_whites == 0){
    return;
  }
  ::dirAngle += 180;
  delayMicroseconds(100000); // 100,000 = 0.1 segundos
}
