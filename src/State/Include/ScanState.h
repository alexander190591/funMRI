#ifndef __SCANSTATE_H__
#define __SCANSTATE_H__

/**
 * @file ScanState.h
 * @author Alexander Najbjerg Christensen (au482141@post.au.dk)
 * @brief state of the WithoutSmartphone state machine.
 * @version 0.1
 * @date 2020-03-28
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include "IState.h"

class ScanState : public IState
{
    ~ScanState() override { /* Nothing to delete here... */ }
    void handleModeChanged(FunMRI* funMRIPtr) override;
    void handleMicroSwitchPressed(FunMRI* funMRIPtr) override;
};

#endif // __SCANSTATE_H__