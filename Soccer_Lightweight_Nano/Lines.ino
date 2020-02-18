void linesPrint(){
  for (int i = 0; i < 15; i++){
      if (i == 0){
        Serial.println("\nLeft");
      }
      if (i == 5){
        Serial.println("\nRight");
      }
      if (i == 10){
        Serial.println("\nFront");
      }
      
      Serial.print(mux.read(i));
      Serial.print("\t");
  }

  /*
  for (int i = 0; i < 15; i++){
    if (i == 0){
        Serial.println("\nBackLeft");
      }
      if (i == 2){
        Serial.println("\nBackRight");
      }
      Serial.print(analogRead(PR[i]));
      Serial.print("\t");
  }
  */
  
}
