#include <RCSwitch.h>

RCSwitch rSwitch = RCSwitch();

void setup() {

  Serial.begin(9600);
  
  // Transmitter is connected to Arduino Pin #10  
  rSwitch.enableTransmit(10);
  
  // Set protocol (default is 1, will work for most outlets)
  // rSwitch.setProtocol(2);

  // Set pulse length.
  // rSwitch.setPulseLength(320);
  
  // Set number of transmission repetitions.
  // rSwitch.setRepeatTransmit(15);
  
}

void loop() {
  // Replace binary code from WL101 to turn ON
  rSwitch.send("000000000001010100010001");
  Serial.println( "Switch On");
  delay(1000); 
  // Replace binary code from WL101 to turn OFF
  rSwitch.send("000000000001010100010100");
  Serial.println( "Switch OFF");
  delay(1000); 
  delay(5000);
}
