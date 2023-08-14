#include <Servo.h>

Servo myservo;
int buttonPin = 2; // Pino do botão
int servoPin = 9; // Pino do servo motor
int buttonState = HIGH;
int lastButtonState = HIGH;
bool servoState = false;

void setup() {
  myservo.attach(servoPin);
  pinMode(buttonPin, INPUT_PULLUP);
}

void loop() {
  buttonState = digitalRead(buttonPin);
  if (buttonState != lastButtonState) {
    if (buttonState == LOW) {
      servoState = !servoState;
      if (servoState) {
        myservo.write(180);
      } else {
        myservo.write(0);
      }
    }
    delay(50);
  }
  lastButtonState = buttonState;
}
