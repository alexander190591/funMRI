/**
 * @file IdleState.cpp
 * @author Alexander Najbjerg Christensen (au482141@post.au.dk)
 * @brief This is the idle state of the Without Smartphone mode.
 *        Its job is to set the state to ScanState when the microswitch is pressed.
 * @version 0.1
 * @date 2020-03-28
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include "../Include/IdleState.h"
#include "../Include/ScanState.h"

// void IdleState::handleScanPressed(FunMRI* funMRIPtr); // NOT USED IN WITHOUTSMARTPHONE MODE

// void IdleState::handleInitPressed(FunMRI* funMRIPtr); // NOT USED IN WITHOUTSMARTPHONE MODE

void IdleState::handleModeChanged(FunMRI* funMRIPtr)
{
    // ??????
}

void IdleState::handleMicroSwitchPressed(FunMRI* funMRIPtr)
{
    #ifdef DEBUGGING_SUBTLE
        std::cout << "IdleState::handleMicroSwitchPressed entered..." << std::endl;
    #endif

    funMRIPtr->scan();
    funMRIPtr->setState(new ScanState());
}