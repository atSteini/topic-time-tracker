#include "timer.app.h"

Timer::Timer() {
    setName("Timer");
}

State Timer::tickImpl(unsigned long dt) {
    return State::RUNNING;
}

void Timer::draw(shared_ptr<DisplayManager> dm) {
    dm->use()->fillRect(10, 10, TFT_WIDTH-10, TFT_HEIGHT-10, TFT_GREEN);
}