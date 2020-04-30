#include "../Include/SmartphoneMode.h"
#include "../../FunMRIFactory/Include/SmartphoneFactory.h"
#include "../../Protocol/Include/Data.h"
#include "../../State/Include/SmartphoneIdleState.h"
#include <Arduino.h>

SmartphoneMode::SmartphoneMode()
{
    Serial.println("SmarpthoneMode constructor.");
    _funMRI = new FunMRI(new SmartphoneFactory());
    Serial.println("Setting state to SmartphoneIdleState.");
    _funMRI->setState(new SmartphoneIdleState());
    _data = _funMRI->getData();
}

SmartphoneMode::~SmartphoneMode()
{
    delete _funMRI;
}

void SmartphoneMode::run()
{
    Serial.println("run() entered...");
    Serial.print("isModeChanged == "); Serial.println(_funMRI->isModeChanged());

    while(!(_funMRI->isModeChanged())) // This is the main loop for Without Smartphone mode
    {
        Serial.println("While loop entered...");
        _data->clearData();
        _funMRI->receive();
        
        if(_data->dataReceived())
        {
            Serial.println("Data received: ");
            unsigned char receivedArray[SIZE_OF_DATA_ARRAY+1];
            _data->getData(receivedArray); Serial.write(receivedArray, SIZE_OF_DATA_ARRAY); Serial.println("");

            Serial.print("Type received: "); Serial.write(receivedArray, 1); Serial.println("");
            Serial.print("_data[1]: "); Serial.write(receivedArray+1,1); Serial.println("");
        
            _data = _funMRI->getData();

            if(_data->getMessage() == MSG_CMD_INIT || _data->getMessage() == MSG_TEST_INIT)
            {
                _funMRI->initPressed();
            }
            else if(_data->getMessage() == MSG_CMD_SCAN || _data->getMessage() == MSG_TEST_SCAN)
            {
                _funMRI->scanPressed();
            }
            else// if(data->getMessage() == MSG_ERROR_NOT_A_MESSAGE)
            {
            _data->setMessage(MSG_ERROR_NOT_A_MESSAGE);              // Setting message up in data object in the FunMRI Object.
            
            /* For debugging purposes... *********************************************************************************/
            Serial.println("ERROR_NOT_A_MESSAGE (0xFF)");           // Printing error to serial.
            unsigned char msgToSend[SIZE_OF_DATA_ARRAY];            
            _data->getData(msgToSend);                               // Checking if the message is set correctly.
            Serial.print("Sending data: "); Serial.write(msgToSend, SIZE_OF_DATA_ARRAY); // Printing message.
            /*************************************************************************************************************/

            _funMRI->send(_data);
            }
        }
    }
}