#include "Testing.h"

void success (String testName){
	Serial.print (testName);
  Serial.println (F(" was a success"));
}

void fail ( String testName) {
	Serial.print (testName);
  Serial.println (F(" failed. Review funciton."));
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
    fail (testName);
}

void TestEqual (String testName, const char* one, const char* two){
	
  if (one == two) 
    success (testName);
  else
    fail (testName);
}

void TestEqual (String testName, String one, const char* two){
	const char * converted;
	converted = StringtoArray (one);
	if (converted == two) 
    success (testName);
  else
    fail (testName);
}

void TestEqual (String testName, const char* one, String two){
	const char * converted;
	converted = StringtoArray (two);
	if (one == converted) 
    success (testName);
  else
    fail (testName);
}

void TestEqual (String testName, int one, int two){
  if (one == two) 
    success (testName);
  else
    fail (testName);
}

void TestEqual (String testName, char one, char two){
  if (one == two) 
    success (testName);
  else
    fail (testName);
}

void TestEqual (String testName, byte one, byte two){
  if (one == two) 
    success (testName);
  else
    fail (testName);
}

void TestNotEqual (String testName, String one, String two){
  const char* convertedOne = StringtoArray (one);
	const char* convertedTwo = StringtoArray (two);
  if (convertedOne != convertedTwo) 
    success (testName);
  else
    fail (testName);
}

void TestNotEqual (String testName, const char* one, const char* two){
  if (one != two) 
    success (testName);
  else
    fail (testName);
}

void TestNotEqual (String testName, int one, int two){
  if (one != two) 
    success (testName);
  else
    fail (testName);
}

void TestNotEqual (String testName, char one, char two){
  if (one != two) 
    success (testName);
  else
    fail (testName);
}

void TestNotEqual (String testName, byte one, byte two){
  if (one != two) 
    success (testName);
  else
    fail (testName);
}
