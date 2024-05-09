#include <Arduino.h>

const int switchPin = 0; // change
const int blinkSwitchPin = 1; // change
const int lightPin = 5; // change

void setup() {
  pinMode(switchPin, INPUT);
  pinMode(blinkSwitchPin, INPUT);
  pinMode(lightPin, OUTPUT);
}

void blinkLights() {
  // Blink the lights
    digitalWrite(lightPin, HIGH); // Turn on
    delay(500);                  // Wait for 0.5 sec
    digitalWrite(lightPin, LOW);  // Turn off
    delay(500);                  // Wait for 0.5 sec
    digitalWrite(lightPin, HIGH); // Turn on
}

// Global variables to keep track of the state and time
bool isBlinking = false;
unsigned long lastBlinkTime = 0;
const unsigned long blinkInterval = 500; // Blink every 500 ms

void loop() {
    int switchState = digitalRead(switchPin);
    if (switchState == LOW) {
        digitalWrite(lightPin, LOW);
        isBlinking = false; // Stop blinking
        return;
    }

    int blinkSwitchState = digitalRead(blinkSwitchPin);
    if (blinkSwitchState == HIGH) {
        isBlinking = true; // Start blinking
    } 
    else {
        isBlinking = false; // Stop blinking
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
        digitalWrite(lightPin, HIGH); // Keep the light on
    }
}