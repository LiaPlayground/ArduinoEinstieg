//////////////////////////////////////////////
//        RemoteXY include library          //
//////////////////////////////////////////////

// RemoteXY select connection mode and include library 
#define REMOTEXY_MODE__SOFTSERIAL
#include <SoftwareSerial.h>

#include <RemoteXY.h>

// RemoteXY connection settings 
#define REMOTEXY_SERIAL_RX 2
#define REMOTEXY_SERIAL_TX 3
#define REMOTEXY_SERIAL_SPEED 9600


// RemoteXY configurate  
#pragma pack(push, 1)
uint8_t RemoteXY_CONF[] =
  { 255,12,0,2,0,66,0,8,13,0,
  2,0,45,30,22,11,2,26,31,31,
  79,78,0,79,70,70,0,7,36,45,
  18,48,9,2,26,2,11,129,0,14,
  19,26,6,17,80,97,115,115,119,111,
  114,116,0,129,0,14,33,18,6,17,
  76,101,100,32,97,110,0,65,6,84,
  31,9,9 };
  
// this structure defines all the variables of your control interface 
struct {

    // input variable
  uint8_t switch_1; // =1 if switch ON and =0 if OFF 
  char edit_1[11];  // string UTF8 end zero  

    // output variable
  uint8_t led_1_r; // =0..255 LED Red brightness 
  uint8_t led_1_g; // =0..255 LED Green brightness 

    // other variable
  uint8_t connect_flag;  // =1 if wire connected, else =0 

} RemoteXY;
#pragma pack(pop)

/////////////////////////////////////////////
//           END RemoteXY include          //
///////////////////////////////////////////// 

#define PIN_SWITCH_1 13

String inputString = "";
String password = "Geheim";

void setup() 
{
  RemoteXY_Init (); 
  pinMode (PIN_SWITCH_1, OUTPUT);
  // TODO you setup code
} 

void loop() 
{ 
  RemoteXY_Handler ();
  inputString = RemoteXY.edit_1;
  if (inputString == password){
     digitalWrite(PIN_SWITCH_1, (RemoteXY.switch_1==0)?LOW:HIGH);
     RemoteXY.led_1_r = 0;
     RemoteXY.led_1_g = 255;
  }else{
     RemoteXY.led_1_r = 255;
     RemoteXY.led_1_g = 0;
  }
  // TODO you loop code
  // use the RemoteXY structure for data transfer
}
