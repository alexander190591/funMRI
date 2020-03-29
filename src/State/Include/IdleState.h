#ifndef __IDLESTATE_H__
#define __IDLESTATE_H__

/**
 * @file IdleState.h
 * @author Alexander Najbjerg Christensen (au482141@post.au.dk)
 * @brief IdleState is the idle state of the WithoutSmartphone state machine.
 * @version 0.1
 * @date 2020-03-28
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include "IState.h"

class IdleState : public IState
{
    ~IdleState() { /* Nothing to delete here... */ }
    void handleModeChanged(FunMRI* funMRIPtr);
    void handleMicroSwitchPressed(FunMRI* funMRIPtr);
};

#endif // __IDLESTATE_H__