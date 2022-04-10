#include "MidiPitchConverter.h"


void MidiPitchConverter::noteOn(float octave) {
    float note = midiNoteScale.convert(octave);
    midiNote = static_cast<int>(note);
    pitchBendInternal(note);
}

bool MidiPitchConverter::pitchBend(float octave) {
    float note = midiNoteScale.convert(octave);
    return pitchBendInternal(note);
}

bool MidiPitchConverter::pitchBendInternal(float note) {
    float bend = note - static_cast<float>(midiNote);
    midiPitchBend = bend * bendResolution;
    if(midiPitchBend < -bendMax || midiPitchBend > bendMax) {
        return false;
    } else {
        return true;
    }
}

