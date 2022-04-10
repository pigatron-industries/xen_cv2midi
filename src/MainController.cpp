#include "MainController.h"
#include "hwconfig.h"
#include "Hardware.h"

#include <Arduino.h>


MainController::MainController() {
}

void MainController::init() {
    Hardware::hw.init();
    usb.begin();
    for(ChannelController& channel : channels) {
        channel.init();
    }
}

void MainController::update() {
    usb.Task();
    midiDevice.read();

    for(ChannelController& channel : channels) {
        channel.update();
    }

}
