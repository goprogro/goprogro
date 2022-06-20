#define RELAY01 0 //Connect RELAY01 to pin 0
#define RELAY02 1 //Connect RELAY02 to pin 1
#define RELAY03 2 //Connect RELAY03 to pin 2
#define RELAY04 3 //Connect RELAY04 to pin 3
#define RELAY05 4 //Connect RELAY05 to pin 4
#define RELAY06 5 //Connect RELAY06 to pin 5
#define RELAY07 6 //Connect RELAY07 to pin 6
#define RELAY08 7 //Connect RELAY08 to pin 7

void setup() {
   pinMode(RELAY01, OUTPUT);  	// Configure pin 0 as OUTPUT
   pinMode(RELAY02, OUTPUT);  	// Configure pin 1 as OUTPUT
   pinMode(RELAY03, OUTPUT);  	// Configure pin 2 as OUTPUT
   pinMode(RELAY04, OUTPUT);  	// Configure pin 3 as OUTPUT
   pinMode(RELAY05, OUTPUT);  	// Configure pin 4 as OUTPUT
   pinMode(RELAY05, OUTPUT);  	// Configure pin 5 as OUTPUT
   pinMode(RELAY06, OUTPUT);  	// Configure pin 6 as OUTPUT
   pinMode(RELAY07, OUTPUT);  	// Configure pin 7 as OUTPUT
   pinMode(RELAY08, OUTPUT);  	// Configure pin 8 as OUTPUT
	
  digitalWrite(RELAY01,HIGH); 	// Turn Relay 01 OFF
  digitalWrite(RELAY02,HIGH); 	// Turn Relay 02 OFF
  digitalWrite(RELAY03,HIGH); 	// Turn Relay 03 OFF
  digitalWrite(RELAY04,HIGH); 	// Turn Relay 04 OFF
  digitalWrite(RELAY05,HIGH); 	// Turn Relay 05 OFF
  digitalWrite(RELAY06,HIGH); 	// Turn Relay 06 OFF
  digitalWrite(RELAY07,HIGH); 	// Turn Relay 07 OFF
  digitalWrite(RELAY08,HIGH); 	// Turn Relay 08 OFF
}

void loop() {

  digitalWrite(RELAY01,LOW);  	// Turn Relay 01 ON
  delay(500);                 	// Wait 500 ms
  digitalWrite(RELAY01,HIGH);  	// Turn Relay 01 ON
  delay(1000);
  digitalWrite(RELAY02,LOW);  	// Turn Relay 02 ON
  delay(500);                 	// Wait 500 ms
  digitalWrite(RELAY02,HIGH);  	// Turn Relay 02 ON
  delay(1000);
  digitalWrite(RELAY03,LOW);  	// Turn Relay 03 ON
  delay(500);                 	// Wait 500 ms
  digitalWrite(RELAY03,HIGH);  	// Turn Relay 03 ON
  delay(1000);                 	// Wait 1000 ms
  digitalWrite(RELAY04,LOW);  	// Turn Relay 04 ON
  delay(500);                 	// Wait 500 ms
  digitalWrite(RELAY04,HIGH);  	// Turn Relay 04 ON
  delay(1000);                 	// Wait 1000 ms
  digitalWrite(RELAY05,LOW);  	// Turn Relay 05 ON
  delay(500);                 	// Wait 500 ms
  digitalWrite(RELAY05,HIGH);  	// Turn Relay 05 ON
  delay(1000);                 	// Wait 1000 ms
  digitalWrite(RELAY06,LOW);  	// Turn Relay 06 ON
  delay(500);                 	// Wait 500 ms
  digitalWrite(RELAY06,HIGH);  	// Turn Relay 06 ON
  delay(1000);                 	// Wait 1000 ms
  digitalWrite(RELAY07,LOW);  	// Turn Relay 07 ON
  delay(500);                 	// Wait 500 ms
  digitalWrite(RELAY07,HIGH);  	// Turn Relay 07 ON
  delay(1000);                 	// Wait 1000 ms
  digitalWrite(RELAY08,LOW);  	// Turn Relay 08 ON
  delay(500);                 	// Wait 500 ms
  digitalWrite(RELAY08,HIGH);  	// Turn Relay 08 ON
  delay(1000);                 	// Wait 1000 ms
}
