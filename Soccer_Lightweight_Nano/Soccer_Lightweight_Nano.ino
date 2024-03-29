// Soccer Lightweight Junior 2020.
// Created by RoBorregos

#include <Type4067Mux.h>

#define RANGO 150

// Mux Object.
Type4067Mux mux(A6, INPUT, ANALOG, 12, 11, 10, 9);

static const int PR[] = {A0,A1,A2,A3};

// Function declaration.
void linesPrint();
bool photoresistors();
void interrupt();

// Nano to Mega Communication.
const int COMPIN1 = 3;

// Interrupt Pin.
const int INTRR = 2;

// unsigned long long timeTrack = 0;

void setup() {
  // Initialize serial communication.
  Serial.begin(9600);

  // Setup Comms to Mega.
  pinMode(COMPIN1, OUTPUT);
  pinMode(INTRR, OUTPUT);

  pinMode(PR[0], INPUT);
  pinMode(PR[1], INPUT);
  pinMode(PR[2], INPUT);
  pinMode(PR[3], INPUT);
}

// The loop function runs over and over again forever.
void loop() {
  interrupt();
  linesPrint();
}
