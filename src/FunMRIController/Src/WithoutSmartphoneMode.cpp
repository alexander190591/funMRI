/**
 * @file WithoutSmartphoneMode.cpp
 * @author Alexander Najbjerg Christensen (au482141@post.au.dk)
 * @brief This is the strategy that runs funMRI without a smartphone.
 * @version 0.1
 * @date 2020-03-28
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include "../Include/WithoutSmartphoneMode.h"
#include "../../FunMRIFactory/Include/WithoutSmartphoneFactory.h"
#include "../../State/Include/IdleState.h"

/**
 * @brief Constructs a new WithoutSmartphoneMode object, starts up the FunMRI object within,
 *        and sets state to IdleState.
 * 
 */
WithoutSmartphoneMode::WithoutSmartphoneMode()
{
    _funMRI = new FunMRI(new WithoutSmartphoneFactory());
    _funMRI->setState(new IdleState());
}

WithoutSmartphoneMode::~WithoutSmartphoneMode()
{
    delete _funMRI;
}

void WithoutSmartphoneMode::run()
{
    while(1) // This is the main loop for Without Smartphone mode
    {
        if(_microSwitchChanged && _microSwitchState) // Values should be set in interrupt routines.
            {
                _funMRI->microSwitchPressed();
                _microSwitchChanged = false;
            }
    }
}

/**
 * @brief Sets a bool value corresponding to a micro switch interrupt made on a change in value.
 *        OBS: Should be reset when handled, as a new interrupt should be able to happen!
 * 
 * @param isChanged is set to true if an interrupt has just happened.
 */
void WithoutSmartphoneMode::setmicroSwitchChanged(bool isChanged) 
{
    _microSwitchChanged = isChanged;
}

/**
 * @brief Sets the state of the micro switch (pressed/not pressed) as a bool value.
 * 
 * @param isPressed corresponds to the value read on the digital pin connected to the micro switch.
 */
void WithoutSmartphoneMode::setMicroSwitchState(bool isPressed) 
{
    _microSwitchState = isPressed;
}