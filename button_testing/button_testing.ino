#include "VelocityButton.hpp"

// Create a VelocityButton object
VelocityButton buttons(2, 3);

void setup() {
  Serial.begin(9600);
  buttons.begin();
}

void loop() {
  long diff = buttons.checkButtonPressDiff();
  if (diff != 0) {
    int mappedValue = buttons.invMapValue(diff);
    Serial.print("Mapped value: ");
    Serial.println(mappedValue);
  }
}