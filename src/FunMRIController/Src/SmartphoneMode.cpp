#include "../Include/SmartphoneMode.h"
#include "../../FunMRIFactory/Include/SmartphoneFactory.h"

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
        //_funMRI->receive();
    }
}

/**
 * @brief Sets a bool value corresponding to a micro switch interrupt made on a change in value.
 *        OBS: Should be reset when handled, as a new interrupt should be able to happen!
 * 
 * @param isChanged is set to true if an interrupt has just happened.
 */
void SmartphoneMode::setmicroSwitchChanged(bool isChanged) 
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