
#include "src/Modules/ScannerModule/include/RFIDRC522.h"
#include "src/Modules/SoundModule/include/DFPlayerMini.h"
//#include "src/Modules/SoundDummy/Include/SoundDummy.h"
#include "src/Modules/CommunicationModule/Include/BluetoothFeather.h"

/**
 * @brief Defines for Bluefruit Feather nRF52832
 * 
 */
#define SOMO_TX 7      //28 before
#define SOMO_RX 11     //29 before
#define SOMO_BAUDRATE 9600
#define LED_PIN LED_BUILTIN
#define RFID_SS_PIN 5
#define RFID_RST_PIN 4

IScannerModule *scannerPtr = nullptr;
ISoundModule *soundPtr = nullptr;
ICommunicationModule *communicationPtr = nullptr;
String IDTag = "";

void setup()
{
  Serial.begin(9600);

  pinMode(LED_PIN, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);


  communicationPtr = new BluetoothFeather();
  communicationPtr->init();

  scannerPtr = new RFIDRC522(RFID_RST_PIN, RFID_SS_PIN);

  soundPtr = new DFPlayerMini(SOMO_RX, SOMO_TX, SOMO_BAUDRATE);
  //soundPtr = new SoundDummy(LED_PIN);

  digitalWrite(LED_BUILTIN, HIGH);

  soundPtr->playSound();

  Serial.println("Setup done...");
}

void loop()
{ 
  // String messageReceived = communicationPtr->receiveCmd();
  // if(messageReceived.length() >= 1)
  //   {
  //     String msgSend = "Message received: ";
  //     msgSend += messageReceived;

  //     Serial.println(msgSend);

  //     communicationPtr->sendCmd(msgSend);
  //   }
  
  // scannerPtr->scan();
  // if(scannerPtr->isNewScanAvailable())
  //   {
  //     //respondToBT = "scanIsAvailable";
  //     String respondToBT = "";
  //     for(int i = 0; i < scannerPtr->getSizeOfData(); i++)
  //     {
  //       respondToBT += scannerPtr->retrieveResult()[i]; //+= scannerPtr->retrieveResult()[i];
  //     }
  //     IDTag = respondToBT;
  //   }

  // delay(3000);

  // digitalWrite(LED_BUILTIN, HIGH);
  // digitalWrite(LED_PIN, HIGH);
  // delay(1000);
  // digitalWrite(LED_PIN, LOW);
  // digitalWrite(LED_BUILTIN, LOW);
  // delay(1000);

  //Blocking bluetooth receive:
  String BTmsg = communicationPtr->receiveCmd();

  if(BTmsg.length() >= 1)
    {
      String msgSend = "Message received: ";
      msgSend += BTmsg;

      //Serial.println(msgSend);
    }

  if(BTmsg == "I")
  {
    String respondToBT = "default";
    scannerPtr->scan();

    if(scannerPtr->isNewScanAvailable())
    {
      //respondToBT = "scanIsAvailable";
      respondToBT = "";
      for(int i = 0; i < scannerPtr->getSizeOfData(); i++)
      {
        respondToBT += scannerPtr->retrieveResult()[i]; //+= scannerPtr->retrieveResult()[i];
      }
      IDTag = respondToBT;
    }

    communicationPtr->sendCmd(respondToBT);

  }
  if(BTmsg == "S")
  {
    scannerPtr->scan();
    if(scannerPtr->isNewScanAvailable())
    {
      String newScanString = "";
      for(int i = 0; i < scannerPtr->getSizeOfData(); i++)
      {
        newScanString += scannerPtr->retrieveResult()[i];
      }

      if(newScanString == IDTag)
      {
        soundPtr->playSound();
        communicationPtr->sendCmd("true");
      }
      else
      {
        communicationPtr->sendCmd("scanning error: not init tag");
      }
    }

    else
    {
      communicationPtr->sendCmd("scanning error: scanning not available");
    }
  }
}
