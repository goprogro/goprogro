#define PUMP01 0 //Connect PUMP01 to pin 0

void setup() {
  Serial.begin(9600);
  pinMode(PUMP01, OUTPUT);  // Configure pin 0 as OUTPUT

  digitalWrite(PUMP01,HIGH); // Turn PumpOFF
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(PUMP01,LOW);  // Turn Pump ON
  Serial.println( "Pump ON");
  delay(1000);                 // Wait 1000 ms
  digitalWrite(PUMP01,HIGH);  // Turn Pump OFF
  Serial.println( "Pump OFF");
  delay(2500);                 // Wait 2500 ms
}
