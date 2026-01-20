#include <Bounce2.h>

int inputPin = 5;
int ledPin = 13;
int ledValue = LOW;
Bounce bouncer = Bounce(inputPin, 5);

void setup() {
 pinMode(inputPin, INPUT);
 digitalWrite(inputPin, HIGH);
 pinMode(ledPin, OUTPUT);
 Serial.begin(9600);
}

void loop() {
 if (bouncer.update() && bouncer.read() == LOW) {
  ledValue = ! ledValue;
  digitalWrite(ledPin, ledValue);
 }
 Serial.println(ledValue);
 //Servirá para ver o gráfico no Serial Plotter de forma lenta
 delay(100);
}