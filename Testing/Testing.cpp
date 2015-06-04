#include "Testing.h"

void success (String testName){
	Serial.print (testName);
  Serial.println (F(" was a success"));
}

void fail ( String testName, int testType) {
	Serial.print (testName);
  Serial.print (F(" failed the ") );
  switch (testType){
	
		case 1:
		Serial.println (F("equality"));
		break;
		
		case 2:
		Serial.println (F("inequality"));
		break;
		
		case 3:
		Serial.println (F("empty variable"));
		break;
		
		case 4:
		Serial.println (F("boolean"));
		break;
		
		default:
		Serial.println (F("???"));
		break;
		Serial.println (F(" test. Review funciton."));
	};
}

const char* StringtoArray(String changeToCArray){
	const char * convertedOne;
	convertedOne = changeToCArray.c_str();
	return convertedOne;
}

void TestEqual (String testName, String one, String two){
	const char* convertedOne = StringtoArray (one);
	const char* convertedTwo = StringtoArray (two);
	if (convertedOne == convertedTwo)
    success (testName);
  else
    fail (testName,1);
}

void TestEqual (String testName, const char* one, const char* two){
	
  if (one == two) 
    success (testName);
  else
    fail (testName,1);
}

void TestEqual (String testName, String one, const char* two){
	const char * converted;
	converted = StringtoArray (one);
	if (converted == two) 
    success (testName);
  else
    fail (testName,1);
}

void TestEqual (String testName, const char* one, String two){
	const char * converted;
	converted = StringtoArray (two);
	if (one == converted) 
    success (testName);
  else
    fail (testName,1);
}

void TestEqual (String testName, int one, int two){
  if (one == two) 
    success (testName);
  else
    fail (testName,1);
}

void TestEqual (String testName, char one, char two){
  if (one == two) 
    success (testName);
  else
    fail (testName,1);
}

void TestEqual (String testName, byte one, byte two){
  if (one == two) 
    success (testName);
  else
    fail (testName,1);
}

void TestEqual (String testName, bool one, bool two){
	if (one == two) 
    success (testName);
  else
    fail (testName,1);
}

void TestNotEqual (String testName, String one, String two){
  const char* convertedOne = StringtoArray (one);
	const char* convertedTwo = StringtoArray (two);
  if (convertedOne != convertedTwo) 
    success (testName);
  else
    fail (testName,2);
}

void TestNotEqual (String testName, const char* one, const char* two){
  if (one != two) 
    success (testName);
  else
		fail (testName,2);	
}

void TestNotEqual (String testName, int one, int two){
  if (one != two) 
    success (testName);
  else
		fail (testName,2);
}

void TestNotEqual (String testName, char one, char two){
  if (one != two) 
    success (testName);
  else
    fail (testName,2);
}

void TestNotEqual (String testName, byte one, byte two){
  if (one != two) 
    success (testName);
  else
    fail (testName,2);
}

void TestEmpty (String testName, int arg){
	if (arg == 0) 
    success (testName);
  else
    fail (testName,3);
}

void TestEmpty (String testName, const char * arg){
	if (arg == 0) 
    success (testName);
  else
    fail (testName,3);
}

void TestEmpty (String testName, String arg){
	if (arg == "") 
    success (testName);
  else
    fail (testName,3);
}

void TestEmpty (String testName, char arg){
	if (arg == 0) 
    success (testName);
  else
    fail (testName,3);
}

void TestEmpty (String testName, byte arg){
	if (arg == 0) 
    success (testName);
  else
    fail (testName,3);
}

void TestTrue (String testName, bool arg){
	if (arg)
		success (testName);
  else
    fail (testName,4);
}


