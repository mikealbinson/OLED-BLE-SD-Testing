/*
*
*SDBeaconFunctionsRevised.cpp
*
*/

#include "SDBeaconFunctionsRevised.h"
SdFat SD;

void SDBeaconSetup () {//Checked and good YEP
	Serial.begin (9600);
  Serial.print(F("Initializing SD card..."));
	pinMode(10, OUTPUT);
	
  if (!SD.begin(4)) {
    Serial.println(F("initialization failed!"));
    return;
  }
  Serial.println(F("initialization done."));

}

String textFileSelect (){//Unused, probably fine YEP
	int i = 0;
	char stringBase [maxTitleSize];
	String fileTitle;
	if (Serial.available ())
	{
		while (Serial.available()){
			int carrier = Serial.read();
			stringBase[i] = carrier;
			i++;
		}
		for (i=0; i<maxTitleSize; i++){
			fileTitle = fileTitle + stringBase [i];
		}
		return fileTitle;
	}
}

String TicketInfoParser (String TicketString, int typeReturn){ //difficult to break up, consider
  String TicketNumberRetrieve = "", TicketNameRetrieve = "", TicketTypeRetrieve = "";
  int lengthString, commaIndex1, commaIndex2;
  TicketString.replace(" ", "");
  lengthString = TicketString.length();
  commaIndex1 = TicketString.indexOf(',');
  commaIndex2 = TicketString.indexOf(',', commaIndex1+1);
    switch (typeReturn){
      case 1:
        TicketNumberRetrieve = TicketString.substring (0, commaIndex1);
        return TicketNumberRetrieve;
        break;
      case 2:
        TicketNameRetrieve = TicketString.substring (commaIndex1+1, commaIndex2);
        return TicketNameRetrieve;
        break;
      case 3:
        TicketTypeRetrieve = TicketString.substring (commaIndex2+1, lengthString);
        return TicketTypeRetrieve;
        break;
      default:
        return "empty";
        Serial.println ("this is not an acceptable input");
        break;
    }
}

const char* StringConversion (String inputString){ //YEP
	const char * conversion;
	conversion = inputString.c_str();
	return conversion;
}

bool searchDatabaseForTicket(String TicketString){ //No way to sensibly shorten
		File myFile;
		const char* TicketNo = StringConversion (TicketString);
		myFile = SD.open("test.txt");  
		if (myFile) {
    	char buf[16];
    	myFile.read(buf, 16);
    	if (strncmp(buf, TicketNo, 14) == 0)
    	{
      	Serial.println(F("Match!"));
      	return true;
    	}
    	else {
				Serial.println ("No Match");
      	return false;
    	}
    myFile.close();
  }
	else {
	Serial.println(F("error opening file"));
  }
}

void writeToSD (String writeThisString, String fileName) { //No good way to sensibly shorten
	File myFile;
	const char* conversion = StringConversion (fileName);
	myFile = SD.open(conversion, FILE_WRITE);
  if (myFile) {
    myFile.println(writeThisString);
    myFile.close();
  } 
	else {
    Serial.println(F("error opening example.txt"));
  }
}

void simpleReadSD (String fileName){ //No way to sensibly shorten
	
	File myFile;
	const char* conversion = StringConversion (fileName);
	myFile = SD.open(conversion);
	  if (myFile) {
	    Serial.print(conversion);
			Serial.println (F(":"));
	    while (myFile.available()) {
	      Serial.write(myFile.read());
	    }
	    myFile.close();
	  } 
	else {
			Serial.print (conversion);
			Serial.println (F(" does not exist"));
	  }
}

void fileRemove (String fileName) { //YEP
	File myFile;
	const char* conversion = StringConversion (fileName);
  myFile = SD.open(conversion);
  SD.remove(conversion);
}
