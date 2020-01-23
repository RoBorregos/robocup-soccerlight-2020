void photoresistors(){
  /* Function to detect if photoresistors detect a white line */
  int range = 500; // number at which a white line is detected
  
  bool front = 0;
  bool right = 0;
  bool left = 0;
  bool backright = 0;
  bool backleft = 0;
  
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
  for (int i:pr_backright){
    if (i > range){
      backright = 1;
      break;
    }
  }
  for (int i:pr_backleft){
    if (i > range){
      backleft = 1;
      break;
    }
  }
  commsToMega(front, right, left, backright, backleft);
}

void commsToMega(bool i, bool j, bool k, bool l, bool m){
  /* Send values to Mega */
  digitalWrite(COMPIN1, i);
  digitalWrite(COMPIN2, j);
  digitalWrite(COMPIN3, k);
  digitalWrite(COMPIN4, l);
  digitalWrite(COMPIN5, m);
}
