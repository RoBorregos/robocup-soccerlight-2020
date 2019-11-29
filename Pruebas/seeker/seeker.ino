#include <HTInfraredSeeker.h>

void setup()
{
  Serial.begin(9600);
  Serial.println("Dir\tStrength");
  Serial.println();
  InfraredSeeker::Initialize();
}

void loop()
{   
  InfraredResult InfraredBall = InfraredSeeker::ReadAC();
  Serial.print(InfraredBall.Direction);
  Serial.print("\t");
  Serial.print(InfraredBall.Strength);
  Serial.println();
  delay(100);
}
