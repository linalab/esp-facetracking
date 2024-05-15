/*
En este ejercicio, utilizamos un botón
como flecha del teclado.
Utilizamos un Arduino Micro (ATMEGA A32U4).

Referencia de librería Keyboard: https://www.arduino.cc/reference/en/language/functions/usb/keyboard/
Basado en el tutorial de referencia: https://www.instructables.com/Arduino-Programmable-Button-Panel-As-Keyboard/

Key Codes:
Flecha izquierda: KEY_LEFT_ARROW	
Flecha derecha: KEY_RIGHT_ARROW	
Flecha arriba: KEY_UP_ARROW
Flecha abajo: KEY_DOWN_ARROW
Enter: KEY_RETURN


*/


#include "Keyboard.h"

const int buttonPin = 5;
int buttonState = 0;
int prevButtonState = HIGH;

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);
  digitalWrite(buttonPin, HIGH);
  Keyboard.begin();
}

void loop() {
  buttonState = digitalRead(buttonPin);
  if ((buttonState != prevButtonState) && (buttonState == HIGH)) {
    Keyboard.press(KEY_LEFT_ARROW);
    delay(100);
    Keyboard.releaseAll(); // This is important after every Keyboard.press it will continue to be pressed
  }
  prevButtonState = buttonState;
}

