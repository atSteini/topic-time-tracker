#ifndef APP_MANAGER_COMP_H
#define APP_MANAGER_COMP_H

#include <Arduino.h>
#include <TFT_eSPI.h>
#include <memory>
#include <vector>

#include "component.h"
#include "../applications/application.h"

//AppManager holds a vector of apps, that can be selected and run. To select an app, means to set a pointer to currentrunning app. When finished, resets app and clears the pointer

class AppManager: public Component {
    private:
        boolean startAppIfOnlyOne = true;

        vector<shared_ptr<Application>> apps;
        shared_ptr<Application> selectedApp;

        State tickImpl(unsigned long dt) override;
    public: 
        AppManager();
        virtual ~AppManager() = default;

        void init() override;
        void draw(shared_ptr<DisplayManager> dm) override;

        void addApp(shared_ptr<Application> app_);
        void selectApp(int index);  //selects an app
        void quitApp(); // stops the running app
        void runSelectedApp();
};

#endif