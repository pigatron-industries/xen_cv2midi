#ifndef MainController_h
#define MainController_h

#include <eurorack.h>
#include <inttypes.h>

#include "Hardware.h"

class MainController {

    public:
        MainController();
        void init();
        void update();

};

#endif
