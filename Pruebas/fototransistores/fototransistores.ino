const int w[3] = {8, 11, 12}; // white
const int g[3] = {9, 10, 13}; // green

int photoTran = A0;
int reading = 0;

void setup() {
  pinMode(photoTran,INPUT);
  Serial.begin(9600);
  pinMode(w[0], OUTPUT);
  pinMode(w[1], OUTPUT);
  pinMode(w[2], OUTPUT);
  pinMode(g[0], OUTPUT);
  pinMode(g[1], OUTPUT);
  pinMode(g[2], OUTPUT);
  digitalWrite(8, HIGH);  
  digitalWrite(11, HIGH);  
  digitalWrite(12, HIGH);  
  digitalWrite(9, HIGH);  
  digitalWrite(10, HIGH);  
  digitalWrite(13, HIGH);  
}

// the loop function runs over and over again forever
void loop() {
  reading = analogRead(photoTran);
  Serial.println(reading);
  delay(100);
}
