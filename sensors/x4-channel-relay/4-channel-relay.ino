#define RELAY01 0 //Connect RELAY01 to pin 0
#define RELAY02 1 //Connect RELAY02 to pin 1
#define RELAY03 2 //Connect RELAY03 to pin 2
#define RELAY04 3 //Connect RELAY04 to pin 3
#define RELAY05 4 //Connect RELAY05 to pin 4

void setup() {
  Serial.begin(9600);
   pinMode(RELAY01, OUTPUT);  // Configure pin 0 as OUTPUT
   pinMode(RELAY02, OUTPUT);  // Configure pin 1 as OUTPUT
   pinMode(RELAY03, OUTPUT);  // Configure pin 2 as OUTPUT
   pinMode(RELAY04, OUTPUT);  // Configure pin 3 as OUTPUT
   pinMode(RELAY05, OUTPUT);  // Configure pin 4 as OUTPUT

  digitalWrite(RELAY01,HIGH); // Turn Relay 01 OFF
  digitalWrite(RELAY02,HIGH); // Turn Relay 02 OFF
  digitalWrite(RELAY03,HIGH); // Turn Relay 03 OFF
  digitalWrite(RELAY04,HIGH); // Turn Relay 04 OFF
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(RELAY01,LOW);  // Turn Relay 01 ON
  delay(500);                 // Wait 500 ms
  digitalWrite(RELAY01,HIGH);  // Turn Relay 01 ON
  delay(1000);
  digitalWrite(RELAY02,LOW);  // Turn Relay 02 ON
  delay(500);                 // Wait 500 ms
  digitalWrite(RELAY02,HIGH);  // Turn Relay 02 ON
  delay(1000);
  digitalWrite(RELAY03,LOW);  // Turn Relay 03 ON
  delay(500);                 // Wait 500 ms
  digitalWrite(RELAY03,HIGH);  // Turn Relay 03 ON
  delay(1000);                 // Wait 1000 ms
  digitalWrite(RELAY04,LOW);  // Turn Relay 04 ON
  delay(500);                 // Wait 500 ms
  digitalWrite(RELAY04,HIGH);  // Turn Relay 04 ON
  delay(1000);                 // Wait 1000 ms
}
