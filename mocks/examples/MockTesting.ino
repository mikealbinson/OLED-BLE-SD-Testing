#include <U8gLibClone.h>
#include <Testing.h>
#include <SPI.h>
#include <boards.h>
#include <RBL_LibCLONE.h>
#include <mocks.h>

MockOLED oled1;
MockFile myFile;
MockSdFat Sdfat;
MockSDBeacon SDB;
MockBLE ble;
String stringInterface = "";

void setup() {
  testingScenario();
  ble.TflyBLESetup();
  oled1.drawSetupMock(oled1);
  SDB.SDBeaconSetup (Sdfat);
  stringInterface = ble.readIncoming();
  SDB.searchDatabaseForTicket (stringInterface, Sdfat, myFile);
  oled1.drawGeneralMock ("TicketTypeDisplayed", oled1);
  endOfScenario ();
}

void loop() {
  // put your main code here, to run repeatedly:

}
