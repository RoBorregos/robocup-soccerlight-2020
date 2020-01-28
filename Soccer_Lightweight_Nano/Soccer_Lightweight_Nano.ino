#include "Type4067Mux.h"

/* Mux */
Type4067Mux mux(A4, INPUT, ANALOG, 11, 10, 9, 8);

/* Function declaration */
void lines();
void linesPrint();
void photoresistors();
void commsToMega(bool, bool, bool, bool, bool);
void distance();
void interrupt();

/* Nano te Mega Communication*/
const int COMPIN1 = 1;
const int COMPIN2 = 2;
const int COMPIN3 = 3;
const int COMPIN4 = 4;
const int COMPIN5 = 5;

const int LED = 13;

/* Photoresistors Variables */
int pr_front[5] = {0, 0, 0, 0, 0};
int pr_right[5] = {0, 0, 0, 0, 0};
int pr_left[5] = {0, 0, 0, 0, 0};
int pr_backright[2] = {0, 0};
int pr_backleft[2] = {0, 0};

bool front = 0;
bool right = 0;
bool left = 0;
bool backright = 0;
bool backleft = 0;

const int PR1 = A1;
const int PR2 = A2;
const int PR3 = A3;
const int PR4 = A4;

/* Multiplexer Variables */
const int SIG = A0;
const int S0 = 1;
const int S1 = 2;
const int S2 = 3;
const int S3 = 4;

/* Interrupt Pin */
const int INTRR = 5;

void setup() {
  /* Initialize serial communication */
  Serial.begin(9600);

  pinMode(LED, OUTPUT);

  /* Setup Comms to Mega */
  pinMode(COMPIN1, OUTPUT);
  pinMode(COMPIN2, OUTPUT);
  pinMode(COMPIN3, OUTPUT);
  pinMode(COMPIN4, OUTPUT);
  pinMode(COMPIN5, OUTPUT);

  /* MUX */
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(SIG, INPUT);

}

// the loop function runs over and over again forever
void loop() {
  /* update array */
  lines();
  photoresistors();
  linesPrint();
  interrupt();
}
