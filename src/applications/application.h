#ifndef APPLICATION_H
#define APPLICATION_H

#include <Arduino.h>
#include "../pub/tickable.h"

/*
* Apps can have access to the entire architecture and register themselves as an app by extending this base class and being loaded into the app_manager
* Children need to implement tickImpl.
*/

class Application: public Tickable {
    private:
        //var: icon?
    public:

        //fn: run
        //  - runs the app.

        //fn: stop
        //  - stops the app (can be a no-op).

        //fn: get name - also stored in tickable
        //fn: get icon
};

#endif