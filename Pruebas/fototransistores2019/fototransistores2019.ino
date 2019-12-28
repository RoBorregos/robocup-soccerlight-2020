
/* Photoresistors Variables */
//const int nanoPin1 = 52; 
//const int nanoPin2 = 50;
const int nanoPin3 = 48;
const int nanoPin4 = 46;
const int nanoPin5 = 44;
bool nano1 = 0;
bool nano2 = 0;
bool nano3 = 0;
bool nano4 = 0;
bool nano5 = 0;

/* LED */
const int ledPin = 43;
const int ledF = 45; //53
const int ledR = 49;
const int ledL = 47;

/* Line loop */
bool F = false;
bool R = false;
bool L = false;
int lineReturnTime;

int readLines();


void setup() {
  Serial.begin(9600);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(readLines());
  delay(100);
}

int readLines()
{
  //nano1 = digitalRead(nanoPin1);
  //nano2 = digitalRead(nanoPin2);
  nano3 = digitalRead(nanoPin3);
  nano4 = digitalRead(nanoPin4);
  nano5 = digitalRead(nanoPin5);
  
  /*Serial.print(nano1);
  Serial.print(" ");
  Serial.print(nano2);
  Serial.print(" ");
  Serial.print(nano3);
  Serial.print(" ");
  Serial.print(nano4);
  Serial.print(" ");
  Serial.print(nano5);
  Serial.println();*/

  if(nano1 == 0 && nano2 == 0 && nano3 == 0 && nano4 == 0 && nano5 == 1)
  {
    digitalWrite(ledR, LOW);
    digitalWrite(ledF, HIGH);
    digitalWrite(ledL, LOW);
    return 1;
  }
  else if(nano1 == 0 && nano2 == 0 && nano3 == 0 && nano4 == 1 && nano5 == 0)
  {
    digitalWrite(ledR, HIGH);
    digitalWrite(ledF, LOW);
    digitalWrite(ledL, LOW);
    return 2;
  }
  else if(nano1 == 0 && nano2 == 0 && nano3 == 0 && nano4 == 1 && nano5 == 1)
  {
    digitalWrite(ledR, LOW);
    digitalWrite(ledF, LOW);
    digitalWrite(ledL, HIGH);
    return 3;
  }
  else if(nano1 == 0 && nano2 == 0 && nano3 == 1 && nano4 == 0 && nano5 == 0)
  {
    digitalWrite(ledR, HIGH);
    digitalWrite(ledF, HIGH);
    digitalWrite(ledL, LOW);
    return 4;
  }
  else if(nano1 == 0 && nano2 == 0 && nano3 == 1 && nano4 == 0 && nano5 == 1)
  {
    digitalWrite(ledR, HIGH);
    digitalWrite(ledF, LOW);
    digitalWrite(ledL, HIGH);
    return 5;
  }
  else if(nano1 == 0 && nano2 == 0 && nano3 == 1 && nano4 == 1 && nano5 == 0)
  {
    digitalWrite(ledR, LOW);
    digitalWrite(ledF, HIGH);
    digitalWrite(ledL, HIGH);
    return 6;
  }

  digitalWrite(ledR, LOW);
  digitalWrite(ledF, LOW);
  digitalWrite(ledL, LOW);
  return 0;
}
