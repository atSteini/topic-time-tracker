#ifndef COMPONENT_H
#define COMPONENT_H

#include <Arduino.h>
#include <TFT_eSPI.h>

#include "../pub/tickable.h"
#include "../pub/state.h"
#include "display_manager.fwd.h"

class Component: public Tickable {
    private:
        virtual State tickImpl(unsigned long dt) override { return State::FINISHED; }
    public:
        Component() = default;
        virtual ~Component() = default;

        virtual void init();
        virtual void draw(shared_ptr<DisplayManager> dm);
};

#endif