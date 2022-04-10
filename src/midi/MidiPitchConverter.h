#ifndef MidiPitchConverter_h
#define MidiPitchConverter_h

#include <inttypes.h>
#include <eurorack.h>

class MidiPitchConverter {

    public:
        MidiPitchConverter() {}

        int8_t getMidiNote() { return midiNote; }
        int16_t getPitchBend() { return midiPitchBend; }

        void noteOn(float octave);
        bool pitchBend(float octave);



    private:
        int8_t midiNote;
        int16_t midiPitchBend;

        RangeScale midiNoteScale = RangeScale(0, 10, 0, 120);
        const int16_t bendResolution = 512; // per semitone
        const int16_t bendMax = 8191;

        bool pitchBendInternal(float note);
};

#endif

