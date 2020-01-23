void lines(){
  /* Read data from arduino nano and act accordingly */
  Serial.println("Linea detectada");
  
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

  /* Combinations Total = 31 */   
  
  /* Combinations for 5/5 */
  if (sum_whites == 5){
    turn(true);
  }
  
  /* Combinations for 4/5 */
  else if (whites[0] && whites[1] && whites[2] && whites[3]) {
    motors(-150);
  }
  else if (whites[0] && whites[1] && whites[2] && whites[4]) {
    motors(150);
  }
  else if (whites[0] && whites[1] && whites[3] && whites[4]) {
    motors(-60);
  }
  else if (whites[0] && whites[2] && whites[3] && whites[4]) {
    motors(60);
  }
  else if (whites[1] && whites[2] && whites[3] && whites[4]) {
    motors(0);
  }

  /* Combinations for 3/5 */
  else if (whites[0] && whites[1] && whites[2]) {
    motors(180);
  }
  else if (whites[0] && whites[1] && whites[3]) {
    motors(-90);
  }
  else if (whites[0] && whites[1] && whites[4]) {
    motors(-45);
  }
  else if (whites[0] && whites[2] && whites[3]) {
    motors(45);
  }
  else if (whites[0] && whites[2] && whites[4]) {
    motors(90);
  }
  else if (whites[0] && whites[3] && whites[4]) {
    motors(180);
  }
  else if (whites[1] && whites[2] && whites[3]) {
    motors(180);
  }
  else if (whites[1] && whites[2] && whites[4]) {
    motors(180);
  }
  else if (whites[1] && whites[3] && whites[4]) {
    motors(-45);
  }
  else if (whites[2] && whites[3] && whites[4]) {
    motors(45);
  }
  
  /* Combinations for 2/5 */
  else if (whites[0] && whites[1]) {
    motors(-90);
  }
  else if (whites[0] && whites[2]) {
    motors(90);
  }
  else if (whites[0] && whites[3]) {
    motors(-15);
  }
  else if (whites[0] && whites[4]) {
    motors(15);
  }
  else if (whites[1] && whites[2]) {
    motors(180);
  }
  else if (whites[1] && whites[3]) {
    motors(-45);
  }
  else if (whites[1] && whites[4]) {
    motors(-15);
  }
  else if (whites[2] && whites[3]) {
    motors(15);
  }
  else if (whites[2] && whites[4]) {
    motors(45);
  }
  else if (whites[3] && whites[4]) {
    motors(0);
  }

  /* Combinations for 1/5 */
  else if (whites[0]){
    motors(180);
  }
  else if (whites[1]){
    motors(-60);
  }
  else if (whites[2]){
    motors(60);
  }
  else if (whites[3]){
    motors(-30);
  }
  else if (whites[4]){
    motors(30);
  }
  
  delayMicroseconds(100000); // 100,000 = 0.1 segundos
}
