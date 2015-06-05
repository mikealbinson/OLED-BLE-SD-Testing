#include "mocks.h"

void testingScenario (){
	Serial.begin (9600);
  Serial.println(F("Feature: hands-free ticket scanning"));
  Serial.println (F("the objective is to read a ticket from a phone"));
  Serial.println (F("and then check the database for that ticket"));
  Serial.println (F("and then display if it exists and its type"));
  Serial.println (F(""));
  Serial.println (F(""));
  Serial.println (F("Scenario: User customer up to the beacon and wants their ticket scanned"));
}

void endOfScenario (){
	Serial.println (F("The user reads the OLED and allows the customer to continue through"));
}

/*************MOCKFILE AND MOCKSD DEFINITIONS*************/
MockFile:: MockFile  (){
}

bool MockFile :: read(){
	Serial.println (readerString);
	return true;
}

bool MockFile :: read (char* interest, int that){
	Serial.println (readerString);
	return true;
}

bool MockFile :: close (){
	return true;
}

bool MockFile :: available() {
	return true;
}

String MockFile :: println(String lineToPrint){
	return lineToPrint;
}

MockSdFat :: MockSdFat(){
		
}
	
bool MockSdFat :: open (String file){
	return true;
}

bool MockSdFat :: open(String file, const uint8_t function){
	return true;
}

bool MockSdFat :: begin (int i){
	return true;
}

bool MockSdFat :: remove (String file){
	return true;
}

bool MockSdFat :: available() {
	return true;
}
/*********************************************************/
/*************MockTicketBeacon implementations************/
MockSDBeacon::MockSDBeacon(){
	//if ya need something
}

void MockSDBeacon::SDBeaconSetup (MockSdFat& SD) {//Checked and good YEP
	//Serial.begin (9600);
  Serial.print(F("Initializing SD card..."));
	pinMode(10, OUTPUT);
	
  if (!SD.begin(4)) {
    Serial.println(F("initialization failed!"));
    return;
  }
  Serial.println(F("initialization done."));
	TestTrue ("The SD is setup", SD.available());
}

bool MockSDBeacon::searchDatabaseForTicket(String TicketString, MockSdFat& SD, MockFile& myFile){ //No way to sensibly shorten
		const char* TicketNo = TicketString.c_str();
		//myFile = SD.open("test.txt");  
		if (myFile.available()) {
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
	Serial.println(F("error opening file")); //error
  }
}

void MockSDBeacon::writeToSD (String writeThisString, String fileName, MockSdFat& SD, MockFile& myFile) { //No good way to sensibly shorten
	const char* conversion = fileName.c_str();
	String printedThis;
	//Serial.println (conversion);
	//myFile = SD.open(conversion);
  if (myFile.available()) {
    printedThis = myFile.println(writeThisString);
    myFile.close();
  } 
	else {
    Serial.println(F("error opening example.txt"));
  }
	TestEqual ("writeToSD", printedThis, writeThisString);
}

void MockSDBeacon::simpleReadSD (String fileName, MockSdFat& SD, MockFile& myFile){ //No way to sensibly shorten
	const char* conversion = fileName.c_str();
	//myFile = SD.open(conversion, FILE_READ);
	if (myFile.available()) {
	  while (bool success = myFile.available()) {
	    Serial.write(myFile.read());
			TestTrue ("simpleRead", success);
			break;
	  }
	  myFile.close();
	} 
	else 
	{
	    Serial.print(F("Error opening "));
			Serial.println (fileName);
	 }
}

void MockSDBeacon::fileRemove (String fileName, MockSdFat& SD, MockFile& myFile) {
	const char* conversion = fileName.c_str();
   SD.open(conversion);
	TestTrue ("fileremove", SD.remove(conversion));
}

/*********************************************************/
/******************MockOLED imp***************************/
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
	//Serial.begin (9600); //alternately comment out if using more than one setup function
	TestTrue ("The OLED is setup", obj.exists);
	int printed = obj.MockPrintToOLED ("Setting Up"); //There's an interior method here that interacts with the OLED
	TestEqual ("drawSetup Print Check", printed, 1 );
}

const char* MockOLED::drawGeneralMock(String stringToPrint,MockOLED& obj) {
	const char* conversion;
	const char* smaller;
  conversion = stringToPrint.c_str();
	int printed = obj.MockPrintToOLED (conversion); //There's an interior method here that interacts with the OLED directly and that needed to be changed
	TestEqual ("The type is displayed on the OLED", printed, 1 );
	return conversion;
}

/*********************************************************/
/******************MockBLE imp***************************/
char MockBLE_read (int &i){
	char sendByteByByte [CHARS_TO_READ] = {"HelloYouThere"};
	return sendByteByByte [i];
}

const char* MockBLE_write (int carrier, int &i){
	char charArray [CHARS_TO_READ] ={};
	if (i<CHARS_TO_READ)
		charArray[i] = carrier;
	if (i ==14)
		return charArray;
}

MockBLE::MockBLE (){
}

void MockBLE::TflyBLESetup(){  //Use only in the setup loop  YEP
  ble_set_name ("TFLY");
  ble_begin ();
  //Serial.begin (57600);
	TestTrue ("The ble is setup", true);
}

void MockBLE::clearParsingSetups(String stringToClear, char charArrayToClear[]){
  for (int i=0; i<CHARS_TO_READ; i++){
    charArrayToClear[i] = 1;
	TestEmpty ("clear parsing--array", charArrayToClear[i]);
  }
  stringToClear= "";

	TestEmpty ("clear parsing--String", stringToClear);
}

void MockBLE::beaconSendData(){ 
  int carrier;
	String inputString = "HelloYouThere";
	String final="";
  if (Serial.available()){
		int i=0;
    delay(5);
    while (Serial.available()){
      carrier = Serial.read();
      final = MockBLE_write ( carrier, i );
			i++;
    }
  }
	TestEqual ("We send data", final, inputString);
}

String MockBLE::readIncoming(){ //No good way to significantly shorten this one--consider revising
  int i=0;
  char stringBase[CHARS_TO_READ];
  char sendByteByByte [CHARS_TO_READ] = {"HelloYouThere"};
	for (int i=0; i<CHARS_TO_READ; i++){
    stringBase[i] = 1;
  }
  String finalString="";
  if (ble_available){
	  int i=0;
    while (ble_available){
      char carrier = MockBLE_read(i);
      Serial.write (carrier);
      if (i<CHARS_TO_READ){
        stringBase [i] = carrier;
      }
      i++;
			if (i>13)
				break;
    }
    for (i=0;i<CHARS_TO_READ;i++){
      finalString = finalString + stringBase[i];
    }
    Serial.println("");
    Serial.println (finalString);
	  TestEqual ("we read ticket data from the BLE", finalString, sendByteByByte);
    return finalString;
  }
}
