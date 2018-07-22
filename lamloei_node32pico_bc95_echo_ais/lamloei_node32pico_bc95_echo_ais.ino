#include <HardwareSerial.h>
#define RESET_PIN 2

//HardwareSerial Serial1(1);

void setup() {
  pinMode(RESET_PIN, OUTPUT);
  digitalWrite(RESET_PIN, HIGH);
  delay(1);
  digitalWrite(RESET_PIN, LOW);  
  Serial.begin(115200);
  Serial1.begin(9600, SERIAL_8N1, 14, 27);
}

void loop() {
  char c;

  if ( Serial.available() ) {
    c = Serial.read();
    Serial.print(c);
    Serial1.print(c);
  }
  if ( Serial1.available() ) {
    c = Serial1.read();
    Serial.print(c);
  }
}
