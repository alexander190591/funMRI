#ifndef __ISTATE_H__
#define __ISTATE_H__

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
#include "../../build_defines.h"

#ifdef TEST_BUILD
    #include <iostream>
#endif


class FunMRI; // Forward declaration...  https://stackoverflow.com/questions/396084/headers-including-each-other-in-c

class IState
{
public:
    virtual ~IState() { /* Nothing to delete here... */ }
    virtual void handleScanPressed(FunMRI* funMRIPtr)
    {
        #ifdef DEBUGGING_SUBTLE
            std::cout << "handleScanPressed: Nothing special happens..." << std::endl;
        #endif
        
        (void)funMRIPtr;    // Removing warning. Should not be used. Nothing should happen here.
    }
    
    virtual void handleInitPressed(FunMRI* funMRIPtr)
    {
        #ifdef DEBUGGING_SUBTLE
            std::cout << "handleInitPressed: Nothing special happens..." << std::endl;
        #endif
        
        (void)funMRIPtr;    // Removing warning. Should not be used. Nothing should happen here.
    }
    
    virtual void handleModeChanged(FunMRI* funMRIPtr)
    {
        #ifdef DEBUGGING_SUBTLE
            std::cout << "handleModeChanged: Nothing special happens..." << std::endl;
        #endif

        (void)funMRIPtr;    // Removing warning. Should not be used. Nothing should happen here.
    }

    virtual void handleMicroSwitchPressed(FunMRI* funMRIPtr)
    {
        #ifdef DEBUGGING_SUBTLE
            std::cout << "handleMicroSwitchPressed: Nothing special happens..." << std::endl;
        #endif

        (void)funMRIPtr;    // Removing warning. Should not be used. Nothing should happen here.
    }
};

#endif // __ISTATE_H__