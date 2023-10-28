#include "display_manager.comp.h"

DisplayManager::DisplayManager() {
    display = make_shared<TFT_eSPI>(TFT_eSPI());
}

void DisplayManager::init() {
    Serial.println("Initializing DisplayManager...");

    use()->init();
    use()->fillScreen(TFT_BLACK);

    Serial.println("Done initializing DisplayManager!");
}

State DisplayManager::tickImpl(unsigned long dt) {
    return State::RUNNING;
}

void DisplayManager::draw() {
    //Draw UI Maybe...

}

void DisplayManager::draw(shared_ptr<DisplayManager> dm) {
    draw();
}
