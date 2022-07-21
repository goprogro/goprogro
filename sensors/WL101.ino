#include <RCSwitch.h>           // Include the RCSwitch Library

RCSwitch rSwitch = RCSwitch(); // Createt the RCSwitch Object

void setup() {
  Serial.begin(9600);
  // Receiver on interrupt 0 => that is pin #2
  rSwitch.enableReceive(10);   
}

void loop() {
  // If the a signal is received,
  if (rSwitch.available()) {
    // capture the output and print it to serial using the output 
    output(rSwitch.getReceivedValue(), rSwitch.getReceivedBitlength(), rSwitch.getReceivedDelay(), rSwitch.getReceivedRawdata(),rSwitch.getReceivedProtocol());
    rSwitch.resetAvailable();
  }
}
