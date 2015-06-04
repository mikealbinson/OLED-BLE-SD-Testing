// TFLY_BLE_BEACON.cpp

#include "TicketflyBLE.h"

BLE::BLE (){
	mockFlag = false;
}

BLE::BLE (bool enterMockFlag){
	mockFlag = enterMockFlag;
}

void BLE::TflyBLESetup(){  //Use only in the setup loop  YEP
  ble_set_name ("TFLY");
  ble_begin ();
  Serial.begin (57600);
}

void startBLEScan(){//Currently empty  YEP
  while (ble_available()){
    if (Serial.available())
        Serial.println (F("do something"));
    }
    ble_do_events();
}

void clearParsingSetups(String stringToClear, char charArrayToClear[]){  //YEP
  for (int i=0; i<CHARS_TO_READ; i++){
    charArrayToClear[i] = 1;
  }
  stringToClear= "";
  ble_do_events();
}

void beaconSendData(){ //YEP
  int carrier;
  char sendCharArray[14];
  if (Serial.available()){
    delay(5);
    while (Serial.available()){
      carrier = Serial.read();
      ble_write ( carrier );  
    }
  }
  ble_do_events();
}

void beaconRequestInfo(){//currently empty
	Serial.println (F("Nothing Here"));
}

String BLE::readIncoming(){ //No good way to significantly shorten this one--consider revising
  int i=0;
  char stringBase[CHARS_TO_READ];
	for (int i=0; i<CHARS_TO_READ; i++){
    stringBase[i] = 1;
  }
  String finalString="";
  if (ble_available()){
    while (ble_available()){
      int carrier = ble_read();
      Serial.write (carrier);
      if (i<CHARS_TO_READ){
        stringBase [i] = carrier;
      }
      i++;
    }
    for (i=0;i<CHARS_TO_READ;i++){
      finalString = finalString + stringBase[i];
    }
    Serial.println("");
    Serial.println (finalString);
    return finalString;
  }
  ble_do_events();
}
