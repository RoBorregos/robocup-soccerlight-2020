bool bluetooth(){
  // Receive and send a byte through bluetooth.
  // Return false if ball is not in range.
  // Return true if ball is in range.
  byte sending;
  byte receiving;
  VL53L0X_RangingMeasurementData_t measure;
  lox.rangingTest(&measure, false);
  InfraredResult InfraredBall = InfraredSeeker::ReadAC();
  if(measure.RangeStatus != 4 && measure.RangeMilliMeter <= RANGE && InfraredBall.Direction == 5) {
    sending = 1; // true
    if(Blue.available()){
      Blue.write(sending);
    }
  }
  else{
    sending = 0; // false
    if(Blue.available()){
      Blue.write(sending);
    }
  }
  
  if(Blue.available()){   // recibir datos por blue
    receiving = Blue.read();
  }
  
  else{
    receiving = false; // si no se puede recibir interpretar falso
  }
  
  if(!sending && !receiving){ // se mando falso y se recibio falso
    return RAND;
  }
  if(!sending && receiving){ // se mando falso y se recibio verdadero
    return false;
  }
  if(sending && !receiving){ // se mando verdadero y se recibio falso
    return true;
  }
  if(sending && receiving){ // se mando verdadero y se recibio verdadero
    return true;
  }
  return true;
}
