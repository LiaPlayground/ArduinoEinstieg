#include <WiFi101.h>
#include "secrets.h"
#include "ThingSpeak.h"
#include "DHT.h"
#include "Zanshin_BME680.h"
 
char ssid[] = SECRET_SSID;   // your network SSID (name) 
char pass[] = SECRET_PASS;   // your network password

int status = WL_IDLE_STATUS;

// Initialize the Wifi client library
WiFiClient client;

// ThingSpeak Settings
unsigned long myChannelNumber = SECRET_CH_ID;
const char * myWriteAPIKey = SECRET_WRITE_APIKEY;
long count = 0;

#define DHTTYPE DHT22 
const int pinDHT22 = A0;
DHT dht22(pinDHT22, DHTTYPE);

BME680_Class BME680;

void setup() {
  Serial.begin(9600);
  //while (!Serial) {
  //  ; // wait for serial port to connect. Needed for native USB port only
  //}
  Serial.println("Freiberg Coding Event - Data logger");
  // attempt to connect to Wifi network

  if (WiFi.status() == WL_NO_SHIELD) {
    Serial.println("Communication with WiFi module failed!");
    // don't continue
    while (true);
  }

  Serial.print(F("- Starting Thing Speak client\n"));
  ThingSpeak.begin(client);  //Initialize ThingSpeak

  Serial.print(F("- Initializing BME680 sensor\n"));
  while (!BME680.begin(I2C_STANDARD_MODE)) // Start BME680 using I2C protocol
  {
    Serial.println(F("-  Unable to find BME680. Waiting 3 seconds."));
    delay(3000);
  } // of loop until device is located
  BME680.setOversampling(TemperatureSensor,Oversample16); // Use enumerated type values
  BME680.setOversampling(HumiditySensor,   Oversample16);
  BME680.setOversampling(PressureSensor,   Oversample16);
  BME680.setIIRFilter(IIR4);
  BME680.setGas(320,150); 

  Serial.print(F("- Initializing DHT22 sensor\n"));
  dht22.begin();
  
  Serial.print(F("Initializing finished\n"));
}

void loop() {
  // Connect or reconnect to WiFi
  Serial.println("");
  Serial.print("Attempting to connect to SSID ... ");
  while(WiFi.status() != WL_CONNECTED){
      WiFi.begin(ssid, pass); // Connect to WPA/WPA2 network. Change this line if using open or WEP network
       delay(5000);     
  } 
  Serial.println("\nConnected.");

  float temperatureDHT = dht22.readTemperature();
  float humidityDHT = dht22.readHumidity();

  static int32_t temperature680, humidity680, pressure, gas; 
  BME680.getSensorData(temperature680, humidity680, pressure,gas);

  int light = analogRead(A5);

  Serial.print( "T_DHT = " );
  Serial.print( temperatureDHT, 1 );
  Serial.print( " T_680 = " );
  Serial.print(temperature680/100.0,2); 
  Serial.print( " HUM_DHT = " );
  Serial.print( humidityDHT, 1 );
  Serial.print( "% HUM_680 = " );
  Serial.print(humidity680/1000.0,2);
  Serial.print( " Pressure = " );
  Serial.print(pressure/100.0,2);  
  Serial.print( " Gas = ");                       
  Serial.print(gas/100.0,2);
  Serial.print(F("mOhm"));
  Serial.print( " Light = ");                       
  Serial.println(light);
 
  // set the fields with the values
  ThingSpeak.setField(1, (float) temperatureDHT);
  ThingSpeak.setField(2, (float) humidityDHT);
  ThingSpeak.setField(3, (float)(temperature680/100.0));
  ThingSpeak.setField(4, (float)(humidity680/1000.0));
  ThingSpeak.setField(5, (float)(pressure/100.0));
  ThingSpeak.setField(6, (float)(gas/100.0));
  ThingSpeak.setField(7, (int)   light);
  ThingSpeak.setStatus("ok");
  
  // write to the ThingSpeak channel
  int x = ThingSpeak.writeFields(myChannelNumber, myWriteAPIKey);
  if(x == 200){
    Serial.println("Channel update successful.");
  }
  else{
    Serial.println("Problem updating channel. HTTP error code " + String(x));
  }
  delay(60000); // Wait 60 seconds to update the channel again
  WiFi.end();
}
