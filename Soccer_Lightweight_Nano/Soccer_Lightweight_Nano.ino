#include <Type4067Mux.h>

/* Mux */
Type4067Mux mux(A4, INPUT, ANALOG, 2, 3, 4, 5);

/*
const int PR1 = A1;
const int PR2 = A2;
const int PR3 = A3;
const int PR4 = A4;
*/

/* Function declaration */
void lines();
void linesPrint();
bool photoresistors();
void interrupt();

/* Nano to Mega Communication*/
const int COMPIN1 = 6;

/* Photoresistors Variables */
int pr[15] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

/* Interrupt Pin */
const int INTRR = 12;

unsigned long long timeTrack = 0;

void setup() {
  /* Initialize serial communication */
  Serial.begin(9600);

  /* Setup Comms to Mega */
  pinMode(COMPIN1, OUTPUT);
  pinMode(INTRR, OUTPUT);

}

// the loop function runs over and over again forever
void loop() {
  interrupt();
}
