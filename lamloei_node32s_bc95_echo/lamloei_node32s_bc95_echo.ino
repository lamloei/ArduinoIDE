#include <HardwareSerial.h>
#define RESET_PIN 2

HardwareSerial Serial2(2);

void setup() {
  pinMode(RESET_PIN, OUTPUT);
  digitalWrite(RESET_PIN, HIGH);
  delay(1);
  digitalWrite(RESET_PIN, LOW);  
  Serial.begin(115200);
  Serial2.begin(9600, SERIAL_8N1, 14, 27);
}

void loop() {
  char c;

  if ( Serial.available() ) {
    c = Serial.read();
    Serial.print(c);
    Serial2.print(c);
  }
  if ( Serial2.available() ) {
    c = Serial2.read();
    Serial.print(c);
  }
}
