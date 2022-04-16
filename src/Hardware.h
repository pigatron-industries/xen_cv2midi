#ifndef Hardware_h
#define Hardware_h

#include <Arduino.h>
#include <USBHost_t36.h>
#include <eurorack.h>
#include "hwconfig.h"

class Hardware {
    public:
        static Hardware hw;
        void init();

        USBHost usb;
        MIDIDevice midiDevice = MIDIDevice(usb);

        RotaryEncoderButton encoder = RotaryEncoderButton(ENCODER_PIN1, ENCODER_PIN2, ENCODER_BTN_PIN);

        AnalogInput(velocityInput1, A7)
        AnalogInput(velocityInput2, A6)
        AnalogInput(velocityInput3, A8)
        AnalogInput(velocityInput4, A9)

        AnalogInput(pitchInput1, A1)
        AnalogInput(pitchInput2, A0)
        AnalogInput(pitchInput3, A2)
        AnalogInput(pitchInput4, A3)

        AnalogInput(modInput1, A12)
        AnalogInput(modInput2, A13)
        AnalogInput(modInput3, A11)
        AnalogInput(modInput4, A10)

};

#endif