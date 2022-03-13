#include "MainController.h"
#include "hwconfig.h"
#include "Hardware.h"

#include <Arduino.h>


MainController::MainController() {
}

void MainController::init() {
    Hardware::hw.init();
}

void MainController::update() {
}
