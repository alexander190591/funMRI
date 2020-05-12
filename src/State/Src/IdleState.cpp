/**
 * @file IdleState.cpp
 * @author Alexander Najbjerg Christensen (au482141@post.au.dk)
 * @brief This is the idle state of the Without Smartphone mode.
 *        Its job is to handle a scanning when the microswitch is pressed.
 * @version 0.1
 * @date 2020-03-28
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include "../Include/IdleState.h"


#ifndef TEST_BUILD
    #include <Arduino.h>
#endif
#ifdef TEST_BUILD
    #include <iostream>
#endif

IdleState::IdleState()
{
    #ifdef DEBUGGING_SUBTLE
        std::cout << "IdleState object created." << std::endl;
    #endif
}

// void IdleState::handleScanPressed(FunMRI* funMRIPtr); // NOT USED IN WITHOUTSMARTPHONE MODE

// void IdleState::handleInitPressed(FunMRI* funMRIPtr); // NOT USED IN WITHOUTSMARTPHONE MODE

void IdleState::handleModeChanged(FunMRI* funMRIPtr)
{
    // ??????
    (void)funMRIPtr;
}

void IdleState::handleMicroSwitchPressed(FunMRI* funMRIPtr)
{
    #ifdef DEBUGGING_SUBTLE
        std::cout << "IdleState::handleMicroSwitchPressed entered..." << std::endl;
    #endif

    if(funMRIPtr->scan())
    {
        funMRIPtr->playSound();
        #ifdef UART_BUILD
            Serial.println("SOUND PLAYED!");
  		#endif UART_BUILD
    }
}