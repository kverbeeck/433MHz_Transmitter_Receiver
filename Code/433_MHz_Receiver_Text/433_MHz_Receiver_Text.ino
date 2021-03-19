/*
   433MHz Receiver Code
*/

#include <RH_ASK.h>
#include <SPI.h> // Not actualy used but needed to compile

RH_ASK driver; // create a RH_ASK object called driver.

void setup() {
  Serial.begin(115200);  // Debugging only
  // Initialize the RH_ASK object by using the init() method.
  if (!driver.init()) {
    Serial.println("433MHz Receiver init failed");
  }
  Serial.println("433MHz Receiver init success");
}

void loop() {
  // If you would change this value to 5, then you would only
  // receive "Hello".
  // If you would change this value to 16, then you would
  // receive something like "Hello World!***8".
  uint8_t buf[12];
  uint8_t buflen = sizeof(buf);
  if (driver.recv(buf, &buflen)) { // Non-blocking
    int i;
    // Message with a good checksum received, dump it.
    Serial.print("Message: ");
    Serial.println((char*)buf);
  }
}
