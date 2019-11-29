#define REMOTEXY_MODE__SOFTSERIAL
#include <SoftwareSerial.h>

#include <RemoteXY.h>
#include <NewPing.h>
 
#define TRIGGER_PIN  12  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN     11  // Arduino pin tied to echo pin on the ultrasonic sensor.
#define MAX_DISTANCE 400 // Maximum distance we want to ping for (in centimeters).
 
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); 
// NewPing setup of pins and maximum distance.

// RemoteXY connection settings 
#define REMOTEXY_SERIAL_RX 2
#define REMOTEXY_SERIAL_TX 3
#define REMOTEXY_SERIAL_SPEED 9600
// RemoteXY configurate  
#pragma pack(push, 1)
uint8_t RemoteXY_CONF[] =
  { 255,0,0,1,0,62,0,8,13,0,
  129,0,17,13,18,6,17,68,105,115,
  116,97,110,99,101,32,109,101,97,115,
  117,114,101,109,101,110,116,0,66,130,
  33,25,36,28,2,26,129,0,20,52,
  18,6,17,48,99,109,0,129,0,69,
  52,18,6,17,51,48,99,109,0 };
  
// this structure defines all the variables of your control interface 
struct {

    // output variable
  int8_t level_1; // =0..100 level position 

    // other variable
  uint8_t connect_flag;  // =1 if wire connected, else =0 

} RemoteXY;
#pragma pack(pop) 

/////////////////////////////////////////////
//           END RemoteXY include          //
///////////////////////////////////////////// 


void setup() {
  Serial.begin(9600);
  RemoteXY_Init ();  
  Serial.begin("RemoteXY started");
}
 
void loop() {
  RemoteXY_Handler (); 
  delay(100);                     // Wait 50ms between pings (about 20 pings/sec). 
  Serial.print("Ping: ");
  Serial.print(sonar.ping_cm()); // Send ping, get distance in cm and print result 
  Serial.println("cm");          //(0 = outside set distance range)
  RemoteXY.level_1 = sonar.ping_cm()*3.3333;
}
