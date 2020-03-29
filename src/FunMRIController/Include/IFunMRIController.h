#ifndef __IFUNMRICONTROLLER_H__
#define __IFUNMRICONTROLLER_H__

/**
 * @file IFunMRIController.h
 * @author Alexander Najbjerg Christensen (au482141@post.au.dk)
 * @brief Interface for the funMRIController. This is the controller class. It has only one method: Run().
 * @version 0.1
 * @date 2020-03-16
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include "../../FunMRI/Include/FunMRI.h"

class IFunMRIController
{
public:
    ~IFunMRIController() { /* Nothing to delete here... */ }
    virtual void run(void) = 0;
    virtual void setmicroSwitchChanged(bool isChanged) = 0;
    virtual void setMicroSwitchState(bool isPressed) = 0;
};

#endif // __IFUNMRICONTROLLER_H__