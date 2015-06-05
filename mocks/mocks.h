#ifndef MOCKS_H_
#define MOCKS_H_

#include "arduino.h"
#include <U8gLibClone.h>
#include <Testing.h>
#include <SPI.h>
#include <boards.h>
#include <RBL_LibCLONE.h>

#define CHARS_TO_READ 14

void testingScenario ();
void endOfScenario ();

class MockFile{
public:
	MockFile();
	bool read();
	const char* read (const char* interest, int that);
	bool close();
	String println(String lineToPrint);
	bool available();
	
private:
	String readerString = "HelloYouThere";
};

class MockSdFat {
 public:
	MockSdFat();
	bool open(String file);
	bool open(String file, const uint8_t function);
	bool begin(int i);
	bool remove (String file);
	bool available(); 

};

class MockSDBeacon{
public:
	  MockSDBeacon();
		void SDBeaconSetup (MockSdFat& SD);
		bool searchDatabaseForTicket(String TicketString, MockSdFat& SD,  MockFile& myFile);
		void writeToSD (String writeThisString, String fileName, MockSdFat& SD, MockFile& myFile);
		void simpleReadSD (String fileName, MockSdFat& SD, MockFile& myFile);
		void fileRemove (String fileName, MockSdFat& SD, MockFile& myFile);
};

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

class MockBLE {
public:
	MockBLE();
	void TflyBLESetup ();
	void clearParsingSetups(String stringToClear, char charArrayToClear[]);
	void beaconSendData();
	String readIncoming();
	
private:
	int ble_available = true; //let's assume we're costantly connected
	char MockBLE_Read(int &i);
	const char* MockBLE_write (int carrier, int &i);
	
};


#endif
