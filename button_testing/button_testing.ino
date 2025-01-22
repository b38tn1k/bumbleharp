#include "VelocityButton.hpp"

// Define an array of 12 VelocityButton objects
VelocityButton buttons[12] = {
  VelocityButton(2, 3),
  VelocityButton(4, 5),
  VelocityButton(6, 7),
  VelocityButton(8, 9),
  VelocityButton(10, 11),
  VelocityButton(12, 13),
  VelocityButton(14, 15), // Adjust these for your board's pin capabilities
  VelocityButton(16, 17),
  VelocityButton(18, 19),
  VelocityButton(20, 21),
  VelocityButton(22, 23),
  VelocityButton(24, 25)  // Ensure these pins exist on your microcontroller
};

void setup() {
  Serial.begin(9600);

  // Initialize all buttons
  for (int i = 0; i < 12; ++i) {
    buttons[i].begin();
  }
}

void loop() {
  // Iterate over all button pairs
  for (int i = 0; i < 12; ++i) {
    long diff = buttons[i].checkButtonPressDiff();

    if (diff != 0) {
      int mappedValue = buttons[i].invMapValue(diff);
      Serial.println(mappedValue);
      // Serial.print("Button Pair ");
      // Serial.print(i);
      // Serial.print(" Mapped Value: ");
      // Serial.println(mappedValue);
    }
  }
}