

float error(float actual, float final = 0){ 
  /*  actual y final siendo angulos de 0 al 360
      regresa un angulo
      angulo positivo si es a la derecha
      angulo negativo si es a la izquierda */
  float total = final-actual;
  if (total > 180){
    total = -(360-total);
  }
  else if (total < -180){
    total = 360 + total;
  }
  return total;
}

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}
