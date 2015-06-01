
#include <U8glib.h>
//#include <SPI.h>
//#include <SdFat.h>
//#include <RBL_nRF8001.h>
//#include <boards.h>
// {]=:

void setup (){
  Serial.begin (9600);
  
  testbleRead ();
  
  testSDRead ();
  
  testOLEDInfoSend ();
}

void loop () {

}


String BLERead (){
  String returnString = "";
  return returnString;
}

String SDRead (){
  String returnString = "";
  return returnString;
}

String OLEDInfoSend (String printThis){
  String returnString = "";
  returnString = printThis;
  
  return returnString;
}


bool testbleRead (){
  String expectedReturn= "Hello World";
  if ( BLERead() == expectedReturn)
     Serial.println ("BLE SUCCESS!");
  else
    Serial.println ("BLE Failure");
     
}

bool testSDRead (){ //Implement test SD class?
  String expectedReturn= "Hello World";
  if ( SDRead() == expectedReturn)
     Serial.println ("SD SUCCESS!");
  else
    Serial.println ("SD Failure");
}

bool testOLEDInfoSend (){ //implement test OLED class?
  String expectedReturn= "Hello World";
  if ( OLEDInfoSend() == expectedReturn)
     Serial.println ("OLED SUCCESS!");
  else
    Serial.println ("OLED Failure");
}

