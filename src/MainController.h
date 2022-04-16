#ifndef MainController_h
#define MainController_h

#include <eurorack.h>
#include <inttypes.h>

#include "Hardware.h"
#include "apps.h"
#include "Controller.h"

class MainController : public AbstractMainController<Controller, CONTROLLERS> {

    public:
        MainController();
        void init();
        void update();

};

#endif
