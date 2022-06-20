#define FLOAT_SWITCH  2     				// Define the digital pin the switch is connected to

void setup() 
{
  Serial.begin(9600);						// Set the data transmission port
  pinMode( FLOAT_SWITCH, INPUT_PULLUP );	// Set local pin
  digitalWrite( FLOAT_SWITCH, HIGH );		// Enable internal 22k pullup
}

void loop() 
{
  if(digitalRead(FLOAT_SWITCH) == LOW) 		// If the switch is LOW(ON), 
  {
    Serial.println( "Switch ON" );			// Do something
  } 
  else 										// Else
  {
    Serial.println( "Switch OFF" );			// Do something else
  }
  delay( 500 );								// Wait 500ms to restart loop
}