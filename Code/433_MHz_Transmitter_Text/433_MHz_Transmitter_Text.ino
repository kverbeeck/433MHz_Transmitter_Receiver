/*
   433MHz Transmitter Code
*/

#include <RH_ASK.h>
#include <SPI.h> // Not actually used but needed to compile

RH_ASK driver; // create a RH_ASK object called driver.

void setup()
{
  Serial.begin(115200);    // Debugging only
  // Initialize the RH_ASK object by using the init() method.
  if (!driver.init()) {
    Serial.println("433MHz Transmitter init failed");
  }
  Serial.println("433MHz Transmitter init success");
}

void loop() {
  // We write and send our message.
  // The message is saved on the msg variable.
  // Please note that the message needs to be of type char.
  const char *msg = "Hello World!";
  // This message contains the “Hello World!” message,
  // but you can send anything you want as long as it is
  // in char format.
  // Finally, we send our message as follows:
  driver.send((uint8_t *)msg, strlen(msg));
  driver.waitPacketSent();
  // The message is being sent every second,
  // but you can adjust this delay time.
  delay(1000);
}
