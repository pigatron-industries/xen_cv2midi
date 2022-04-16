#include "MainController.h"
#include "hwconfig.h"
#include "Hardware.h"

#include <Arduino.h>


MainController::MainController() : AbstractMainController(Hardware::hw.encoder) {
}

void MainController::init() {
    Hardware::hw.init();
    AbstractMainController::init();
    encoder.getEncoderButton().update();
}

void MainController::update() {
    AbstractMainController::update();
    // while(!Hardware::hw.midiDevice) {
    //     Serial.println("disconnected");
    // }
}
