// Soccer Lightweight Junior 2020.
// Created by RoBorregos

#include <Adafruit_BNO055.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_VL53L0X.h>
#include <HTInfraredSeeker.h>
#include <math.h>
#include <Pixy2.h>
#include <utility/imumaths.h>
#include <Wire.h>
#include <Motors.h>

bool bouncing();
int error(float, float);
int orientationStatus();
void angleFix();
void angleTurn(int, int);
void center();
void defense();
void lines();
void pixyUpdate();
void seeker();


// Pixy Object.
Pixy2 pixy;
int Ppos = 0;
int Ptol = 50;

const int SIG = 2; 
// Pixy Color Code.
//  1 = Blue Goal.
//  2 = Yellow Goal.

// Function degrees to radians.
float degToRad(int dir){
  return (dir * M_PI / 180);
}

// LED Variables.
const int LEDPIN = 13;
const int LEDPIN1 = 27;
const int LEDPIN2 = 29;
const int LEDPIN3 = 31;
const int LEDPIN4 = 33;
const int LEDPIN5 = 35;
const int LEDPIN6 = 37;

// BNO055 Variables.
#define BNO055_SAMPLERATE_DELAY_MS (100)
const int TOLERANCE = 12;   // Find lowest tolerance for turns.
int fix = 0;
int BNOSetPoint = 0;
unsigned long long angleFixTime = 0;
float BNO_START = 0;

// BNO055 Object.
Adafruit_BNO055 bno = Adafruit_BNO055(-1, 0x28);

// VL53L0X Object.
Adafruit_VL53L0X lox = Adafruit_VL53L0X();

// VL53L0X Variable.
const int RANGE = 50;

// Motors Variables.
volatile int dirAngle = 0;  // Direction angle for motors.
Motors robot(4,3,8,7,6,5);

// Photoresistors Variables.
const int NANOPIN1 = 22; 

// Interrupt Variables.
const int INTERRUPT = 2;
volatile int linesCount = 0;
unsigned long long timeTrack = 0;
bool bounce = false;

void setup() {
  // Initialize serial communication.
  Serial.begin(9600);
  Serial.println("Setup");

  robot.InitializeMotors();
  
  pinMode(LEDPIN1, OUTPUT);
  pinMode(LEDPIN2, OUTPUT);
  pinMode(LEDPIN3, OUTPUT);
  pinMode(LEDPIN4, OUTPUT);
  pinMode(LEDPIN5, OUTPUT);
  pinMode(LEDPIN6, OUTPUT);
  
  digitalWrite(LEDPIN3, HIGH); // On LED
  
  // VL53L0X Setup.
  Serial.println("VL53L0X Setup");
  while(!lox.begin()) {
    Serial.println(F("Failed to boot VL53L0X"));
  }
  Serial.println("VL53L0X Working"); 
  
  // BNO055 Setup.
  while(!bno.begin())
  {
    Serial.println("No BNO055 detected ...");
    delay(10);
  }
  delay(1);
  bno.setExtCrystalUse(true);
  Serial.println("BNO055 Working");
  
  // BNO055 Calibration Check.
  while(orientationStatus() != 2)
  {
    digitalWrite(LEDPIN2, HIGH);
    delay(50);
    digitalWrite(LEDPIN2, LOW);
    delay(50);
  }
  while(orientationStatus() != 3)
  {
    digitalWrite(LEDPIN2, HIGH);
    delay(50);
    digitalWrite(LEDPIN2, LOW);
    delay(50);
  }  
  digitalWrite(LEDPIN2, HIGH);
  delay(200);
  digitalWrite(LEDPIN2, LOW);

  sensors_event_t event;
  bno.getEvent(&event);
  BNOSetPoint = event.orientation.x;

  imu::Vector<3> euler = bno.getVector(Adafruit_BNO055::VECTOR_EULER);
  BNO_START = euler.x();
    
  Serial.println("BNO055 Calibrated");

  // Seeker Setup.
  InfraredSeeker::Initialize();

  // Pixy Setup.
  pixy.init();
  
  // Comm Setup.
  pinMode(NANOPIN1, INPUT);

  // Interrupt Setup.
  attachInterrupt(digitalPinToInterrupt(INTERRUPT), lines, RISING);
  
}

// The loop function runs over and over again forever.
void loop() {   
   seeker();
   angleFix();
  /*
  timeTrack = millis();
  cli(); // Disable interrupts.
  bounce = bouncing();
  sei(); // Enable interrupts.
  if(bounce){
    delay(300);
  }
  */
}
