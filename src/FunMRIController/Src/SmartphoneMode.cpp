#include "../Include/SmartphoneMode.h"
#include "../../FunMRIFactory/Include/SmartphoneFactory.h"
#include "../../Protocol/Include/Data.h"
#include <Arduino.h>

SmartphoneMode::SmartphoneMode()
{
    _funMRI = new FunMRI(new SmartphoneFactory());
    //_funMRI->setState(???????);
}

SmartphoneMode::~SmartphoneMode()
{
    delete _funMRI;
}

void SmartphoneMode::run()
{
    while(1) // This is the main loop for Without Smartphone mode
    {
        _funMRI->receive();
        IData* data = _funMRI->getData();

        if(data->getMessage() == MSG_CMD_INIT || data->getMessage() == MSG_TEST_INIT)
        {
            _funMRI->initPressed();
        }
        else if(data->getMessage() == MSG_CMD_SCAN || data->getMessage() == MSG_TEST_SCAN)
        {
            _funMRI->scanPressed();
        }
        else// if(data->getMessage() == MSG_ERROR_NOT_A_MESSAGE)
        {
        data->setMessage(MSG_ERROR_NOT_A_MESSAGE);              // Setting message up in data object in the FunMRI Object.
        
        /* For debugging purposes... *********************************************************************************/
        Serial.println("ERROR_NOT_A_MESSAGE (0xFF)");           // Printing error to serial.
        unsigned char msgToSend[SIZE_OF_DATA_ARRAY];            
        data->getData(msgToSend);                               // Checking if the message is set correctly.
        Serial.print("Sending data: "); Serial.write(msgToSend, SIZE_OF_DATA_ARRAY); // Printing message.
        /*************************************************************************************************************/

        _funMRI->send(data);
        }
    }
}

/**
 * @brief Sets a bool value corresponding to a micro switch interrupt made on a change in value.
 *        OBS: Should be reset when handled, as a new interrupt should be able to happen!
 * 
 * @param isChanged is set to true if an interrupt has just happened.
 */
void SmartphoneMode::setMicroSwitchChanged(bool isChanged) 
{
    _microSwitchChanged = isChanged;
}

/**
 * @brief Sets the state of the micro switch (pressed/not pressed) as a bool value.
 * 
 * @param isPressed corresponds to the value read on the digital pin connected to the micro switch.
 */
void SmartphoneMode::setMicroSwitchState(bool isPressed) 
{
    _microSwitchState = isPressed;
}