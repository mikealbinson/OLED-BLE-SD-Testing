#ifndef _TESTING_H
#define _TESTING_H

#include "Arduino.h"

void success(String testName);
void fail(String testName, int testType);
const char* StringtoArray(String changeToCArray);

void TestEqual (String testName, String one, String two);
void TestEqual (String testName, const char* one, const char* two);
void TestEqual (String testName, String one, const char* two);
void TestEqual (String testName, int one, int two);
void TestEqual (String testName, char one, char two);
void TestEqual (String testName, byte one, byte two);
void TestEqual (String testName, bool one, bool two);

void TestNotEqual (String testName, String one, String two);
void TestNotEqual (String testName, const char* one, const char* two);
void TestNotEqual (String testName, int one, int two);
void TestNotEqual (String testName, char one, char two);
void TestNotEqual (String testName, byte one, byte two);

void TestEmpty (String testName, int arg);
void TestEmpty (String testName, const char* arg);
void TestEmpty (String testName, String arg);
void TestEmpty (String testName, char arg);
void TestEmpty (String testName, byte arg);

#endif
