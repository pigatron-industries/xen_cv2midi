#ifndef NSX1Controller_h
#define NSX1Controller_h

#include "Controller.h"
#include "midi/ChannelController.h"

using namespace eurorack;

class NSX1Controller : public Controller {
    public:
        NSX1Controller() : Controller(0x7F) {}
        virtual void init();
        virtual void update();

    private:
        ChannelController channels[4] = {
            ChannelController(Hardware::hw.midiDevice, Hardware::hw.velocityInput1, Hardware::hw.pitchInput1, 1),
            ChannelController(Hardware::hw.midiDevice, Hardware::hw.velocityInput2, Hardware::hw.pitchInput2, 2),
            ChannelController(Hardware::hw.midiDevice, Hardware::hw.velocityInput3, Hardware::hw.pitchInput3, 3),
            ChannelController(Hardware::hw.midiDevice, Hardware::hw.velocityInput4, Hardware::hw.pitchInput4, 10)
        };
        
};

#endif
