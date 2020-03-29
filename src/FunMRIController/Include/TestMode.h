#ifndef __TESTMODE_H__
#define __TESTMODE_H__

/**
 * @file TestMode.h
 * @author Alexander Najbjerg Christensen (au482141@post.au.dk)
 * @brief In this test mode all objects are public to enable reading of the objects.
 * @version 0.1
 * @date 2020-03-29
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include "IFunMRIController.h"

class TestMode : public IFunMRIController
{
public:
    TestMode();
    ~TestMode();
    void run(void);
    void setmicroSwitchChanged(bool isChanged);
    void setMicroSwitchState(bool isPressed);
// private:     // Made public for making testing simple...
    FunMRI* _funMRI = nullptr;
    bool _microSwitchChanged = false; // Value changed to true in interrupt.
    bool _microSwitchState = false;   // Value changed to true if microswitch is HIGH (slider is in the mini-scanner).
};

 #endif // __TESTMODE_H__