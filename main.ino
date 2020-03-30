
#include "src/build_defines.h"
#include "src/Modules/ScannerModule/include/RFIDRC522.h"
#include "src/Modules/SoundModule/include/DFPlayerMini.h"
//#include "src/Modules/SoundModule/Include/SoundDummy.h"
#include "src/Modules/CommunicationModule/Include/BluetoothFeather.h"
#include "src/Protocol/Include/Data.h"
#include "src/FunMRI/Include/FunMRI.h"
#include "src/FunMRIFactory/Include/SmartphoneFactory.h"
#include "src/FunMRIFactory/Include/SerialPrintTestFactory.h"
#include "src/FunMRIController/Include/SmartphoneMode.h"
#include "src/FunMRIController/Include/WithoutSmartphoneMode.h"

/**
 * @brief Defines for Bluefruit Feather nRF52832
 * 
 */
#define SOMO_TX 7   // Using Serial pin instead (pin 6)
#define SOMO_RX 11   // Using Serial pin instead (pin 8)
#define SOMO_BAUDRATE 9600
#define LED_PIN LED_BUILTIN
#define RFID_SS_PIN 5
#define RFID_RST_PIN 4
//#define INT_MODE_PIN 7
//#define INT_MICROSWITCH_PIN 25
const uint8_t INT_MICROSWITCH_PIN = 7;

IData* data = nullptr;

FunMRI* myFunMRI = nullptr;
IFunMRIFactory* factoryPtr = nullptr;
IFunMRIController* controllerPtr = nullptr;

unsigned char IDTag[SIZE_OF_DATA_ARRAY - 1] = {0, 0, 0, 0, 0, 0, 0};
unsigned char newIDTag[SIZE_OF_DATA_ARRAY - 1] = {0, 0, 0, 0, 0, 0, 0};

enum MODE{
  SMARTPHONE        = 0,
  WITHOUTSMARTPHONE = 1,
};

volatile bool currentMode = true;
volatile bool microswitchState = LOW;
volatile bool newInterrupt = false;

// void ISR_MODE()
// {
//   //newInterrupt = true;

//   Serial.print("ISR_MODE entered.");

//   //Serial.print(newInterrupt);

//   // if(digitalRead(INT_MODE_PIN))
//   // {
//   //   currentMode = true; // WITHOUTSMARTPHONE
//   // }
//   // else
//   // {
//   //   currentMode = false; // SMARTPHONE
//   // }
// }

void ISR_MICROSWITCH()
{
  newInterrupt = true;
  // controllerPtr->setMicroSwitchChanged(true);
  // int state = digitalRead(INT_MICROSWITCH_PIN);
  // controllerPtr->setMicroSwitchState(state);

  Serial.print("ISR_MICROSWITCH entered.");

  // if(digitalRead(INT_MICROSWITCH_PIN))
  // {
  //   microswitchState = 1;
  // }
  // else
  // {
  //   microswitchState = 0;
  // }
}

void setup()
{
  Serial.begin(9600);
  pinMode(LED_PIN, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);

  //I N T E R U P T S
  //pinMode(INT_MODE_PIN, INPUT);
  //attachInterrupt(digitalPinToInterrupt(INT_MODE_PIN), ISR_MODE, CHANGE);
  pinMode(INT_MICROSWITCH_PIN, INPUT);
  attachInterrupt(INT_MICROSWITCH_PIN, ISR_MICROSWITCH, CHANGE);

  // O B J E C T   I N I T I A L I Z A T I O N
  controllerPtr = new SmartphoneMode();

  // For debugging:
  digitalWrite(LED_BUILTIN, HIGH);
  Serial.println("Setup done...");
}

void loop()
{ 
  if(newInterrupt)
  {
    Serial.println("New Interrupt!");
    newInterrupt = false;
    //Serial.print("Mode is now: "); Serial.println(currentMode);
    //Serial.print("microswitchState is now: "); Serial.println(microswitchState);
  }

  // controllerPtr->run();
}
