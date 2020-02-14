int mux(bool i, bool j, bool k, bool l){
  /* Read phototransistors from multiplexer */

  digitalWrite(S0, i);
  digitalWrite(S1, j);
  digitalWrite(S2, k);
  digitalWrite(S3, l);

  return analogRead(SIG); 
}

void lines(){
  /* Function to update values of pr arrays*/

  // whites[0]
  pr_front[0] = mux(0,0,0,1);
  delay(50);
  pr_front[1] = mux(0,0,1,0);
  delay(50);
  pr_front[2] = mux(0,0,1,1);
  delay(50);
  pr_front[3] = mux(0,1,0,0);
  delay(50);
  pr_front[4] = mux(0,1,0,1);
  delay(50);

  // whites[1]
  pr_right[0] = mux(0,1,1,0);
  delay(50);
  pr_right[1] = mux(0,1,1,1);
  delay(50);
  pr_right[2] = mux(1,0,0,0);
  delay(50);
  pr_right[3] = mux(1,0,0,1);
  delay(50);
  pr_right[4] = mux(1,0,1,0);
  delay(50);

  // whites[2]
  pr_left[0] = mux(1,0,1,1);
  delay(50);
  pr_left[1] = mux(1,1,0,0);
  delay(50);
  pr_left[2] = mux(1,1,0,1);
  delay(50);
  pr_left[3] = mux(1,1,1,0);
  delay(50);
  pr_left[4] = mux(1,1,1,1);
  delay(50);
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
}

void photoresistors(){
  /* Function to detect if photoresistors detect a white line */

  int range = 900; // number at which a white line is detected

  front = 0;
  right = 0;
  left = 0;
  
  for (int i:pr_front){
    if (i > range){
      front = 1;
      break;
    }
  }
  for (int i:pr_right){
    if (i > range){
      right = 1;
      break;
    }
  }
  for (int i:pr_left){
    if (i > range){
      left = 1;
      break;
    }
  }
}
