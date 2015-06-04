#include <U8gLibClone.h>
#include <Testing.h>
#include <MockOLEDResponses.h>

MockOLED oled1;

void setup() {
  // put your setup code here, to run once:
  oled1.drawSetupMock(oled1);
  oled1.drawGeneralMock("Print this", oled1);
}

void loop() {
  // put your main code here, to run repeatedly:
}
