#include "../Include/SmartphoneMode.h"
#include "../../FunMRIFactory/Include/SmartphoneFactory.h"
#include "../../Protocol/Include/Data.h"
#include "../../State/Include/SmartphoneIdleState.h"
#include <Arduino.h>

SmartphoneMode::SmartphoneMode()
{
    #ifdef UART_BUILD
        Serial.println("SmarpthoneMode constructor.");
    #endif // UART_BUILD
    
    _funMRI = new FunMRI(new SmartphoneFactory());

    #ifdef UART_BUILD
        Serial.println("Setting state to SmartphoneIdleState.");
    #endif // UART_BUILD
    
    _funMRI->setState(new SmartphoneIdleState());
    _data = _funMRI->getData();

    #ifdef UART_BUILD
        Serial.println("Exit SmarpthoneMode constructor.");
    #endif // UART_BUILD
}

SmartphoneMode::~SmartphoneMode()
{
    delete _funMRI;
}

void SmartphoneMode::run()
{
    #ifdef UART_BUILD
        Serial.println("run() entered...");
        Serial.print("isModeChanged == "); Serial.println(_funMRI->isModeChanged());
    #endif // UART_BUILD

    while(!(_funMRI->isModeChanged())) // This is the main loop for Without Smartphone mode
    {
        #ifdef UART_BUILD
            Serial.println("SmartphoneMode While loop entered. Listening for data...");
        #endif // UART_BUILD
        
        delay(1000);
        _data->clearData();
        _funMRI->receive();
        
        if(_data->dataReceived())
        {
            #ifdef UART_BUILD
                Serial.println("Data received: ");
            #endif // UART_BUILD
            
            unsigned char receivedArray[SIZE_OF_DATA_ARRAY+1];
            _data->getData(receivedArray); 
            #ifdef UART_BUILD
                Serial.write(receivedArray, SIZE_OF_DATA_ARRAY); Serial.println("");
            #endif // UART_BUILD
            

            #ifdef UART_BUILD
                Serial.print("Type received: "); Serial.write(receivedArray, 1); Serial.println("");
                Serial.print("_data[1]: "); Serial.write(receivedArray+1,1); Serial.println("");
            #endif // UART_BUILD
            
        
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
            #ifdef UART_BUILD
                Serial.println("ERROR_NOT_A_MESSAGE (0xFF)");           // Printing error to serial.
            #endif // UART_BUILD
            
            unsigned char msgToSend[SIZE_OF_DATA_ARRAY];            
            _data->getData(msgToSend);                               // Checking if the message is set correctly.

            #ifdef UART_BUILD
                Serial.print("Sending data: "); Serial.write(msgToSend, SIZE_OF_DATA_ARRAY); // Printing message.
            #endif // UART_BUILD
            /*************************************************************************************************************/

            _funMRI->send(_data);
            }
        }
    }

    #ifdef UART_BUILD
        Serial.print("Before SmartphoneMode.run() exit: modeChanged == "); Serial.println(_funMRI->isModeChanged());
    #endif // UART_BUILD

    
    // Leaving mode, resetting mode changed
    _funMRI->resetModeChanged();

    #ifdef UART_BUILD
        Serial.print("Exits SmartphoneMode.run(). Clearing changed flag: modeChanged == "); Serial.println(_funMRI->isModeChanged());
    #endif // UART_BUILD
    
}