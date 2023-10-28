#ifndef DISPLAY_MANAGER_COMP_H
#define DISPLAY_MANAGER_COMP_H

#include <Arduino.h>
#include "component.h"
#include "../pub/globals.h"

const unsigned int time_until_sleep = 15 * MS_PER_S;

class DisplayManager: public Component {
    private:
        //fn: tickImpl
    public:
};

#endif