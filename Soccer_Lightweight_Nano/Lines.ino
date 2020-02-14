void lines(){
  pr[0] = mux.read(0);
  pr[1] = mux.read(1);
  pr[2] = mux.read(2);
  pr[3] = mux.read(3);
  pr[4] = mux.read(4);;

  pr[5] = mux.read(5);
  pr[6] = mux.read(6);
  pr[7] = mux.read(7);
  pr[8] = mux.read(8);
  pr[9] = mux.read(9);

  pr[10] = mux.read(10);
  pr[11] = mux.read(11);
  pr[12] = mux.read(12);
  pr[13] = mux.read(13);
  pr[14] = mux.read(14);
}

void linesPrint(){
  for (int i = 0; i < 15; i++){
      if (i==0){
        Serial.print(" ");
        Serial.println("Left");
      }
      if (i==5){
        Serial.print(" ");
        Serial.print("Right");
      }
      if (i==10){
        Serial.print(" ");
        Serial.println("Front");
      }
      Serial.print("  ");
      Serial.print(pr[i]);
  
      if (i == 4 || i == 9 || i == 14){
        Serial.print("         " );
        Serial.println();
      }  
  }

}
