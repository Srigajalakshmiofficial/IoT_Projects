#define VRX A0
#define VRY A1
#define SW  2  // Joystick button pin

void setup() {
  pinMode(SW, INPUT_PULLUP); // Button is active LOW
  Serial.begin(9600);
}

void loop() {
  int xValue = analogRead(VRX);
  int yValue = analogRead(VRY);
  int buttonState = digitalRead(SW);

  int deadzone = 200;

  if (xValue > 512 + deadzone) {
    Serial.println(1); // Right
  } 
  else if (xValue < 512 - deadzone) {
    Serial.println(2); // Left
  } 
  else if (yValue < 512 - deadzone) {
    Serial.println(3); // Up
  } 
  else if (yValue > 512 + deadzone) {
    Serial.println(4); // Down
  } 
  else if (buttonState == LOW) {
    Serial.println(5); // Button Press
  }
  else {
    Serial.println(0); // Neutral
  }

  delay(100);
}