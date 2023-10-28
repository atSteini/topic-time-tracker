#ifndef COMPONENT_H
#define COMPONENT_H

#include <Arduino.h>
#include "../pub/tickable.h"
#include "../pub/state.h"

class Component: public Tickable {
    private:
        virtual State tickImpl(unsigned long dt) override;
    public:
};

#endif