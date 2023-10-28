#include "app_manager.comp.h"

State AppManager::tickImpl(unsigned long dt) {
    return this->selectedApp->tick();
}

void AppManager::addApp(shared_ptr<Application> app_) {
    this->apps.push_back(app_);
}

void AppManager::selectApp(int index) {
    this->selectedApp = this->apps.at(index);
}

void AppManager::runSelectedApp() {
    this->selectedApp->start();
}