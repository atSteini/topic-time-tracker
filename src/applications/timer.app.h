#ifndef TIMER_APP_H
#define TIMER_APP_H

#include <Arduino.h>
#include <TFT_eSPI.h>

#include "application.h"
#include "../components/display_manager.comp.h"

class Timer: public Application {
    private:
        State tickImpl(unsigned long dt) override;
    public:
        Timer();
        virtual ~Timer() = default;

        void draw(shared_ptr<DisplayManager> dm) override;
};

#endif