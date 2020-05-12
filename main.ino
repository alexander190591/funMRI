
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

IFunMRIController* controllerPtr = nullptr;
unsigned char currentMode;

enum MODE{
  SMARTPHONE        = 0,
  WITHOUTSMARTPHONE = 1,
};

void setup()
{
  Serial.begin(9600);

  pinMode(LED_PIN, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);

  // O B J E C T   I N I T I A L I Z A T I O N
  controllerPtr = new WithoutSmartphoneMode();
  currentMode = WITHOUTSMARTPHONE;
  
  // For debugging:
  #ifdef UART_BUILD
    Serial.println("Setup done...");
  #endif // UART_BUILD
}

void loop()
{ 
  controllerPtr->run();

  #ifdef UART_BUILD
    Serial.println("Out of run(). STATUS: ");
    Serial.print("---- currentMode: "); Serial.println(currentMode);    
  #endif // UART_BUILD
  
  switch(currentMode)
  {
    case WITHOUTSMARTPHONE:

      #ifdef UART_BUILD
        Serial.println("Switch case WITHOUTSMARTPHONE entered... Changing Strategy to SmartphoneMode...");
      #endif // UART_BUILD

      delete controllerPtr;
      controllerPtr = new SmartphoneMode();
      currentMode = SMARTPHONE;
      break;
    case SMARTPHONE:
    
      #ifdef UART_BUILD
        Serial.println("Switch case SMARTPHONE entered... Changing Strategy to WithoutSmartphoneMode...");
      #endif // UART_BUILD

      delete controllerPtr;
      controllerPtr = new WithoutSmartphoneMode();
      currentMode = WITHOUTSMARTPHONE;
      break;
    default:

      #ifdef UART_BUILD
        Serial.println("ERROR in switch-case :( .....");
      #endif // UART_BUILD
      
      break;
  }
}
