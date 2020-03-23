#ifndef STATEDUMMY_H_
#define STATEDUMMY_H_

/**
 * @file IState.h
 * @author Alexander Najbjerg Christensen (au482141@post.au.dk)
 * @brief STATEDUMMY for the states used in the State Pattern.
 * @version 0.1
 * @date 2020-03-18
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include "../../FunMRI/Include/FunMRI.h"

class FunMRI; // Forward declaration...  https://stackoverflow.com/questions/396084/headers-including-each-other-in-c

class StateDummy : public IState
{
public:
    void handleScanPressed(FunMRI* funMRIPtr);
    void handleInitPressed(FunMRI* funMRIPtr);
    void handleModeChanged(FunMRI* funMRIPtr);
    void handleMicroSwitchPressed(FunMRI* funMRIPtr);
};

#endif // STATEDUMMY_H_