#include <Wire.h>
#define Serial SerialUSB
void setup() {
  SerialUSB.begin(115200);
  Serial5.begin(9600);
}

void loop() {
  char c;

  if ( SerialUSB.available() ) {
    c = SerialUSB.read();
    SerialUSB.print(c);
    Serial5.print(c);
  }
  if ( Serial5.available() ) {
    c = Serial5.read();
    SerialUSB.print(c);
  }
}

