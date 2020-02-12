#include <Pixy2.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055.h>
#include <Adafruit_VL53L0X.h>
#include <utility/imumaths.h>
#include <math.h>
#include <Wire.h>
#include <HTInfraredSeeker.h>

/* Function declaration */
int error(float, float);
void angleFix();
void angleTurn(int, int);
void motors(int);
void turn(bool);
int orientationStatus();
void seeker();
void seeker2();
void lines();
void lines2();
bool bouncing();

/* Pixy Object */
Pixy2 pixy;

/* Function degrees to radians */
float degToRad(int dir){
  return (dir * M_PI / 180);
}

/* LED Variables */
const int LEDPIN = 13;

/* BNO055 Variables */
#define BNO055_SAMPLERATE_DELAY_MS (100)
const int TOLERANCE = 10; // find lowest tolerance

Adafruit_BNO055 bno = Adafruit_BNO055(-1, 0x28);

int fix = 0;
int BNOSetPoint = 0;
unsigned long long angleFixTime = 0;

/* VL53L0X Variables */
Adafruit_VL53L0X lox = Adafruit_VL53L0X();
const int RANGE = 35;

/* Motors Variables */
const int POWER = 255;

const int MOTOR1A = 8; 
const int MOTOR1B = 9;

const int MOTOR2A = 6; 
const int MOTOR2B = 7;

const int MOTOR3A = 4; 
const int MOTOR3B = 5;

volatile int dirAngle = 0;

/* Photoresisters Variables */
const int NANOPIN1 = 52;
const int NANOPIN2 = 1;
const int NANOPIN3 = 1;
const int NANOPIN4 = 1;
const int NANOPIN5 = 1;
const int NANOPIN6 = 1;

/* Interrupt Variables */
const int INTERRUPT = 2;
volatile int linesCount = 0;
unsigned long long timeTrack = 0;
bool bounce = false;

void setup() {
  /* Initialize serial communication */
  Serial.begin(9600);
  Serial.println("Setup");
  
  /* BNO055 Setup 
  while(!bno.begin())
  {
    Serial.println("No BNO055 detected ...");
    delay(10);
  }
  delay(1);
  bno.setExtCrystalUse(true);

  Serial.println("BNO055 detected");

  /* BNO055 Calibration Check 
  Adafruit_BNO055 BNO055;

  while(orientationStatus() != 3)
  {
    digitalWrite(LEDPIN, HIGH);
    delay(1000);
    digitalWrite(LEDPIN, LOW);
    delay(500);
  }
  Serial.println("Calibrated");

  for(int i = 0; i < 15; i++)
  {
    digitalWrite(LEDPIN, HIGH);
    delay(100);
    digitalWrite(LEDPIN, LOW);
    delay(100);
  }
  delay(1000);
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

  /* Pixy Setup 
  pixy.init();

  /* VL53L0X Setup 
  Serial.println("VL53L0X Setup");
  if (!lox.begin()) {
    Serial.println(F("Failed to boot VL53L0X"));
    while(1);
  }
  // power 
  Serial.println("VL53L0X Working"); 

  */
  
  /* Interrupt Setup */
  attachInterrupt(digitalPinToInterrupt(INTERRUPT), lines2, RISING); // change 2 to pin selected, RISING - Low to high, HIGH - High

  /* Comm Setup*/
  pinMode(NANOPIN1, INPUT);
  pinMode(NANOPIN2, INPUT);
  pinMode(NANOPIN3, INPUT);
  pinMode(NANOPIN4, INPUT);
  pinMode(NANOPIN5, INPUT);

}

// the loop function runs over and over again forever
void loop() {  
  /*
  ::dirAngle = 0;
  motors(::dirAngle);
  delay(3000);
  turn(true);
  delay(300);
  */
  seeker();
  
  /*
  seeker2();
  angleFix();
  timeTrack = millis();
  cli(); // disable interrupts
  bounce = bouncing();
  sei(); // enable interrupts
  if (bounce){
    delay(300);
  }
  */
  
}
