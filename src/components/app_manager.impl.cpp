#include "app_manager.comp.h"

AppManager::AppManager() {

}

void AppManager::init() {
    Serial.println("Initializing AppManager...");

    Serial.println("Done initializing AppManager!");
}

void AppManager::draw(shared_ptr<DisplayManager> dm) {

    //the app is running
    if (selectedApp->getState().isAppRunning()) {
        selectedApp->draw(dm);

        return;
    } 

    //draw app logo
    dm->use()->fillCircle(TFT_WIDTH/2, TFT_HEIGHT/2, TFT_WIDTH/3, TFT_RED);
}

State AppManager::tickImpl(unsigned long dt) {
    return this->selectedApp->tick();
}

void AppManager::addApp(shared_ptr<Application> app_) {
    this->apps.push_back(app_);
}

void AppManager::selectApp(int index) {
    if (index > apps.size()-1) {
        return;
    }

    this->selectedApp = this->apps.at(index);
}

void AppManager::quitApp() {
    this->selectedApp->stop();
}

void AppManager::runSelectedApp() {
    this->selectedApp->start();
}