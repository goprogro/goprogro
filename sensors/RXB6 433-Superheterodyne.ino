#include <RCSwitch.h>

RCSwitch rSwitch = RCSwitch();

void setup() {

  Serial.begin(9600);
  
  // Transmitter is connected to Arduino Pin #10  
  rSwitch.enableTransmit(10);
  
  // Optional set protocol (default is 1, will work for most outlets)
  // rSwitch.setProtocol(2);

  // Optional set pulse length.
  rSwitch.setPulseLength(190);
  
  // Optional set number of transmission repetitions.
  // rSwitch.setRepeatTransmit(15);
  
}

void loop() {

  /* Same switch as above, but using decimal code */
  rSwitch.send(3570092, 24);
  Serial.println( "Send ON decimal");
  delay(1000);  
  rSwitch.send(3570084, 24);
  Serial.println( "Send OFF decimal");
  delay(1000);  

  /* Same switch as above, but using binary code */
  rSwitch.send("001101100111100110101100");
  Serial.println( "Send ON binary");
  delay(1000);  
  rSwitch.send("001101100111100110100100");
  Serial.println( "Send OFF binary");
  delay(1000);


  delay(10000);
}
