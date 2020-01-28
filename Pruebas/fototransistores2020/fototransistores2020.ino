void photoresistors();
void linesPrint();
void lines();
int mux(bool i, bool j, bool k, bool l);


/* Photoresistors Variables */
int pr_front[5] = {0, 0, 0, 0, 0};
int pr_right[5] = {0, 0, 0, 0, 0};
int pr_left[5] = {0, 0, 0, 0, 0};

bool front = 0;
bool right = 0;
bool left = 0;

/* Multiplexer Variables */
const int SIG = A4;
const int S0 = 11;
const int S1 = 10;
const int S2 = 9;
const int S3 = 8;

void setup() {
  /* Initialize serial communication */
  Serial.begin(9600);
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);

  pinMode(SIG, INPUT);

  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  lines();
  photoresistors();
  linesPrint();
  delay(1000);
}
