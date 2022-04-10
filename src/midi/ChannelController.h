#ifndef ChannelController_h
#define ChannelController_h

#include <eurorack.h>
#include <inttypes.h>
#include <USBHost_t36.h>
#include "Hardware.h"
#include "MidiPitchConverter.h"

class ChannelController {

    public:
        ChannelController(MIDIDevice& midiDevice, AnalogInputPin<>& velocityInputPin, AnalogInputPin<>& pitchInputPin, uint8_t midiChannel) : 
            midiDevice(midiDevice), 
            gateInput(velocityInputPin),
            velocityInput(velocityInputPin, -5, 5, 127),
            pitchInput(pitchInputPin, -5, 5, 0, 10),
            midiChannel(midiChannel)
        {};

        void init();
        void update();

    private:
        MIDIDevice& midiDevice;
        MidiPitchConverter midiPitchConverter;

        AnalogGateInput<> gateInput;
        EnumInput<> velocityInput;
        LinearInput<> pitchInput;

        uint8_t midiChannel;
        
        void noteOn(float octave);
};

#endif
