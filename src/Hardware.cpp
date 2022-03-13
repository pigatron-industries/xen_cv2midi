#include "Hardware.h"

Hardware Hardware::hw = Hardware();

void Hardware::init() {
    analogReadResolution(12);
}

