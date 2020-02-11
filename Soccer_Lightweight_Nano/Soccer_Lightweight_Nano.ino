#include <Type4067Mux.h>

/* Mux */
Type4067Mux mux(A4, INPUT, ANALOG, 2, 3, 4, 5);

/* Function declaration */
void lines();
void lines2();
void linesPrint();
void linesPrint2();
void photoresistors();
bool photoresistors2();
void commsToMega(bool, bool, bool, bool, bool);
void distance();
void interrupt();
void interrupt2();

/* Nano to Mega Communication*/
const int COMPIN1 = 6;
/* ignorar */
const int COMPIN2 = 0;
const int COMPIN3 = 0;
// const int COMPIN4 = 4;
// const int COMPIN5 = 5;

/* Photoresistors Variables */
/* ignorar */
int pr_front[5] = {0, 0, 0, 0, 0};
int pr_right[5] = {0, 0, 0, 0, 0};
int pr_left[5] = {0, 0, 0, 0, 0};
int pr_backright[2] = {0, 0};
int pr_backleft[2] = {0, 0};

int pr[15] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

/* ignorar */
bool front = 0;
bool right = 0;
bool left = 0;
bool backright = 0;
bool backleft = 0;

/*
const int PR1 = A1;
const int PR2 = A2;
const int PR3 = A3;
const int PR4 = A4;
*/

/* Interrupt Pin */
const int INTRR = 12;

unsigned long long timeTrack = 0;

void setup() {
  /* Initialize serial communication */
  Serial.begin(9600);

  /* Setup Comms to Mega */
  pinMode(COMPIN1, OUTPUT);
  pinMode(INTRR, OUTPUT);
  /* ignorar */
  pinMode(COMPIN2, OUTPUT);
  pinMode(COMPIN3, OUTPUT);
  // pinMode(COMPIN4, OUTPUT);
  // pinMode(COMPIN5, OUTPUT);

}

// the loop function runs over and over again forever
void loop() {
  interrupt2();
}
