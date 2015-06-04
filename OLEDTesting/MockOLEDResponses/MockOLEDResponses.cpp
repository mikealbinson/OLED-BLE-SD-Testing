#include "MockOLEDResponses.h"

int MockOLED::MockPrintToOLED (String printThis){
	return 1; //if true... which I guess is true every time
}

int MockOLED::setColorIndexMock (int type){
	int happy = type;
	return 1; //if done
}

MockOLED::MockOLED () {
	MOCKu8g = new U8GLIB_SSD1306_128X32MOCK(U8G_I2C_OPT_NONE);
  MOCKu8g->getMode() == U8G_MODE_BW;
  MOCKu8g->setColorIndex(1);
	exists=true;
}

void MockOLED::drawSetupMock(MockOLED& obj) {
	Serial.begin (9600); //alternately comment out if using more than one setup function
	TestTrue ("OLED init test", obj.exists);
	int printed = obj.MockPrintToOLED ("Setting Up"); //There's an interior method here that interacts with the OLED
	TestEqual ("drawSetup Print Check", printed, 1 );
}

const char* MockOLED::drawGeneralMock(String stringToPrint,MockOLED& obj) {
	const char* conversion;
	const char* smaller;
  conversion = stringToPrint.c_str();
	int printed = obj.MockPrintToOLED (conversion); //There's an interior method here that interacts with the OLED
	TestEqual ("drawGeneralPrintCheck", printed, 1 );
	return conversion;
}

//Still hoping to include a bitmap fxn at some point if I can figure out how to get a bitmap in the proper format

//Done Shortening --Start Testing tomorrow
