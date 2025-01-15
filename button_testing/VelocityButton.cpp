#include "VelocityButton.hpp"

// Constructor
VelocityButton::VelocityButton(int firstPin, int secondPin, unsigned long debounceTime, 
                       float inputMin, float inputMax, float outputMin, float outputMax)
  : firstButtonPin(firstPin), secondButtonPin(secondPin), debounceMs(debounceTime),
    minVal(inputMin), maxVal(inputMax), scaledMinVal(outputMin), scaledMaxVal(outputMax) {}

// Initialization
void VelocityButton::begin() {
  pinMode(firstButtonPin, INPUT_PULLUP);
  pinMode(secondButtonPin, INPUT_PULLUP);
}

// Method to check button press difference
long VelocityButton::checkButtonPressDiff() {
  long timeDifference = 0;

  // Read the pins
  bool firstButtonIsLow = (digitalRead(firstButtonPin) == LOW);
  bool secondButtonIsLow = (digitalRead(secondButtonPin) == LOW);

  // Handle first button debounce and timing
  if (firstButtonIsLow && firstButtonLowLastCycle) {
    if (!firstPressCaptured && (millis() - firstDebounceTimer > debounceMs)) {
      firstButtonPressTime = micros();
      firstPressCaptured = true;
    }
  } else if (firstButtonIsLow && !firstButtonLowLastCycle) {
    firstDebounceTimer = millis();
  }

  // Handle second button debounce and timing
  if (secondButtonIsLow && secondButtonLowLastCycle) {
    if (!secondPressCaptured && (millis() - secondDebounceTimer > debounceMs)) {
      secondButtonPressTime = micros();
      secondPressCaptured = true;
    }
  } else if (secondButtonIsLow && !secondButtonLowLastCycle) {
    secondDebounceTimer = millis();
  }

  // Calculate time difference once per cycle
  if (firstPressCaptured && secondPressCaptured && !measurementDone) {
    timeDifference = (long)secondButtonPressTime - (long)firstButtonPressTime;
    measurementDone = true;
  }

  // Reset when both buttons are released
  if (!firstButtonIsLow && !secondButtonIsLow) {
    firstPressCaptured = false;
    secondPressCaptured = false;
    measurementDone = false;
  }

  // Update "last cycle" states
  firstButtonLowLastCycle = firstButtonIsLow;
  secondButtonLowLastCycle = secondButtonIsLow;

  return timeDifference;
}

// Method to map value inversely
int VelocityButton::invMapValue(float value) {
  if (minVal == maxVal) return scaledMinVal;

  if (value < minVal) value = minVal;
  if (value > maxVal) value = maxVal;

  float normalizedValue = (value - minVal) / (maxVal - minVal);
  float mappedValue = scaledMinVal + normalizedValue * (scaledMaxVal - scaledMinVal);

  return scaledMaxVal - mappedValue;
}