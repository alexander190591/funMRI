#ifndef ISTATE_H_
#define ISTATE_H_

/**
 * @file IState.h
 * @author Alexander Najbjerg Christensen (au482141@post.au.dk)
 * @brief Interface for the states used in the State Pattern.
 * @version 0.1
 * @date 2020-03-18
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include "../../FunMRI/Include/FunMRI.h"

class FunMRI; // Forward declaration...  https://stackoverflow.com/questions/396084/headers-including-each-other-in-c

class IState
{
public:
    virtual void handleScanPressed(FunMRI* funMRIPtr) = 0;
    virtual void handleInitPressed(FunMRI* funMRIPtr) = 0;
    virtual void handleModeChanged(FunMRI* funMRIPtr) = 0;
    virtual void handleMicroSwitchPressed(FunMRI* funMRIPtr) = 0;
};

#endif // ISTATE_H_
