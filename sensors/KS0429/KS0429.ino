#define TdsSensorPin A0             // Define the analog pin the sensor is connected to
#define VREF 5.0                    // The voltage pin
#define SCOUNT 30                   // Minimum sample count for averaging
int mBuffer[SCOUNT];                // Array to catch TDS Readings
int tempratureBuffer[SCOUNT];       // Array to store unmodified TDS Readings
int index_buffer_value = 0,                       // Counter for buffer value
    tbIdx = 0;                      // Counter for buffer temp
float averageVolts = 0,             // Average voltage
      tdsValue = 0,                 // Current TDS Reading
      temperature = 25;             // Current temperature

void setup()
{
  Serial.begin(115200);             // Set the data transmission port
  pinMode(TdsSensorPin,INPUT);      // Configure the pin receive INPUT
}
void loop()
{
  static unsigned long sample_timepoint = millis();                                     // Set to ms since the board started
  if(millis()-sample_timepoint > 40U) {                                                 // Get a reading every 40 ms
    sample_timepoint = millis();
    mBuffer[index_buffer_value] = analogRead(TdsSensorPin);                             // Take the reading
    index_buffer_value++;                                                               // Increment the value buffer
    if(index_buffer_value == SCOUNT)                                                    // If buffer index > the sample point
      index_buffer_value = 0;                                                           // Reset the the index
  }
  static unsigned long print_timepoint = millis();                                      // Set the print timepoint
  if(millis()-print_timepoint > 800U)
  {
    print_timepoint = millis();                                                         // Reset the timepoint
    for(tbIdx=0;tbIdx<SCOUNT;tbIdx++) {
      tempratureBuffer[tbIdx]= mBuffer[tbIdx];
    }
    averageVolts = getMedian(tempratureBuffer,SCOUNT) * (float)VREF/ 1024.0;         // read the analog value using median filtering algorithm then convert to voltage value
    float compensationCoefficient=1.0+0.02*(temperature-25.0);                          // temperature compensation formula: fFinalResult(25^C) = fFinalResult(current)/(1.0+0.02*(fTP-25.0));
    float compensationVolatge=averageVolts/compensationCoefficient;                     //voltage compensation
    tdsValue=(133.42*compensationVolatge*compensationVolatge*compensationVolatge - 255.86*compensationVolatge*compensationVolatge + 857.39*compensationVolatge)*0.5; //convert voltage value to tds value
    //Serial.print("voltage:");
    //Serial.print(averageVolts,2);
    //Serial.print("V ");
    Serial.print("TDS Value:");
    Serial.print(tdsValue,0);
    Serial.println("ppm");
  }
}
int getMedian(int mArray[], int iFilterLen)
{
  int mTab[iFilterLen];
  for (byte i = 0; i<iFilterLen; i++)
  mTab[i] = mArray[i];
  int i, j, bTemp;
  for (j = 0; j < iFilterLen - 1; j++)
  {
    for (i = 0; i < iFilterLen - j - 1; i++)
    {
      if (mTab[i] > mTab[i + 1])
      {
        bTemp = mTab[i];
        mTab[i] = mTab[i + 1];
        mTab[i + 1] = bTemp;
      }
    }
  }
  if ((iFilterLen & 1) > 0) {
    bTemp = mTab[(iFilterLen - 1) / 2];
  }  
  else{
    bTemp = (mTab[iFilterLen / 2] + mTab[iFilterLen / 2 - 1]) / 2;
  }
  return bTemp;
}