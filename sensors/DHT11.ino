#include "DHT.h"			    // Include sensor library 'DHT sensor library By Adafruit'
#define DHTPIN 2			    // Define the digital pin the sensor is connected to
#define DHTTYPE DHT11		  // Define sensor type

DHT dht(DHTPIN, DHTTYPE);	// Define the sensor

void setup() {
  Serial.begin(9600);		  // Set the data transmission port
  dht.begin();				    // Start the sensor
}

void loop() {
  float h = dht.readHumidity(); 					        //Get the humidity
  float t = dht.readTemperature(); 					      // Read temprature in degrees C
  float f = dht.readTemperature(true);				    // Read temprature in degrees F ( the 'true' )
  if (isnan(h) || isnan(t) || isnan(f)) {			    // Make sure that the data from the sensor is valid
    Serial.println( "Sensor Error" );				      // return sensor error if sensor is not returning valid data
    return;
  }
  float hif = dht.computeHeatIndex(f, h);			    // Set the heat index in degrees C
  float hic = dht.computeHeatIndex(t, h, false);	// Set the heat index in degrees F
  Serial.println( " Humidity: " + String( h ) );
  Serial.println( " Temperature (C): " + String( t ) );
  Serial.println( " Temperature (F): " + String( f ) );
  Serial.println( " Heat index (C): " + String( hic ) );
  Serial.println( " Heat index (F): " + String( hif ) );
  delay(5000);
}
