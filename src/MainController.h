#ifndef MainController_h
#define MainController_h

#include <eurorack.h>
#include <inttypes.h>

#include "Hardware.h"
#include "USBHost_t36.h"
#include "midi/ChannelController.h"

class MainController {

    public:
        MainController();
        void init();
        void update();

    private:
        USBHost usb;
        MIDIDevice midiDevice = MIDIDevice(usb);

        ChannelController channels[1] = {
            ChannelController(midiDevice, Hardware::hw.velocityInput1, Hardware::hw.pitchInput1, 1)
        };
};

#endif
