#include <RCSwitch.h>

RCSwitch rSwitch = RCSwitch();

void setup() {

  Serial.begin(9600);
  
  // Transmitter is connected to Arduino Pin #10  
  rSwitch.enableTransmit(10);
  
  // Set protocol (default is 1, will work for most outlets)
  // rSwitch.setProtocol(2);

  // Set pulse length.
  rSwitch.setPulseLength(188);
  
  // Set number of transmission repetitions.
  rSwitch.setRepeatTransmit(15);
  
}

void loop() {

  rSwitch.send(3570090, 24);
  Serial.println( "Switch On");
  delay(1000);  
  rSwitch.send(3570082, 24);
  Serial.println( "Switch OFF");
  delay(1000);  
  
  // rSwitch.send("001101100111100110101010");
  // Serial.println( "Switch On");
  // delay(1000);  
  // rSwitch.send("001101100111100110100010");
  // Serial.println( "Switch OFF");
  // delay(1000); 



  delay(5000);
}
