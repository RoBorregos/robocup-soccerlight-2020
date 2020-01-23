void lines(){
  /* Function to update values of pr arrays*/

  // whites[0]
  pr_front[0] = mux(0,0,0,0);
  pr_front[1] = mux(0,0,0,1);
  pr_front[2] = mux(0,0,1,0);
  pr_front[3] = mux(0,0,1,1);
  pr_front[4] = mux(0,1,0,0);

  // whites[1]
  pr_right[0] = mux(0,1,0,1);
  pr_right[1] = mux(0,1,1,0);
  pr_right[2] = mux(0,1,1,1);
  pr_right[3] = mux(1,0,0,0);
  pr_right[4] = mux(1,0,0,1);

  // whites[2]
  pr_left[0] = mux(1,0,1,0);
  pr_left[1] = mux(1,0,1,1);
  pr_left[2] = mux(1,1,0,0);
  pr_left[3] = mux(1,1,0,1);
  pr_left[4] = mux(1,1,1,0);

  // whites[3]
  pr_backright[0] = analogRead(PR1);
  pr_backright[1] = analogRead(PR2);


  // whites[4]
  pr_backleft[0] = analogRead(PR3);
  pr_backleft[1] = analogRead(PR4);;
}

int mux(bool i, bool j, bool k, bool l){
  /* Read phototransistors from multiplexer */

  digitalWrite(S0, i);
  digitalWrite(S1, j);
  digitalWrite(S2, k);
  digitalWrite(S3, l);

  return analogRead(SIG); 
}

void linesPrint(){
  Serial.println("Front");
  for (int i:pr_front){
    Serial.print(i);
    Serial.print("  ");
    }
  Serial.println();

  Serial.println("Right");
  for (int i:pr_right){
    Serial.print(i);
    Serial.print("  ");
    }
  Serial.println();

  Serial.println("Left");
  for (int i:pr_left){
    Serial.print(i);
    Serial.print("  ");
    }
  Serial.println();

  Serial.println("Back Right");
  for (int i:pr_backright){
    Serial.print(i);
    Serial.print("  ");
    }
  Serial.println();

  Serial.println("Back Left");
  for (int i:pr_backleft){
    Serial.print(i);
    Serial.print("  ");
    }
  Serial.println();
  
}
