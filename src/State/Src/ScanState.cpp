/**
 * @file ScanState.cpp
 * @author Alexander Najbjerg Christensen (au482141@post.au.dk)
 * @brief 
 * @version 0.1
 * @date 2020-03-28
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include "../Include/ScanState.h"

// void ScanState::handleScanPressed(FunMRI* funMRIPtr); // NOT USED IN WITHOUTSMARTPHONE MODE

// void ScanState::handleInitPressed(FunMRI* funMRIPtr); // NOT USED IN WITHOUTSMARTPHONE MODE

void ScanState::handleModeChanged(FunMRI* funMRIPtr)
{
    // ??????
}

void ScanState::handleMicroSwitchPressed(FunMRI* funMRIPtr)
{
    #ifdef DEBUGGING_SUBTLE
        std::cout << "IdleState::handleMicroSwitchPressed entered..." << std::endl;
    #endif

    funMRIPtr->scan();
    funMRIPtr->setState(new ScanState());
}