#ifndef Hardware_h
#define Hardware_h

#include <Arduino.h>
#include <eurorack.h>
#include "hwconfig.h"

class Hardware {
    public:
        static Hardware hw;
        void init();

        AnalogInput(pitchInput1, A9)
        AnalogInput(pitchInput2, A8)
        AnalogInput(pitchInput3, A7)
        AnalogInput(pitchInput4, A6)

        AnalogInput(velocityInput1, A3)
        AnalogInput(velocityInput2, A2)
        AnalogInput(velocityInput3, A1)
        AnalogInput(velocityInput4, A0)

        AnalogInput(modInput1, A12)
        AnalogInput(modInput2, A11)
        AnalogInput(modInput3, A10)
        AnalogInput(modInput4, A13)

        
};

#endif