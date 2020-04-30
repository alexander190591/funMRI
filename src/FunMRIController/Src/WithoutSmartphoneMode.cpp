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
#include "../../Protocol/Include/Data.h"

#include <Arduino.h>

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
    Serial.println("Entered run()...");
    while(!(_funMRI->isModeChanged())) // This is the main loop for Without Smartphone mode
    {
        delay(1000);
        if(_funMRI->microSwitchChanged() && _funMRI->getMicroSwitchState())
        {
            _funMRI->microSwitchPressed();
        }
    }
    Serial.print("Exited run()...");
}