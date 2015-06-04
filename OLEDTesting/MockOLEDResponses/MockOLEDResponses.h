#ifndef _MOCKOLEDRESPONSES_H
#define _MOCKOLEDRESPONSES_H

#include <U8gLibClone.h>
#include <Testing.h>
#include "Arduino.h"

int printToOLED (String printThis);

class MockOLED{
	private:
	U8GLIB_SSD1306_128X32MOCK *MOCKu8g;
	bool exists;
		
	
  public:
		int MockPrintToOLED (String printThis);
		int setColorIndexMock(int type);
  	MockOLED();
		void drawSetupMock(MockOLED &obj);
  	const char* drawGeneralMock(String stringToPrint, MockOLED &obj);
};



#endif // MockOLEDResponses.h

