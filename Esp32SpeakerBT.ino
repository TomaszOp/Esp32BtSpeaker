#include "src/Esp32BtSpeaker/Esp32BtSpeaker.h"

Esp32BtSpeaker Esp32BtSpeaker;

void setup() 
{

  Serial.begin(115200);
  Esp32BtSpeaker.Start("BtSpeaker");

}

void loop() {

 delay(1000); // do nothing

}
