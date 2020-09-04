#include <Arduino.h>

#define LEDGREEN 2
#define LEDRED 4
#define ANALOGBATTERY 0

int analogValue = 0;
float voltage = 0;
int ledDelay = 800;

float maximum = 1.6;
float minimum = 1.0;

void setup() {
  // put your setup code here, to run once:
  pinMode (LEDGREEN, OUTPUT);
  pinMode (LEDRED, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  analogValue = analogRead (ANALOGBATTERY);

  voltage = 0.0048 * analogValue;
  serial.print ("voltage:");
  serial.println (voltage);

  if (voltage>= maximum)
  {
    digitalWrite (LEDGREEN, HIGH);
    delay (ledDelay);
    digitalWrite (LEDGREEN, LOW);
  }
  else if (voltage <maximum && voltage> minimum)
  {
    digitalWrite(LEDRED, HIGH);
    delay(ledDelay);
    digitalWrite(LEDRED, LOW);
  }
}