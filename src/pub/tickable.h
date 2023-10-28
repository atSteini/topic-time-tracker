#ifndef TICKABLE_H
#define TICKABLE_H

#include <Arduino.h>
#include <memory>
#include "State.h"

using namespace std;

class Tickable {
    private:
        bool isFirstTick = true;
    protected:
        State tState = State::NOT_STARTED;
        String name;

        unsigned long latestDt = 0;

        bool autoStart = false;
        bool rootNode = false;

        virtual State tickInterceptor(unsigned long dt);
        virtual State tickImpl(unsigned long dt);
    public:
        static inline unsigned long lastTick;    //inline because it is the new way of writing static variables. only c++17 compatible tough TODO: make c++11 compatible
        static inline bool isFirstSystemTick;

        Tickable();
        virtual ~Tickable() = default;
        virtual void reset();

        const State tick();
        void start();
        void pause();
        void stop();

        bool isFinished();

        virtual void setState(State state_) {tState = state_;}
        State getState() {return tState;}
        State state(State state_) {setState(state_); return state_;}
        void setName(String name_) {name = name_;}
        String getName() {return name;}
        void setAutoStart(bool autoStart_) {autoStart = autoStart_;}
        bool isAutoStart() {return autoStart;}
        void setRootNode(bool rootNode_) {rootNode = rootNode_;}
        bool isRootNode() {return rootNode;}
};

#endif