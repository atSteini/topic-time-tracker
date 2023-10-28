#ifndef APPMANAGER_COMP_H
#define APPMANAGER_COMP_H

#include <Arduino.h>
#include "component.h"

#include "../applications/application.h"
#include "../pub/state.h"
#include <memory>
#include <vector>

//AppManager holds a vector of apps, that can be selected and run. To select an app, means to set a pointer to currentrunning app. When finished, resets app and clears the pointer

class AppManager: public Component {
    private:
        boolean startAppIfOnlyOne = true;

        vector<shared_ptr<Application>> apps;
        shared_ptr<Application> selectedApp;

        State tickImpl(unsigned long dt) override;
    public: 
        void addApp(shared_ptr<Application> app_);
        void selectApp(int index);
        void runSelectedApp();
};

#endif