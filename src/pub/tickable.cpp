#include "Tickable.h"

Tickable::Tickable() {
    setName("DEFAULT_Tickable");
}

State Tickable::tickInterceptor(unsigned long dt) {
    if (!getState().isRunning()) {
        return getState();
    }

    State before = getState();
    //Serial.printf("TICK: %s | Before: {%s} - After: {\n", getName().c_str(), before.getName().c_str());

    State after = tickImpl(dt);
    //Serial.printf("} -> %s\n", after.getName().c_str());

    return after;
}

State Tickable::tickImpl(unsigned long dt) {
    return State::FINISHED;
}

const State Tickable::tick() {
    unsigned long lastTickCorrect = millis();  //Saving last Tick here so that, if there is an offset, there is a constant offset between ticks. Also to make tick-times independent of the time it takes to finish the tickInterceptor()

    if (isFirstTick) {
        isFirstTick = false;

        if (isAutoStart()) {
            start();
        }
    }

    if (tState != State::PAUSED) {
        latestDt = lastTickCorrect - Tickable::lastTick;
    }

    setState(tickInterceptor(latestDt));

    if (isRootNode()) {
        Tickable::lastTick = lastTickCorrect;
    }

    return getState();
}

void Tickable::reset() {
    setState(State::NOT_STARTED);
    isFirstTick = true;
}

void Tickable::start() {
    if (Tickable::isFirstSystemTick) {
        Tickable::lastTick = millis();
        Tickable::isFirstSystemTick = false;
    }

    setState(State::RUNNING);
}

void Tickable::pause() {
    setState(State::PAUSED);
}

void Tickable::stop() {
    setState(State::FINISHED);
}

bool Tickable::isFinished() {
    return tState.isFinished();
}