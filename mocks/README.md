#Mocks

A slightly more succinct version of the three mock object libraries combined

Includes Mocktesting.ino, which demonstrates the output of the tests included in the files

There are still some bugs in the string passing--that'll be fixed soon

Also hoping include a "send" method for RBL that will report an iBeacon signal being sent even though we can't do that with the current hardware

#NOTE: to use you will need to download and include:

 U8gLibClone.h
 
 Testing.h
 
 SPI.h //included in the default arduino libs, no need to download
 
 boards.h
 
 RBL_LibCLONE.h

to use the example
