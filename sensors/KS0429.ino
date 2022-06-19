#define sensor_pin A0             // Define the analog pin the sensor is connected to
#define voltage 5.0               // The voltage pin
#define sample_point 30           // Minimum sample count for averaging

int buffer_value[ sample_point ]; // Array to catch TDS Readings
int buffer_copy[ sample_point ];  // Array to store unmodified TDS Readings

int index_buffer_value = 0;       // Counter for buffer value
int index_buffer_copy = 0;        // Counter for buffer temp

float average_voltage = 0;        // Average voltage
float tds_reading = 0;            // Current TDS Reading
float temperature = 0;            // Current temperature

void setup() {
  Serial.begin( 115200 );         // Set the data transmission port
  pinMode( sensor_pin, INPUT );   // Configure the pin receive INPUT
}

void loop() {
  static unsigned long sample_timepoint = millis();                                            // Set to ms since the board started
  static unsigned long print_timepoint = millis();
  if(millis() - sample_timepoint > 40U) {                                                      // Get a reading every 40 ms
    buffer_value[ index_buffer_value ] = analogRead( sensor_pin );                             // Take the reading
    index_buffer_value++;                                                                      // Increment the value buffer
    if(  index_buffer_value > sample_point ) {                                                 // If buffer index > the sample point
      index_buffer_value = 0;                                                                  // Reset the the index
    }
    sample_timepoint = millis();                                                               // Reset the timepoint
  }
  if(millis() - print_timepoint > 800U) {                                                      // Prepare the output every 800 ms
    print_timepoint = millis();                                                                // Reset the timepoint
    for( index_buffer_copy = 0; index_buffer_copy < sample_point; index_buffer_copy++ ) {
      buffer_copy[ index_buffer_copy ] = buffer_value[ index_buffer_copy ];
      average_voltage = getMedian( buffer_copy, index_buffer_copy ) * (float)voltage/ 1024.0;  // read the analog value using median filtering algorithm then convert to voltage value
      float comp_coef = 1.0 + ( 0.02 * ( temperature - 25.0 ) );                               // temperature compensation formula: fFinalResult(25^C) = fFinalResult(current)/(1.0+0.02*(fTP-25.0));
      float comp_volt = average_voltage / comp_coef;                                           // voltage compensation
      tds_reading = ( ( 133.42 * ( comp_volt * comp_volt * comp_volt ) ) -                     // {
                      ( 255.86 * ( comp_volt * comp_volt ) ) +                                 //   convert voltage value to tds value
                      ( 857.39 * comp_volt )                                                   // }
                     ) * 0.5;
      Serial.println("TDS Value: " + String( tds_reading ) );
    }
  }
  
} // End Loop


// Functions
// getMedian - get the median of values contained in 'mArray'
int getMedian(int mArray[], int iFilterLen) {
  int mTab[iFilterLen];
  for (byte i = 0; i<iFilterLen; i++)
    mTab[i] = mArray[i];
    int i, j, mTemp;
    for (j = 0; j < iFilterLen - 1; j++)
    {
      for (i = 0; i < iFilterLen - j - 1; i++)
      {
        if (mTab[i] > mTab[i + 1])
        {
          mTemp = mTab[i];
          mTab[i] = mTab[i + 1];
          mTab[i + 1] = mTemp;
        }
      }
    }
    if ((iFilterLen & 1) > 0)
      mTemp = mTab[(iFilterLen - 1) / 2];
    else
      mTemp = (mTab[iFilterLen / 2] + mTab[iFilterLen / 2 - 1]) / 2;
    return mTemp;
  }
