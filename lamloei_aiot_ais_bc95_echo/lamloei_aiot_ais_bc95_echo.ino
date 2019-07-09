#define RESET_PIN 20

void setup() {
  pinMode(RESET_PIN, OUTPUT);
  digitalWrite(RESET_PIN, HIGH);
  delay(2000);
  digitalWrite(RESET_PIN, LOW);  
  Serial.begin(115200);
  Serial2.begin(9600, 18, 19);
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
