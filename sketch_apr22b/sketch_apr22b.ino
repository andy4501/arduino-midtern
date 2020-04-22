#include "SevSeg.h"
SevSeg sevseg;
const byte potPin = A3;
int val;
const byte NUM = 1;
const byte led[] = {7};
const int delaytime = 500;
const byte sw = 6;
int ii;
byte Hour = 0;
byte Min = 0;


void setup() {
  Serial.begin(9600);
  pinMode(led[ii], OUTPUT);
  byte numDigits = 4;
  byte digitPins[] = {2, 3, 4, 5};
  byte segmentPins[] = {8, 9, 10, 11, 12, 13, 14, 15};
  bool resistorsOnSegments = false; // 'false' means resistors are on digit pins
  byte hardwareConfig = COMMON_CATHODE; // See README.md for options
  bool updateWithDelays = false; // Default. Recommended
  bool leadingZeros = false; // Use 'true' if you'd like to keep the leading zeros
  pinMode(6, INPUT);
  sevseg.begin(hardwareConfig, numDigits, digitPins, segmentPins, resistorsOnSegments, updateWithDelays, leadingZeros);
  sevseg.setBrightness(90);

  Serial.begin(9600);


}


void loop() {
  // val = analogRead(potPin);
  // Serial.begin(9600);

  static unsigned long timer = millis();

  boolean Pin6 = digitalRead (6); // Reset
  if (Pin6 == HIGH) {
    Min = Hour = 0;
    for (ii = 0; ii < NUM; ii++)
    {
      digitalWrite(led[ii], HIGH);
    }
    delay(500);
    for (ii = 0; ii < NUM; ii++)
    {
      digitalWrite(led[ii], LOW);
    }
    delay(500);
  }
  if (millis() - timer >= 500) {
    timer += 500;
    
    val = analogRead(potPin);
    Serial.println("ADC光敏:");
    Serial.println(val);

    
    sevseg.setNumber(Min, 0);
    Min = Min + 1;

    if (Min == 10 )
    {
      Min = 0;
    }

  }
  sevseg.refreshDisplay(); // Must run repeatedly


}
