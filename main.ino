
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
#include "src/defines.h"

//IData* data = nullptr;
// FunMRI* myFunMRI = nullptr;
// IFunMRIFactory* factoryPtr = nullptr;
IFunMRIController* controllerPtr = nullptr;

//unsigned char IDTag[SIZE_OF_DATA_ARRAY - 1] = {0, 0, 0, 0, 0, 0, 0};
//unsigned char newIDTag[SIZE_OF_DATA_ARRAY - 1] = {0, 0, 0, 0, 0, 0, 0};

enum MODE{
  SMARTPHONE        = 0,
  WITHOUTSMARTPHONE = 1,
};

unsigned char currentMode = WITHOUTSMARTPHONE;

void setup()
{
  Serial.begin(9600);
  pinMode(LED_PIN, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);

  // O B J E C T   I N I T I A L I Z A T I O N
  controllerPtr = new WithoutSmartphoneMode();
  
  // For debugging:
  Serial.println("Setup done...");
}

void loop()
{ 
  controllerPtr->run();

  switch(currentMode)
  {
    case WITHOUTSMARTPHONE:
      Serial.println("Switch case WITHOUTSMARTPHONE entered... Changing Strategy to SmartphoneMode...");
      delete controllerPtr;
      controllerPtr = new SmartphoneMode();
      break;
    case SMARTPHONE:
      Serial.println("Switch case SMARTPHONE entered... Changing Strategy to WithoutSmartphoneMode...");
      delete controllerPtr;
      controllerPtr = new WithoutSmartphoneMode();
      break;
    default:
      Serial.println("ERROR in switch-case :( .....");
      break;
  }
}
