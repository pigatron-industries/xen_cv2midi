#ifndef Hardware_h
#define Hardware_h

#include <Arduino.h>
#include <eurorack.h>
#include "hwconfig.h"

class Hardware {
    public:
        static Hardware hw;
        void init();

        AnalogInput(velocityInput1, A9)
        AnalogInput(pitchInput1, A8)

};

#endif