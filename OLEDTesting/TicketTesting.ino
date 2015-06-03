// NOTE: This code uses a third party library: u8glib
// https://bintray.com/olikraus/u8glib/Arduino

#include <U8gLibClone.h>
#include <Testing.h>a
#include "OLEDResponses.h"

OLED *oled; //Unfortunately, this had to be redone as a pointer, but hey, it works so i won't complain
OLED *MockOLED;

void setup(void) {
  Serial.begin (9600);
  oled = new OLED();
  MockOLED = new OLED (true);
  oled->drawSetup();
}

void loop(void) {
  
  int x = random (0,5);
  String in;
  const char* out;
  switch (x){
    case 1:
      in = "VIP";
      out = oled->drawGeneral(in);
      Serial.println (out);
      TestEqual ("VIP test", in, out);
      break;
  
    case 2:
      in = "Normal ADMT";
      out = oled->drawGeneral(in);
      Serial.println (out);
      TestEqual ("Normal test", in, out);
      break;
  
    case 3:
      in = "VOID";
      out =oled->drawGeneral(in);
      Serial.println (out);
      TestEqual ("VOID test", in, out);
      break;
    
    case 4:
      in = "Unknown-CHECK";
      out =oled-> drawGeneral(in);
      Serial.println (out);
      TestEqual ("Unknown test", in, out);
      break;
      
    default:
      in = "NO TICKET";
      out = oled->drawGeneral(in);
      Serial.println (out);
      TestEqual ("No ticket test", in, out);
      break;
  }
  // rebuild the picture after some delay
  delay(500);
  Serial.println (x);
  oled->drawGeneral("Tfly");
  
}
