const int motor1A = 6; 
const int motor1B = 7;

const int motor2A = 2; 
const int motor2B = 3;

const int motor3A = 4; 
const int motor3B = 5;
int power = 255;

float deg(float dir){
  // return radians from degrees
  return (dir * 71) / 4068;
}

void motors(int dir){
  // set motors to move in direction dir degrees
  float A = cos(deg(150-dir));
  float B = cos(deg(30-dir));
  float C = cos(deg(270-dir));
  int speedA = int(A*255);
  int speedB = int(B*255);
  int speedC = int(C*255);
  
  if (A >= 0){
    analogWrite(motor1A, speedA);
    analogWrite(motor1B, 0);
  }
  else {
    analogWrite(motor1A, 0);
    analogWrite(motor1B, abs(speedA));
  }
  if (B >= 0){
    analogWrite(motor2A, speedB);
    analogWrite(motor2B, 0);
  }
  else {
    analogWrite(motor2A, 0);
    analogWrite(motor2B, abs(speedB));
  }
  if (C >= 0){
    analogWrite(motor3A, speedC);
    analogWrite(motor3B, 0);
  }
  else {
    analogWrite(motor3A, 0);
    analogWrite(motor3B, abs(speedC));
  }
}

void turn(bool dir){
  if (dir) { // true turns right
    analogWrite(motor1A, 0);
    analogWrite(motor1B, 255);
    analogWrite(motor2A, 0);
    analogWrite(motor2B, 255);
    analogWrite(motor3A, 0);
    analogWrite(motor3B, 255);
  }
  if (!dir) { // false turns left
    analogWrite(motor1A, 255);
    analogWrite(motor1B, 0);
    analogWrite(motor2A, 255);
    analogWrite(motor2B, 0);
    analogWrite(motor3A, 255);
    analogWrite(motor3B, 0);
  }
}

void motorsOFF(){
  // turn Off all motors
  analogWrite(motor1A, 0);
  analogWrite(motor1B, 0);
  analogWrite(motor2A, 0);
  analogWrite(motor2B, 0);
  analogWrite(motor3A, 0);
  analogWrite(motor3B, 0);
}

void star(){
  motors(0);
  delay(1000);
  motors(180);
  delay(1000);
  motors(45);
  delay(1000);
  motors(225);
  delay(1000);
  motors(90);
  delay(1000);
  motors(270);
  delay(1000);
  motors(135);
  delay(1000);
  motors(315);
  delay(1000);
  motors(180);
  delay(1000);
  motors(0);
  delay(1000);
  motors(225);
  delay(1000);
  motors(45);
  delay(1000);
  motors(270);
  delay(1000);
  motors(90);
  delay(1000);
  motors(315);
  delay(1000);
  motors(136);
  delay(1000);
  motors(360);
  delay(1000);
  motors(180);
  delay(1000);
}

void setup() {
  // Setup motors
  pinMode(motor1A, OUTPUT);
  pinMode(motor1B, OUTPUT);
  pinMode(motor2A, OUTPUT);
  pinMode(motor2B, OUTPUT);
  pinMode(motor3A, OUTPUT);   
  pinMode(motor3B, OUTPUT);

  // Set up Serial
  Serial.begin(9600);

  delay(2000);
  star();
  motorsOFF();

}

void loop() {
}
