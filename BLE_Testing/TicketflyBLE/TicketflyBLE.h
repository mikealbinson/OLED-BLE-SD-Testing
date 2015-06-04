/*
* Work in Progress
*
* NOTE: If you don't include one of the body (loop) functions, you MUST add ble_do_events() to the body of your 
* loop function, otherwise the BLE will not initialize
*/

#ifndef TICKETFLYBLE_H_
#define TICKETFLYBLE_H_


#include "Arduino.h"
#include <SPI.h>
#include <boards.h>
#include <RBL_LibCLONE.h>
#include <Testing.h>

#define CHARS_TO_READ 14 //Set number of char to read from the BLE (max of 16)

class BLE {
public:
	BLE();
	BLE (bool enterMockFlag);
	void TflyBLESetup ();
	void startBLEScan();//currently empty
	void clearParsingSetups(String stringToClear, char charArrayToClear[]);
	void beaconSendData();
	void beaconRequestInfo();
	String readIncoming();
	
private:
	int mockFlag;
};

#endif
