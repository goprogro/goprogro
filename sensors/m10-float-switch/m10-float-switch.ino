#define FLOAT_SENSOR  2     // the number of the pushbutton pin

void setup() 
{
  Serial.begin(9600);
  pinMode( FLOAT_SENSOR, INPUT_PULLUP );
  digitalWrite( FLOAT_SENSOR, HIGH );
}

void loop() 
{
  if(digitalRead(FLOAT_SENSOR) == LOW) 
  {
    Serial.println( "Sensor LOW (ON)" );
  } 
  else 
  {
    Serial.println( "Sensor HIGH (OFF)" );
  }
  delay( 500 );
}
