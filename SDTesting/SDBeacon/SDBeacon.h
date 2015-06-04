/*
* SDBeacon.h
*
*
*/


#ifndef SDBeacon_h
#define SDBeacon_h

#include "Arduino.h"
#include <SdFat.h> //THIS FILE REQUIRES A MODIFIED VERSION OF <SD.h>
#include <SPI.h>

#define maxTitleSize 16

void SDBeaconSetup(SdFat& SD); //go here to change files that are being searched for each type
String textFileSelect ();
String TicketInfoParser (String TicketString, int typeReturn); 
bool ticketCompare (String searchFor, const char* compareToThis);
bool ticketCompare (const char* searchFor, String compareToThis);
bool ticketCompare (String searchFor, String compareToThis);
bool searchDatabaseForTicket(String TicketString, SdFat& SD);
void writeToSD(String writeThisString, String fileName, SdFat& SD);
void simpleReadSD (String fileName, SdFat& SD);
void fileRemove (String fileName, SdFat& SD);
bool parseTextLines (int lineIndex, String TicketRecieved, SdFat& SD);

#endif

