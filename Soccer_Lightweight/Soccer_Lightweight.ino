/* 
 * Soccer Lightweight Junior 2020
 * Created by RoBorregos member Keven G. Arroyo
 */

#include <Adafruit_BNO055.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_VL53L0X.h>
#include <HTInfraredSeeker.h>
#include <math.h>
#include <Pixy2.h>
#include <SoftwareSerial.h>
#include <utility/imumaths.h>
#include <Wire.h>

/* Bluetooth Object */
SoftwareSerial Blue(10, 11); // RX, TX

/* Function declarations */
bool bluetooth();
bool bouncing();
int error(float, float);
int orientationStatus();
void angleFix();
void angleTurn(int, int);
void center();
void defense();
void lines();
void motors(int);
void PixyUpdate();
void seeker();
void turn(bool, int);

/* Bluetooth Declaration */
const bool RAND = true; // change depending of robot
unsigned long long CurrentTime = 0;

/* Pixy Object */
Pixy2 pixy;
int Ppos = 0;
int Ptol = 50;

/* Pixy Color Code */
const int SIG = 2; // 1 = Blue, 2 = Yellow 

/* Function degrees to radians */
float degToRad(int dir){
  return (dir * M_PI / 180);
}

/* LED Variables */
const int LEDPIN = 13;

/* BNO055 Variables */
#define BNO055_SAMPLERATE_DELAY_MS (100)
const int TOLERANCE = 20; // find lowest tolerance
int fix = 0;
int BNOSetPoint = 0;
unsigned long long angleFixTime = 0;

/* BNO055 Object */
Adafruit_BNO055 bno = Adafruit_BNO055(-1, 0x28);

/* VL53L0X Object */
Adafruit_VL53L0X lox = Adafruit_VL53L0X();

/* VL53L0X Variable */
const int RANGE = 35;

/* Motors Variables */
volatile int dirAngle = 0;  // direction angle for motors

const int MOTOR1A = 8; 
const int MOTOR1B = 9;
const int MOTOR2A = 6; 
const int MOTOR2B = 7;
const int MOTOR3A = 4; 
const int MOTOR3B = 5;

/* Photoresistors Variables */
const int NANOPIN1 = 52;

/* Interrupt Variables */
const int INTERRUPT = 2;
volatile int linesCount = 0;
unsigned long long timeTrack = 0;
bool bounce = false;

void setup() {
  /* Initialize serial communication */
  Serial.begin(9600);
  Serial.println("Setup");

  /* Initialize bluetooth communication */
  Blue.begin(9600);
  
  /* BNO055 Setup */
  while(!bno.begin())
  {
    Serial.println("No BNO055 detected ...");
    delay(10);
  }
  delay(1);
  bno.setExtCrystalUse(true);

  Serial.println("BNO055 detected");

  /* BNO055 Calibration Check */
  while(orientationStatus() < 1)
  {
    digitalWrite(LEDPIN, HIGH);
    delay(50);
  }
  digitalWrite(LEDPIN, LOW);
  
  Serial.println("Calibrated");

  delay(10);

  sensors_event_t event;
  bno.getEvent(&event);
  BNOSetPoint = event.orientation.x;
  
  /* Motors Setup */
  pinMode(MOTOR1A, OUTPUT);
  pinMode(MOTOR1B, OUTPUT);
  pinMode(MOTOR2A, OUTPUT);
  pinMode(MOTOR2B, OUTPUT);
  pinMode(MOTOR3A, OUTPUT);   
  pinMode(MOTOR3B, OUTPUT);

  /* Seeker Setup */
  InfraredSeeker::Initialize();

  /* Pixy Setup */
  pixy.init();

  /* VL53L0X Setup */
  Serial.println("VL53L0X Setup");
  if(!lox.begin()) {
    Serial.println(F("Failed to boot VL53L0X"));
    while(1);
  }
  Serial.println("VL53L0X Working"); 
  
  /* Comm Setup*/
  pinMode(NANOPIN1, INPUT);

  /* Interrupt Setup */
  attachInterrupt(digitalPinToInterrupt(INTERRUPT), lines, RISING); // change 2 to pin selected, RISING - Low to high, HIGH - High
  CurrentTime = millis(); 
}

// the loop function runs over and over again forever
void loop() {   
  if(millis() > CurrentTime + 1500){ // one robot every 1500, another one every 1600
    // check if robot should be defense or offense
    CurrentTime = millis();
    if(bluetooth()){
      seeker();
    }
    else{
      defense();
    }
  }
  seeker();
  angleFix();
  timeTrack = millis();
  cli(); // disable interrupts
  bounce = bouncing();
  sei(); // enable interrupts
  if(bounce){
    delay(300);
  }
}
