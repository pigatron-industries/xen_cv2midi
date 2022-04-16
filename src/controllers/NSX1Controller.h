#ifndef NSX1Controller_h
#define NSX1Controller_h

#include "Controller.h"
#include "midi/ChannelController.h"

using namespace eurorack;

#define NSX1_CHANNEL_MIKU 1
#define NSX1_CHANNEL_DRUM 10

#define NSX1_PROGRAM_PIANO 0x00
#define NSX1_PROGRAM_CHROMATIC 0x08
#define NSX1_PROGRAM_ORGAN 0x10
#define NSX1_PROGRAM_GUITAR 0x18
#define NSX1_PROGRAM_BASS 0x20
#define NSX1_PROGRAM_STRINGS 0x28
#define NSX1_PROGRAM_ENSEMBLE 0x30
#define NSX1_PROGRAM_BRASS 0x38
#define NSX1_PROGRAM_REED 0x40
#define NSX1_PROGRAM_PIPE 0x48
#define NSX1_PROGRAM_SYNTH_LEAD 0x50
#define NSX1_PROGRAM_SYNTH_PAD 0x58
#define NSX1_PROGRAM_SYNTH_EFFECTS 0x60
#define NSX1_PROGRAM_ETHNIC 0x68
#define NSX1_PROGRAM_PERCUSSIVE 0x70
#define NSX1_PROGRAM_SOUND_EFFECTS 0x78


class NSX1Controller : public Controller {
    public:
        enum Mode {
            MIKU,
            PIANO,
            CHROMATIC,
            ORGAN,
            GUITAR,
            BASS,
            STRINGS,
            ENSEMBLE,
            BRASS,
            REED,
            PIPE,
            SYNTH_LEAD,
            SYNTH_PAD,
            SYNTH_EFFECTS,
            ETHNIC,
            PERCUSSIVE,
            DRUMS
        };

        NSX1Controller() : Controller(Mode::DRUMS) {}
        virtual void init();
        virtual void update();

    private:
        ChannelController channels[CHANNELS] = {
            ChannelController(Hardware::hw.midiDevice, Hardware::hw.velocityInput1, Hardware::hw.pitchInput1, NSX1_CHANNEL_MIKU),
            ChannelController(Hardware::hw.midiDevice, Hardware::hw.velocityInput2, Hardware::hw.pitchInput2, 2),
            ChannelController(Hardware::hw.midiDevice, Hardware::hw.velocityInput3, Hardware::hw.pitchInput3, 3),
            ChannelController(Hardware::hw.midiDevice, Hardware::hw.velocityInput4, Hardware::hw.pitchInput4, NSX1_CHANNEL_DRUM)
        };

        IntegerInput<> mod1Input = IntegerInput<>(Hardware::hw.modInput1, -5, 5, 0, 7);

        uint8_t instrumentGroup;
        
        void selectInstrumentChannels();
        void selectInstrumentGroup(uint8_t instrumentGroup);
        void selectInstrumentVariation(uint8_t instrumentVariation);
};

#endif
