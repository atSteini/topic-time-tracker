#ifndef DISPLAY_MANAGER_COMP_H
#define DISPLAY_MANAGER_COMP_H

#include <Arduino.h>
#include <TFT_eSPI.h>

#include "component.h"
#include "../pub/globals.h"

const unsigned int time_until_sleep = 15 * MS_PER_S;

class DisplayManager: public Component {
    private:
        shared_ptr<TFT_eSPI> display;

        State tickImpl(unsigned long dt) override;
    public:
        DisplayManager();
        virtual ~DisplayManager() = default;

        void init() override;

        //Functions like turnOn/turnOff

        void draw(shared_ptr<DisplayManager> dm) override;
        void draw();

        shared_ptr<TFT_eSPI> getDisplay() { return display; }
        shared_ptr<TFT_eSPI> use() { return getDisplay(); }
        void setDisplay(shared_ptr<TFT_eSPI> display_) { display = display_; }
};

#endif