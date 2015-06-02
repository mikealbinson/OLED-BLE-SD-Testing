#include <ArduinoUnit.h>
#include <U8glib.h>
//#include <SPI.h>
//#include <SdFat.h>
//#include <RBL_nRF8001.h>
//#include <boards.h>
// {]=:

void setup (){
  Serial.begin (9600);
  
}

void loop () {
  Test::run();
}


String BLERead (){
  String returnString = "";
  return returnString;
}

String SDRead (String SearchThisString){
  String returnString = SearchThisString;
  return returnString;
}

String OLEDInfoSend (String printThis){
  String returnString = "";
  returnString = printThis;
  
  return returnString;
}


test (BLE_functionality) {
  String expectedReceive = "Hello World";
  assertEqual (expectedReceive, BLERead ());
}

test (SD_Functionality) {
  String expectedSearch = "Hello World";
  assertEqual (expectedSearch, SDRead ("Hello World"));
  
}

test (OLED_Functionality) {
  String expectedReturn = "Hello World"; 
  assertEqual (expectedReturn, OLEDInfoSend ("Hello World"));
}
