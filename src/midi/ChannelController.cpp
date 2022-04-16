#include "ChannelController.h"

void ChannelController::init() {
}

void ChannelController::update() {
    bool pitchUpdate = pitchInput.update();

    // pitch bend
    if(gateInput.isGateOn() && pitchUpdate) {
        pitchBend(pitchInput.getValue());
    }

    // trigger note on/off
    if(gateInput.update()) {
        if(gateInput.isTriggeredOn()) {
            noteOn(pitchInput.getValue());
        } else if (gateInput.isTriggeredOff()) {
            noteOff();
        }
    }
}

void ChannelController::setMidiChannel(uint8_t midiChannel) {
    noteOff();
    this->midiChannel = midiChannel;
}

void ChannelController::sendProgramChange(uint8_t program) {
    midiDevice.sendProgramChange(program, midiChannel);
}

void ChannelController::noteOn(float octave) {
    midiPitchConverter.noteOn(pitchInput.getValue());
    midiDevice.sendNoteOn(midiPitchConverter.getMidiNote(), 95, midiChannel);
    midiDevice.sendPitchBend(midiPitchConverter.getPitchBend(), midiChannel);
}

void ChannelController::pitchBend(float octave) {
    if(midiPitchConverter.pitchBend(octave)) {
        midiDevice.sendPitchBend(midiPitchConverter.getPitchBend(), midiChannel);
    } else {
        //recenters note when pitch bend goes too high or low, but this retrigger the note
        //noteOn(pitchInput.getValue());
    }
}

void ChannelController::noteOff() {
    midiDevice.sendNoteOff(midiPitchConverter.getMidiNote(), 0, midiChannel);
}