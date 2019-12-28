int error(float actual, float final = 0){ 
  /*  actual y final siendo angulos de 0 al 360
      regresa un angulo
      angulo positivo si es a la derecha
      angulo negativo si es a la izquierda */
  int total = final-actual;
  if (total > 180){
    total = -(360-total);
  }
  else if (total < -180){
    total = 360 + total;
  }
  return total;
}

void BNOAngleCheck()
{
  sensors_event_t event;
  bno.getEvent(&event);
  orientationAngle = ((int(event.orientation.x) - BNOSetPoint) + 360) % 360;
  Serial.println(orientationAngle);
}

void angleFix(){
  BNOAngleCheck();

  if(millis() < angleFixTime + 15){
    return;
  }
  
  angleFixTime = millis();
  int fix = error(orientationAngle);
  if(abs(fix) > 20){
    while(abs(fix) > 20){
      if(fix > 20){
        turn(true);
      }
      else{
        turn(false);
      }
      BNOAngleCheck();
      int fix = error(orientationAngle);
    }
    motorsOff();
  } 
}
