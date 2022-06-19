#define sensor_pin A0                                   // Define the analog pin the sensor is connected to
#define sample_point 10                                 // Minimum sample count for averaging

//float b;
int value_sum;                                          // A variable to hold total readings
int analogBuffer[ SCOUNT ];                             // Array to catch PH Readings
int temp;                                               // Temprature value

void setup() {
  Serial.begin(9600);                                   // Set the data transmission port
  pinMode(13,OUTPUT);                                   // Set local pin
}

void loop() {
  for( int i = 0; i < sample_point; i++ ) {                       // loop through and get sample_point number of readings
    analogBuffer[ i ] = analogRead( sensor_pin );                 // add reading to array
    delay(10);                                                    // wait 10 ms
  }
  for( int i = 0; i < ( sample_point - 1 ); i++ ) {               // loop through the first 9 sampls
    for( int x = ( i + 1 ); x < sample_point; x++ ) {             // loop through the last 9 samples
      if( analogBuffer[ i ] > analogBuffer[ x ] ) {               // if the current value is greater than the next value (temp value drop)
        temp = analogBuffer[ i ];                                 // the set the temp value equal to the current value 
        analogBuffer[ i ] = analogBuffer[ x ];                    // set the current value equal to the next value
        analogBuffer[ x ] = temp;                                 // set the next value equal to the temp value ( previously the current value)
      }
    }
  }
  value_sum = 0;                                                  // reset the value_sum
  for( int i = 2; i < 8; i++ ) {                                  // loop through the middle 8 values in the array
    value_sum += analogBuffer[ i ];                               // add the values to the sum
  }
  float ph_value = ( ( ( float )value_sum * 5.0 ) / 1024 ) / 6 ;  // Calculate the PH
  ph_value = 3.5 * ph_value;                                      // Calculate the PH
  Serial.println( "PH : " + String( ph_value ) ) ;                // Print the output
  delay(800);                                                     // wait 800 ms and restart the loop
}
