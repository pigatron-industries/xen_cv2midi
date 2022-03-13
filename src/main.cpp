#include <Arduino.h>
#include "hwconfig.h"
#include "MainController.h"

MainController mainController = MainController();

void setup() {
    Serial.begin(SERIAL_BAUD);
    Serial.println();
    Serial.println("=========================================");
    Serial.println("*     Pigatron Industries CV2MIDI       *");
    Serial.println("=========================================");
    Serial.println();
    Hardware::hw.init();

    mainController.init();
}

void loop() {
    mainController.update();
}
