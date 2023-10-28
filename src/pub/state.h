#ifndef STATE_H
#define STATE_H

#include <Arduino.h>

class State {
    public:
        enum StateEnum : uint8_t {
            NOT_STARTED = 0,
            RUNNING = 1,
            PAUSED = 2,
            FINISHED = 3,
            CHILD_FINISHED = 4
        };
        State() = default;
        constexpr State(StateEnum state_) : value(state_) { }

        constexpr bool operator==(State a) const { return value == a.value; }
        constexpr bool operator!=(State a) const { return value != a.value; }
        State& operator=(StateEnum v) { value = v; return *this;}
        
        const bool isFinished() {
            return value == FINISHED;
        }

        const bool isChildFinished() {
            return value == CHILD_FINISHED;
        }

        const bool isRunning() {
            return value == RUNNING || value == CHILD_FINISHED;
        }

        const String getName() {
            String name;
            switch (value) {
                case 0:
                    name = "NOT_STARTED";
                    break;
                case 1:
                    name = "RUNNING";
                    break;
                case 2:
                    name = "PAUSED";
                    break;
                case 3:
                    name = "FINISHED";
                    break;
                case 4:
                    name = "CHILD_FINISHED";
                    break;
                default:
                    name = String(value);
            }
            return name;
        }
    private:
        StateEnum value;
};


#endif