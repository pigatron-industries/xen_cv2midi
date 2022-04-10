#include "ChannelController.h"

void ChannelController::init() {
    midiDevice.sendControlChange(0x48, 127, midiChannel);
}

void ChannelController::update() {
    bool pitchUpdate = pitchInput.update();

    // pitch bend
    if(gateInput.isGateOn() && pitchUpdate) {
        if(midiPitchConverter.pitchBend(pitchInput.getValue())) {
            midiDevice.sendPitchBend(midiPitchConverter.getPitchBend(), midiChannel);
        } else {
            //recenters note when pitch bend goes too high or low, this is not seamless
            noteOn(pitchInput.getValue());
        }
    }

    // trigger note on/off
    if(gateInput.update()) {
        if(gateInput.isTriggeredOn()) {
            noteOn(pitchInput.getValue());
        } else if (gateInput.isTriggeredOff()) {
            midiDevice.sendNoteOff(midiPitchConverter.getMidiNote(), 0, midiChannel);
        }
    }

    // Serial.println("1");
    // midiDevice.sendNoteOn(80, 95, midiChannel);
    // delay(100);
    // midiDevice.sendNoteOff(80, 0, midiChannel);
    // delay(100);
}

void ChannelController::noteOn(float octave) {
    midiPitchConverter.noteOn(pitchInput.getValue());
    midiDevice.sendNoteOn(midiPitchConverter.getMidiNote(), 95, midiChannel);
    midiDevice.sendPitchBend(midiPitchConverter.getPitchBend(), midiChannel);
}