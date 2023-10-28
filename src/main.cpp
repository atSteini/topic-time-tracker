#include <Arduino.h>

#include <TFT_eSPI.h> // Hardware-specific library
#include <SPI.h>

#include "pub/globals.h"
#include "components/system_manager.comp.h"
#include "components/app_manager.comp.h"
#include "components/display_manager.comp.h"
#include "components/wifi.comp.h"
#include "applications/timer.app.h"

const int static_framerate = 300; //fps

//Init all the apps
SystemManager system_manager = SystemManager();
Timer timerApp = Timer();

int fdelay() {
  return MS_PER_S / static_framerate;
}

void setup() {
  Serial.begin(115200);

  //Add all the apps
  system_manager.addApp(make_shared<Timer>(timerApp));

  system_manager.getAppManager()->selectApp(0);
  system_manager.getAppManager()->runSelectedApp();

  system_manager.init();
}

int lcount = 0;
void loop() {
  system_manager.tick();
  system_manager.draw();
  
  if (lcount >= 5 * MS_PER_S / fdelay()) {
    system_manager.getAppManager()->quitApp();
    lcount = 0;
  }

  lcount++;
  delay (fdelay());
}


/*
#include <TFT_eSPI.h> // Hardware-specific library
#include <SPI.h>

TFT_eSPI tft = TFT_eSPI();       // Invoke custom library
//can we create frames or spaces for tft so that we can pass a tft object and it is not the full screen?

void setup(void) {
  Serial.begin(115200);
  Serial.println("Hello! ST7789V TFT Test");

  tft.init();

  Serial.println("Initialized");

  uint16_t time = millis();
  tft.fillScreen(TFT_BLACK);
  time = millis() - time;

  Serial.printf("It took %d ms to fill with black.\n", time);

  tft.drawRect(0, 0, tft.width(), tft.height(), TFT_GREEN);
  tft.fillCircle(tft.width()/2, tft.height()/2, tft.width()/4, TFT_PURPLE);

  Serial.println("done");
}
*/
