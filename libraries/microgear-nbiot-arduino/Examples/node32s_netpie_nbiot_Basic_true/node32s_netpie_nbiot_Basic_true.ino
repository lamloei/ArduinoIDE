#include <Arduino.h>
#define bc95serial Serial2
#define RESET_PIN 33

#include "BC95Udp.h"
#include "MicrogearNB.h"

#define APPID    "YOUR_APPID"
#define KEY      "YOUR_KEY"
#define SECRET   "YOUR_SECRET"

BC95UDP client;
Microgear mg(&client);

char payload[32];
int i=0;

void setup() {
    pinMode(RESET_PIN, OUTPUT);
    digitalWrite(RESET_PIN, LOW);
    delay(1);
    digitalWrite(RESET_PIN, HIGH);
    bc95serial.begin(9600, SERIAL_8N1, 14, 27);
    BC95.begin(bc95serial);

    Serial.begin(115200);
    Serial.println(F("Starting..."));

    BC95.reset();
    Serial.println(BC95.getIMEI());
    Serial.println(BC95.getIMSI());

    while (!BC95.attachNetwork()) {
        Serial.println("...");
        delay(1000);
    }
    Serial.println(F("NB-IOT attached\n RSSI:"));
    Serial.println(BC95.getSignalStrength());
    Serial.println(BC95.getIPAddress());

    mg.init(APPID, KEY, SECRET);
    mg.begin(5555);
}

void loop() {
    mg.publish("/node32pico/i", i++);
    mg.loop();
    delay(5000);
}
