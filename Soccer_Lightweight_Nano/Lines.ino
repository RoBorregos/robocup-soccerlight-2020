void lines(){
  /* Function to update values of pr arrays*/

  // whites[0]
  pr_front[0] = mux.read(0);
  pr_front[1] = mux.read(1);
  pr_front[2] = mux.read(2);
  pr_front[3] = mux.read(3);
  pr_front[4] = mux.read(4);;

  // whites[1]
  pr_right[0] = mux.read(5);
  pr_right[1] = mux.read(6);
  pr_right[2] = mux.read(7);
  pr_right[3] = mux.read(8);
  pr_right[4] = mux.read(9);

  // whites[2]
  pr_left[0] = mux.read(10);
  pr_left[1] = mux.read(11);
  pr_left[2] = mux.read(12);
  pr_left[3] = mux.read(13);
  pr_left[4] = mux.read(14);

  /*
  // whites[3]
  pr_backright[0] = analogRead(PR1);
  pr_backright[1] = analogRead(PR2);


  // whites[4]
  pr_backleft[0] = analogRead(PR3);
  pr_backleft[1] = analogRead(PR4);;
  */
}

void interrupt(){
  if(front || right || left) {
    digitalWrite(INTRR, 1);
    delay(50);
    digitalWrite(INTRR, 0);
  }
}

void linesPrint(){
  Serial.print("Front = ");
  Serial.println(front);
  for (int i:pr_front){
    Serial.print(i);
    Serial.print("  ");
    }
  Serial.println();

  Serial.print("Right = ");
  Serial.println(right);
  for (int i:pr_right){
    Serial.print(i);
    Serial.print("  ");
    }
  Serial.println();

  Serial.print("Left = ");
  Serial.println(left);
  for (int i:pr_left){
    Serial.print(i);
    Serial.print("  ");
    }
  Serial.println();

  Serial.print("Back Right = ");
  Serial.println(backright);
  for (int i:pr_backright){
    Serial.print(i);
    Serial.print("  ");
    }
  Serial.println();

  Serial.print("Back Left = ");
  Serial.println(backleft);
  for (int i:pr_backleft){
    Serial.print(i);
    Serial.print("  ");
    }
  Serial.println();
  
}
