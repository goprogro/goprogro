#define RELAY01 0 //Connect RELAY01 to pin 0

void setup() {
  Serial.begin(9600);
   pinMode(RELAY01, OUTPUT);  // Configure pin 0 as OUTPUT

  digitalWrite(RELAY01,HIGH); // Turn Relay 01 OFF
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(RELAY01,LOW);  // Turn Relay 01 ON
  delay(500);                 // Wait 500 ms
  digitalWrite(RELAY01,HIGH);  // Turn Relay 01 ON
}
