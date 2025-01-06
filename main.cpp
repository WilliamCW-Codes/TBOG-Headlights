#include <Arduino.h>

const int switchPin = 0; // change
const int blinkSwitchPin = 1; // change
const int lightPin = 5; // change

void setup() {
  pinMode(switchPin, INPUT);
  pinMode(blinkSwitchPin, INPUT);
  pinMode(lightPin, OUTPUT);
}

// Global variables to keep track of the state and time
unsigned long lastBlinkTime = 0;
const unsigned long blinkInterval = 500; // Blink every 500 ms
bool isBlinking = false;

void loop() {
    int switchState = digitalRead(switchPin);
    int blinkSwitchState = digitalRead(blinkSwitchPin);

    if (switchState == HIGH) {
        digitalWrite(lightPin, HIGH);
        isBlinking = false;
    }

    if (switchState == HIGH && blinkSwitchState == HIGH) {
        isBlinking = true;
    }

    if (isBlinking) {
        unsigned long currentMillis = millis();
        if (currentMillis - lastBlinkTime >= blinkInterval) {
            // Save the last time the light was toggled
            lastBlinkTime = currentMillis;

            // Read the current state of the light
            int lightState = digitalRead(lightPin);

            // If the light is on, turn it off. If it's off, turn it on.
            digitalWrite(lightPin, lightState == HIGH ? LOW : HIGH);
        }
    } 
        else {
        digitalWrite(lightPin, LOW);
    }
}