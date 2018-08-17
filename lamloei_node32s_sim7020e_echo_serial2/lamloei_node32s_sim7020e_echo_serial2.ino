#include <HardwareSerial.h>
#define PINRESET_7020E 32 //PWRKEY

char c;
void setup() {
  pinMode(PINRESET_7020E, OUTPUT);
  digitalWrite(PINRESET_7020E, LOW); 
  delay(300);
  digitalWrite(PINRESET_7020E, HIGH);
  Serial.begin(115200);
  Serial2.begin(9600);
}

void loop() {
  if ( Serial.available() ) {
    c = Serial.read();
    //Serial.print(c);
    Serial2.print(c);
  }
  if ( Serial2.available() ) {
    c = Serial2.read();
    Serial.print(c);
  }
}

