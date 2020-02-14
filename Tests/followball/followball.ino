#include <HTInfraredSeeker.h>

const int motor1A = 6; 
const int motor1B = 7;

const int motor2A = 2; 
const int motor2B = 3;

const int motor3A = 4; 
const int motor3B = 5;

int power = 100;

float deg(float dir){
  // return radians from degrees
  return (dir * 71) / 4068;
}

void motors(int dir){
  // set motors to move in direction dir degrees
  dir = 360 - dir;
  float m1 = cos(deg(150-dir));
  float m2 = cos(deg(30-dir));
  float m3 = cos(deg(270-dir));
  int speedA = int(m1*power);
  int speedB = int(m2*power);
  int speedC = int(m3*power);
  
  if (m1 >= 0){
    analogWrite(motor1A, speedA);
    analogWrite(motor1B, 0);
  }
  else {
    analogWrite(motor1A, 0);
    analogWrite(motor1B, abs(speedA));
  }
  if (m2 >= 0){
    analogWrite(motor2A, speedB);
    analogWrite(motor2B, 0);
  }
  else {
    analogWrite(motor2A, 0);
    analogWrite(motor2B, abs(speedB));
  }
  if (m3 >= 0){
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
    analogWrite(motor1B, power);
    analogWrite(motor2A, 0);
    analogWrite(motor2B, power);
    analogWrite(motor3A, 0);
    analogWrite(motor3B, power);
  }
  if (!dir) { // false turns left
    analogWrite(motor1A, power);
    analogWrite(motor1B, 0);
    analogWrite(motor2A, power);
    analogWrite(motor2B, 0);
    analogWrite(motor3A, power);
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

void chace(){
  InfraredResult InfraredBall = InfraredSeeker::ReadAC();
  if(InfraredBall.Direction == 5){
    motors(0);
  }
  else if(InfraredBall.Direction == 0){
    motorsOFF();
  }
  else if(InfraredBall.Direction < 5){
    turn(false);
  }
  else{
    turn(true);
  }
}

void defend(){
  InfraredResult InfraredBall = InfraredSeeker::ReadAC();
  if(InfraredBall.Direction == 1){
    motors(-165);
  }
  if(InfraredBall.Direction == 2){
    motors(-135);
  }
  if(InfraredBall.Direction == 3){
    motors(-105);
  }
  if(InfraredBall.Direction == 4){
    motors(-75);
  }
  if(InfraredBall.Direction == 5){
    motors(0);
  }
  if(InfraredBall.Direction == 6){
    motors(75);
  }
  if(InfraredBall.Direction == 7){
    motors(105);
  }
  if(InfraredBall.Direction == 8){
    motors(135);
  }
  if(InfraredBall.Direction == 9){
    motors(165);
  }
  if(InfraredBall.Direction == 0){
    motorsOFF();
  }
}

void setup()
{
  Serial.begin(9600);
  // Setup motors
  pinMode(motor1A, OUTPUT);
  pinMode(motor1B, OUTPUT);
  pinMode(motor2A, OUTPUT);
  pinMode(motor2B, OUTPUT);
  pinMode(motor3A, OUTPUT);   
  pinMode(motor3B, OUTPUT);
  // Set up Serial
  Serial.begin(9600);
  // Setup seeker
  Serial.println("Dir\tStrength");
  Serial.println();
  InfraredSeeker::Initialize();
}

void loop()
{   
  // chace();
  defend();
}
