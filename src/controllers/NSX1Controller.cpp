#include "NSX1Controller.h"

void NSX1Controller::init() {
    Serial.println("NSX1");

    switch(mode.value) {
        case Mode::MIKU:
            channels[0].setMidiChannel(NSX1_CHANNEL_MIKU);
            channels[1].setMidiChannel(3);
            channels[2].setMidiChannel(4);
            channels[3].setMidiChannel(NSX1_CHANNEL_DRUM);
            break;
        case Mode::PIANO:
            selectInstrumentChannels();
            selectInstrumentGroup(NSX1_PROGRAM_PIANO);
            break;
        case Mode::CHROMATIC:
            selectInstrumentChannels();
            selectInstrumentGroup(NSX1_PROGRAM_CHROMATIC);
            break;
        case Mode::ORGAN:
            selectInstrumentChannels();
            selectInstrumentGroup(NSX1_PROGRAM_ORGAN);
            break;
        case Mode::GUITAR:
            selectInstrumentChannels();
            selectInstrumentGroup(NSX1_PROGRAM_GUITAR);
            break;
        case Mode::BASS:
            selectInstrumentChannels();
            selectInstrumentGroup(NSX1_PROGRAM_BASS);
            break;
        case Mode::STRINGS:
            selectInstrumentChannels();
            selectInstrumentGroup(NSX1_PROGRAM_STRINGS);
            break;
        case Mode::ENSEMBLE:
            selectInstrumentChannels();
            selectInstrumentGroup(NSX1_PROGRAM_ENSEMBLE);
            break;
        case Mode::BRASS:
            selectInstrumentChannels();
            selectInstrumentGroup(NSX1_PROGRAM_BRASS);
            break;
        case Mode::REED:
            selectInstrumentChannels();
            selectInstrumentGroup(NSX1_PROGRAM_REED);
            break;
        case Mode::PIPE:
            selectInstrumentChannels();
            selectInstrumentGroup(NSX1_PROGRAM_PIPE);
            break;
        case Mode::SYNTH_LEAD:
            selectInstrumentChannels();
            selectInstrumentGroup(NSX1_PROGRAM_SYNTH_LEAD);
            break;
        case Mode::SYNTH_PAD:
            selectInstrumentChannels();
            selectInstrumentGroup(NSX1_PROGRAM_SYNTH_PAD);
            break;
        case Mode::SYNTH_EFFECTS:
            selectInstrumentChannels();
            selectInstrumentGroup(NSX1_PROGRAM_SYNTH_EFFECTS);
            break;
        case Mode::ETHNIC:
            selectInstrumentChannels();
            selectInstrumentGroup(NSX1_PROGRAM_ETHNIC);
            break;
        case Mode::PERCUSSIVE:
            selectInstrumentChannels();
            selectInstrumentGroup(NSX1_PROGRAM_PERCUSSIVE);
            break;
        case Mode::DRUMS:
            channels[0].setMidiChannel(10);
            channels[1].setMidiChannel(10);
            channels[2].setMidiChannel(10);
            channels[3].setMidiChannel(10);
            break;
    }

    for(ChannelController& channel : channels) {
        channel.init();
    }
}

void NSX1Controller::update() {
    for(ChannelController& channel : channels) {
        channel.update();
    }

    if(mod1Input.update()) {
        selectInstrumentVariation(mod1Input.getIntValue());
    }
}

void NSX1Controller::selectInstrumentChannels() {
    channels[0].setMidiChannel(2);
    channels[1].setMidiChannel(3);
    channels[2].setMidiChannel(4);
    channels[3].setMidiChannel(5);
}

void NSX1Controller::selectInstrumentGroup(uint8_t instrumentGroup) {
    for(ChannelController& channel : channels) {
        channel.sendProgramChange(instrumentGroup);
    }
    this->instrumentGroup = instrumentGroup;
}

void NSX1Controller::selectInstrumentVariation(uint8_t instrumentVariation) {
    for(ChannelController& channel : channels) {
        channel.sendProgramChange(instrumentGroup+instrumentVariation);
    }
    //Serial.println(instrumentGroup+instrumentVariation);
}