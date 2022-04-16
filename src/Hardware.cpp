#include "Hardware.h"

Hardware Hardware::hw = Hardware();

void Hardware::init() {
    NativeDevice::instance.init();
    usb.begin();
    while(!midiDevice) {}
    Serial.println("MIDI device connected.");
}

