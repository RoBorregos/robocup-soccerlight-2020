bool photoresistors(){
  for(int i = 0; i < 15; i++){
    if(mux.read(i) > RANGO){
       return true;
    }
  }

  /*
  for (int i = 0; i < 4; i++) {
    if(analogRead(PR[i]) > RANGO){
      return true;
    }
  }
  */
    
 return false;
}

void interrupt(){
  bool i = photoresistors();
  
  digitalWrite(INTRR, i);
  digitalWrite(COMPIN1, i);

  // Artificial delay for Mega.
  if(i){
    digitalWrite(COMPIN1, i);
    delay(400);
  }

  // Attempt at a better implementation of a delay.
  /*
  if(i){
    timeTrack = millis();
    bool j;
    
    while(timeTrack + 600 > millis()){
      digitalWrite(COMPIN1, true);
      if(!photoresistors()){
        j = true;
      }
      if(j && photoresistors(){
        digitalWrite(INTRR, false);
        delay(15);
        digitalWrite(INTRR, true);
        j = false;
      }
    }
  }
  */
  
  // Serial.println(i);
}
