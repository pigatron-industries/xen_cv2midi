#ifndef Controller_h
#define Controller_h

#include <eurorack.h>
#include "Hardware.h"

class Controller {
    public:
        Controller(int lastMode = 0) : mode(0, lastMode) {}
        virtual void init() {};
        virtual void update() = 0;
        int cycleMode(int amount) { mode.cycle(amount); return mode.value; }
        void setMode(int value) { mode.setValue(value); }
    
    protected: 
        CycleEnum<int> mode;
};

#endif
