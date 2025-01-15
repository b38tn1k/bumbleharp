#ifndef VELOCITY_BUTTON_HPP
#define VELOCITY_BUTTON_HPP

#include <Arduino.h>  // Required for Arduino-specific functions like `pinMode`

class VelocityButton {
private:
  int firstButtonPin;
  int secondButtonPin;
  const unsigned long debounceMs;
  float minVal, maxVal, scaledMinVal, scaledMaxVal;

  // State variables
  bool firstButtonLowLastCycle = false;
  bool secondButtonLowLastCycle = false;
  unsigned long firstButtonPressTime = 0;
  unsigned long secondButtonPressTime = 0;
  bool firstPressCaptured = false;
  bool secondPressCaptured = false;
  bool measurementDone = false;
  unsigned long firstDebounceTimer = 0;
  unsigned long secondDebounceTimer = 0;

public:
  // Constructor
  VelocityButton(int firstPin, int secondPin, unsigned long debounceTime = 50,
                 float inputMin = 2500, float inputMax = 25000,
                 float outputMin = 0, float outputMax = 127);

  // Initialization
  void begin();

  // Method to check button press difference
  long checkButtonPressDiff();

  // Method to map value inversely
  int invMapValue(float value);
};

#endif  // VELOCITY_BUTTON_HPP