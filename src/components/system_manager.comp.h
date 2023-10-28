#ifndef SYSTEM_MANAGER_COMP_H
#define SYSTEM_MANAGER_COMP_H

#include <Arduino.h>
#include <TFT_eSPI.h>
#include <memory>

#include "component.h"
#include "app_manager.comp.h"
#include "display_manager.comp.h"

//AppManager holds a vector of apps, that can be selected and run. To select an app, means to set a pointer to currentrunning app. When finished, resets app and clears the pointer

class SystemManager: public Component {
    private:
        shared_ptr<AppManager> app_manager;
        shared_ptr<DisplayManager> display_manager;

        uint32_t background_color = 0x0000;

        State tickImpl(unsigned long dt) override;
    public:
        SystemManager();
        virtual ~SystemManager() = default;

        void init() override;
        void draw(shared_ptr<DisplayManager> dm) override;
        void draw();

        void addApp(shared_ptr<Application> app_) { app_manager->addApp(app_); }

        void setAppManager(shared_ptr<AppManager> app_manager_) { app_manager = app_manager_; }
        shared_ptr<AppManager> getAppManager() { return app_manager; }

        void setDisplayManager(shared_ptr<DisplayManager> display_manager_) { display_manager = display_manager_; }
        shared_ptr<DisplayManager> getDisplayManager() { return display_manager; }
};

#endif