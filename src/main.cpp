#include <Arduino.h>

/*
#include "components/app_manager.comp.h"
#include "components/display_manager.comp.h"
#include "components/wifi.comp.h"
#include "applications/timer.app.h"

//Init all the apps

void setup() {
  //Add all the apps
}

void loop() {
  //Tick the AppManager
}
*/

#include <TFT_eSPI.h> // Hardware-specific library
#include <SPI.h>

TFT_eSPI tft = TFT_eSPI();       // Invoke custom library

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

void loop() {

}
