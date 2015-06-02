#ifndef OLEDResponses_h
#define OLEDResponses_h

#include <U8gLibClone.h>
#include "Arduino.h"

const char * stringToChar (String desiredText); //was giving me a hard time if I included it in the class definitions
																								//but doesn't work inside the class if I declare it here.. ideally
																								//would go inside drawGeneral and replace those first two lines

class OLED{
  private: 
  U8GLIB_SSD1306_128X32 *u8g;
	U8GLIB_SSD1306_128X32MOCK *MOCKu8g;
	
  public:
  OLED();
	OLED(bool TestSwitch);
  void drawSetup();
  const char* drawGeneral(String stringToPrint);
};



#endif // TicketResponsesRevised_h

