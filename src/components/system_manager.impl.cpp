#include "system_manager.comp.h"

SystemManager::SystemManager() {
    rootNode = true;

    app_manager = make_shared<AppManager>(AppManager());
    display_manager = make_shared<DisplayManager>(DisplayManager());
}

void SystemManager::init() {
    Serial.println("Initializing SystemManager...");
    
    app_manager->init();
    display_manager->init();

    Serial.println("Done initializing SystemManager!");
}

State SystemManager::tickImpl(unsigned long dt) {
    //TODO: multithreading or rtos but good for now...

    State state_am = app_manager->tick();
    State state_dm = display_manager->tick();

    if (state_am == State::RUNNING && state_dm == State::RUNNING) {
        return State::RUNNING;
    }

    if (state_am != State::RUNNING) {
        return state_am;
    }

    return state_dm;
}

void SystemManager::draw() {
    draw(display_manager);
}

void SystemManager::draw(shared_ptr<DisplayManager> dm) {
    //dm->use()->fillScreen(background_color);    //clearing the screen inbetween frames; -- CAUSES FLICKERING!

    app_manager->draw(display_manager);
    display_manager->draw();
}
