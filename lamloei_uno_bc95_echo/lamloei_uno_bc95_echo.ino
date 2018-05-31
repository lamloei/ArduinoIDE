#include <SoftwareSerial.h>

SoftwareSerial mySerial(8, 9);

void setup() {
  Serial.begin(9600);
  mySerial.begin(9600);
}

void loop() {
  char c;

  if ( Serial.available() ) {
    c = Serial.read();
    Serial.print(c);
    mySerial.print(c);
  }
  if ( mySerial.available() ) {
    c = mySerial.read();
    Serial.print(c);
  }
}

