/**
 * @file SmartphoneIdleState.cpp
 * @author Alexander Najbjerg Christensen (au482141@post.au.dk)
 * @brief This is the idle state of the Smartphone mode.
 *        Its job is to handle all scenarios when a smartphone is connected.
 * @version 0.1
 * @date 2020-03-28
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include "../Include/SmartphoneIdleState.h"
#include "../../Protocol/Include/Data.h"

#include <Arduino.h>

SmartphoneIdleState::SmartphoneIdleState()
{

}

void SmartphoneIdleState::handleScanPressed(FunMRI* funMRIPtr)
{
    #ifdef UART_BUILD
        Serial.println("SmartphoneIdleState::handleScanPressed() entered.");
    #endif UART_BUILD

    Data* data = new Data();
    unsigned char id[SIZE_OF_DATA_ARRAY-1];

    if(funMRIPtr->scan())
    {
        #ifdef UART_BUILD
            Serial.println("New scan is available.");
  		#endif UART_BUILD
        
        funMRIPtr->getNewID(id);                                            // Reading new scan into id.

        if(funMRIPtr->isIDSameAsInit(id))                                   // If the new ID scanned (stored as _newID in FunMRI object) is same as _storedID (set in handleInitPressed())
        {
            funMRIPtr->playSound();                                         // Sound is played.

            #ifdef UART_BUILD
                Serial.println("INFO_SOUND_PLAYED (0xCC)");                     // For debugging purposes...
  		    #endif UART_BUILD

            data->setMessage(MSG_INFO_SOUND_PLAYED);                        // Setting message to be sent.
            funMRIPtr->send(data);                                          // Sending.
        }
        else
        {
            #ifdef UART_BUILD
                Serial.println("ERROR_NOT_INIT_TAG (0xBB)");                    // For debugging purposes...
  		    #endif UART_BUILD

            data->setMessage(MSG_ERROR_NOT_INIT_TAG);                       // Setting error message to be sent.
            funMRIPtr->send(data);                                          // Sending.
        }
    }
    else
    {
        #ifdef UART_BUILD
            Serial.println("MSG_ERROR_NO_ID_REGISTERED (0x00)");                
  		#endif UART_BUILD                                                        
                                                                            
        data->setMessage(MSG_ERROR_NO_ID_REGISTERED);                       
        funMRIPtr->send(data);                                              
    }
}

void SmartphoneIdleState::handleInitPressed(FunMRI* funMRIPtr)
{
    #ifdef UART_BUILD
        Serial.println("SmartphoneIdleState::handleInitPressed() entered.");    // For debugging purposes...
    #endif UART_BUILD
    
    Data* data = new Data();
    data->setMessage(MSG_ERROR_NO_ID_REGISTERED);                           // Default message set in data object.
    unsigned char id[SIZE_OF_DATA_ARRAY-1];

    if(funMRIPtr->scan())                                                   // Scanning. If anything is scanned, it's read and set into funMRIPtr->_newID[SIZE_OF_DATA_ARRAY-1].
    {
        #ifdef UART_BUILD
            Serial.println("New scan is available.");                           // For debugging purposes...
  		#endif UART_BUILD
        

        funMRIPtr->getNewID(id);                                            // Reading new scan into id.
        funMRIPtr->storeInitID(id);                                         // Storing id into _storedID in the FunMRI object.
        data->setIDdata(id);                                                // Setting up the data in the Data object for sending.
    }

    #ifdef UART_BUILD
        Serial.print("IDTag: "); Serial.write(id+1,7); Serial.println("");      // For debugging purposes...
    #endif UART_BUILD
    
    funMRIPtr->send(data);                                                  // Sending the new tag as stated in the protocol ('D' + id);
}


void SmartphoneIdleState::handleModeChanged(FunMRI* funMRIPtr)
{
    // This is not where the mode is handled. It's in the Run-method of the FunMRIController.
}

void SmartphoneIdleState::handleMicroSwitchPressed(FunMRI* funMRIPtr)
{
    #ifdef DEBUGGING_SUBTLE
        std::cout << "SmartphoneIdleState::handleMicroSwitchPressed entered..." << std::endl;
    #endif

    // Here we could send a message of the state of the microswitch to the app...
}