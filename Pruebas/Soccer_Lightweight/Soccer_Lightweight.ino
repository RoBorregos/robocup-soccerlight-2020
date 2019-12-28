#include <Pixy2.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055.h>
#include <utility/imumaths.h>
#include <math.h>
#include <Wire.h>
#include <HTInfraredSeeker.h>

/* LED Variables */
const int ledPin = 13;

/* BNO055 Variables */
#define BNO055_SAMPLERATE_DELAY_MS (100)

Adafruit_BNO055 bno = Adafruit_BNO055();

int orientationAngle = 0;
int BNOSetPoint = 0;
unsigned long long angleFixTime = 0;


/* Motors Variables */
const int power = 255;

const int motor1A = 6; 
const int motor1B = 7;

const int motor2A = 2; 
const int motor2B = 3;

const int motor3A = 4; 
const int motor3B = 5;

void setup() {
  Serial.begin(9600);

  /* BNO055 Setup */
  if(!bno.begin())
  {
    Serial.print("Ooops, no BNO055 detected ...");
  }
  delay(1);
  bno.setExtCrystalUse(true);
  
  /* Motors Setup */
  pinMode(motor1A, OUTPUT);
  pinMode(motor1B, OUTPUT);
  pinMode(motor2A, OUTPUT);
  pinMode(motor2B, OUTPUT);
  pinMode(motor3A, OUTPUT);   
  pinMode(motor3B, OUTPUT);

  /* Seeker Setup */
  InfraredSeeker::Initialize();

  /* BNO055 Calibration Check */
  Adafruit_BNO055 BNO055;

  while(orientationStatus() != 3)
  {
    digitalWrite(ledPin, HIGH);
    delay(1000);
    digitalWrite(ledPin, LOW);
    delay(500);
  }
  Serial.println("Calibrated");

  for(int i = 0; i < 15; i++)
  {
    digitalWrite(ledPin, HIGH);
    delay(100);
    digitalWrite(ledPin, LOW);
    delay(100);
  }
  orientationAngle = 0;
  delay(1000);
  sensors_event_t event;
  bno.getEvent(&event);
  BNOSetPoint = event.orientation.x;
}

// the loop function runs over and over again forever
void loop() {
  seeker();
  angleFix();
}
