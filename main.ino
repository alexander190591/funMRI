
#include "src/Modules/ScannerModule/include/RFIDRC522.h"
#include "src/Modules/SoundModule/include/DFPlayerMini.h"
//#include "src/Modules/SoundDummy/Include/SoundDummy.h"
#include "src/Modules/CommunicationModule/Include/BluetoothFeather.h"

/**
 * @brief Defines for Bluefruit Feather nRF52832
 * 
 */
#define SOMO_TX 7
#define SOMO_RX 11
#define SOMO_BAUDRATE 9600
#define LED_PIN LED_BUILTIN
#define RFID_SS_PIN 5
#define RFID_RST_PIN 4

IScannerModule *scannerPtr = nullptr;
ISoundModule *soundPtr = nullptr;
ICommunicationModule *communicationPtr = nullptr;
Data* data = new Data();

unsigned char IDTag[SIZE_OF_DATA_ARRAY - 1] = {0, 0, 0, 0, 0, 0, 0};
unsigned char newIDTag[SIZE_OF_DATA_ARRAY - 1] = {0, 0, 0, 0, 0, 0, 0};

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

  //soundPtr->playSound();

  Serial.println("Setup done...");
}

void loop()
{ 
  data->clearData();  // Every loop starts by clearing data for new data to be received.
  
  communicationPtr->receiveData(*data);

  if(data->dataReceived())
  {
    Serial.println("Data received: ");
    unsigned char receivedArray[SIZE_OF_DATA_ARRAY+1];
    data->getData(receivedArray); Serial.write(receivedArray, SIZE_OF_DATA_ARRAY); Serial.println("");

    Serial.print("Type received: "); Serial.write(receivedArray, 1); Serial.println("");
    Serial.print("_data[0]: "); Serial.write(receivedArray+1,1); Serial.println("");

    if(data->getMessage() == MSG_CMD_INIT || data->getMessage() == MSG_TEST_INIT)
    {
      Serial.println("INIT ENTERED");

      data->setMessage(MSG_ERROR_NO_ID_REGISTERED);
      //String respondToBT = "default";
      scannerPtr->scan();

      Serial.println("After scan()...");

      if(scannerPtr->isNewScanAvailable())
      {
        Serial.println("isNewScanAvailable == true");
        //respondToBT = "scanIsAvailable";
        //respondToBT = "";

        for(int i = 0; i < scannerPtr->getSizeOfData(); i++)
        {
          IDTag[i] = scannerPtr->retrieveResult()[i]; //+= scannerPtr->retrieveResult()[i];
        }
        data->setIDdata(IDTag);
      }

      unsigned char idTagArray[8] = {0,0,0,0,0,0,0,0};
      data->getData(idTagArray);
      Serial.print("IDTag: "); Serial.write(idTagArray+1,7); Serial.println("");

      communicationPtr->sendData(*data);
    }
    else if(data->getMessage() == MSG_CMD_SCAN || data->getMessage() == MSG_TEST_SCAN)
    {
      Serial.println("SCAN ENTERED");
      scannerPtr->scan();
      if(scannerPtr->isNewScanAvailable())
      {
        Serial.println("New scan is available.");
        for(int i = 0; i < scannerPtr->getSizeOfData(); i++)
        {
          newIDTag[i] = scannerPtr->retrieveResult()[i];
        }

        if(data->isSame(newIDTag, IDTag))
        {
          soundPtr->playSound();
          Serial.println("INFO_SOUND_PLAYED (0xCC)");
          data->setMessage(MSG_INFO_SOUND_PLAYED);
          communicationPtr->sendData(*data);
        }
        else
        {
          Serial.println("ERROR_NOT_INIT_TAG (0xBB)");
          data->setMessage(MSG_ERROR_NOT_INIT_TAG);
          communicationPtr->sendData(*data);
          //communicationPtr->sendData("scanning error: not init tag");
        }
      }
    }
    else if(data->getMessage() == MSG_ERROR_NOT_A_MESSAGE)
    {
      data->setMessage(MSG_ERROR_NOT_A_MESSAGE);
      Serial.println("ERROR_NOT_A_MESSAGE (0xFF)");
      unsigned char msgToSend[SIZE_OF_DATA_ARRAY];
      data->getData(msgToSend);
      Serial.print("Sending data: "); Serial.write(msgToSend, SIZE_OF_DATA_ARRAY);
      communicationPtr->sendData(*data);

      //communicationPtr->sendData("scanning error: scanning not available");
    }
    Serial.println("Leaving if(data->dataReceived())...");
  }
}



  // THIS IS OLD CODE.........................................................................................

  //Blocking bluetooth receive:
  //String BTmsg = communicationPtr->receiveData();

//   if(BTmsg.length() >= 1)
//     {
//       String msgSend = "Message received: ";
//       msgSend += BTmsg;

//       //Serial.println(msgSend);
//     }

//   if(BTmsg == "I")
//   {
//     String respondToBT = "default";
//     scannerPtr->scan();

//     if(scannerPtr->isNewScanAvailable())
//     {
//       //respondToBT = "scanIsAvailable";
//       respondToBT = "";
//       for(int i = 0; i < scannerPtr->getSizeOfData(); i++)
//       {
//         respondToBT += scannerPtr->retrieveResult()[i]; //+= scannerPtr->retrieveResult()[i];
//       }
//       IDTag = respondToBT;
//     }

//     communicationPtr->sendData(respondToBT);

//   }
//   if(BTmsg == "S")
//   {
//     scannerPtr->scan();
//     if(scannerPtr->isNewScanAvailable())
//     {
//       String newScanString = "";
//       for(int i = 0; i < scannerPtr->getSizeOfData(); i++)
//       {
//         newScanString += scannerPtr->retrieveResult()[i];
//       }

//       if(newScanString == IDTag)
//       {
//         soundPtr->playSound();
//         communicationPtr->sendData("true");
//       }
//       else
//       {
//         communicationPtr->sendData("scanning error: not init tag");
//       }
//     }

//     else
//     {
//       communicationPtr->sendData("scanning error: scanning not available");
//     }
//   }
// }
