// RemoteXY select connection mode and include library 
#define REMOTEXY_MODE__SOFTSERIAL
#include <SoftwareSerial.h>

#include <NewPing.h>

#include <RemoteXY.h>

// RemoteXY connection settings 
#define REMOTEXY_SERIAL_RX A8
#define REMOTEXY_SERIAL_TX A9
#define REMOTEXY_SERIAL_SPEED 9600


// RemoteXY configurate  
#pragma pack(push, 1)
uint8_t RemoteXY_CONF[] =
  { 255,0,0,12,0,52,0,8,13,0,
  66,1,17,6,6,47,2,26,129,0,
  33,7,47,6,17,68,105,115,116,97,
  110,122,109,101,115,115,117,110,103,0,
  129,0,6,47,9,6,17,99,109,0,
  67,6,34,48,20,5,2,26,11 };
  
// this structure defines all the variables of your control interface 
struct {

    // output variable
  int8_t distance_bar;     // =0..100 level position 
  char distance_text[11];  // string UTF8 end zero 

    // other variable
  uint8_t connect_flag;  // =1 if wire connected, else =0 

} RemoteXY;
#pragma pack(pop)

/////////////////////////////////////////////
//           END RemoteXY include          //
/////////////////////////////////////////////

#define TRIGGER_PIN  16  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN     15  // Arduino pin tied to echo pin on the ultrasonic sensor.
#define MAX_DISTANCE 30  // Maximum distance we want to ping for (in centimeters).

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);
// NewPing setup of pins and maximum distance.


void setup() 
{
  RemoteXY_Init (); 
  
  
  // TODO you setup code
  
}

void loop() 
{ 
  RemoteXY_Handler ();
  sprintf(RemoteXY.distance_text, "%d", sonar.ping_cm());
  
  // TODO you loop code
  // use the RemoteXY structure for data transfer


}
