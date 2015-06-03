/*
* SDBeaconFunctionsRevised.h
*
*
*/


#ifndef SDBeaconFunctionsRevised_h
#define SDBeaconFunctionsRevised_h

#include "Arduino.h"
#include <SdFat.h> //THIS FILE REQUIRES A MODIFIED VERSION OF <SD.h>
#include <SPI.h>

#define maxTitleSize 16

void SDBeaconSetup(); //go here to change files that are being searched for each type
String textFileSelect ();
String TicketInfoParser (String TicketString, int typeReturn);
const char* StringConversion (String inputString);
bool searchDatabaseForTicket(String TicketString);
void writeToSD(String writeThisString, String fileName);
void simpleReadSD (String fileName);
void fileRemove (String fileName);
#endif

