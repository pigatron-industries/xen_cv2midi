#include "NSX1Controller.h"

void NSX1Controller::init() {
    Serial.println("NSX1Controller::init");

    Hardware::hw.midiDevice.sendProgramChange(mode.value, 2);

    for(ChannelController& channel : channels) {
        channel.init();
    }
}

void NSX1Controller::update() {
    for(ChannelController& channel : channels) {
        channel.update();
    }
}
