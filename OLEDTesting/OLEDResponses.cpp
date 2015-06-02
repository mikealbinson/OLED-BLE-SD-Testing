#include "OLEDResponses.h"

const char* stringToChar (String desiredText) {
  const char* conversion;
  conversion = desiredText.c_str();
  return conversion;
}

OLED::OLED () {
	u8g = new U8GLIB_SSD1306_128X32(U8G_I2C_OPT_NONE);
  u8g->getMode() == U8G_MODE_BW;
	u8g->setColorIndex(1);
}

OLED::OLED(bool TestSwitch) { //creates MockOLED object if input is true--based on U8gLibClone library
  if (TestSwitch == true) 
	{
    MOCKu8g = new U8GLIB_SSD1306_128X32MOCK(U8G_I2C_OPT_NONE);
    MOCKu8g->getMode() == U8G_MODE_BW;
    MOCKu8g->setColorIndex(1);
  }
  else {
		OLED ();
  }
}


void OLED::drawSetup() {
  u8g->firstPage();
  do {
    u8g->setFont(u8g_font_unifont);
    u8g->drawStr( 0, 22, "Setting up...");
  } while ( u8g->nextPage() );
  delay(3000);
}

const char* OLED::drawGeneral(String stringToPrint) {
	const char* conversion;
  conversion = stringToPrint.c_str();
  u8g->firstPage();
  do {
    u8g->setFont(u8g_font_unifont);
    u8g->drawStr( 0, 22, conversion);
  } while ( u8g->nextPage() );
  delay(3000);
}



//Done Shortening --Start Testing tomorrow
