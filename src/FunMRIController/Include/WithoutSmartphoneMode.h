#ifndef __WITHOUTSMARTPHONEMODE_H__
#define __WITHOUTSMARTPHONEMODE_H__

/**
 * @file WithoutSmartphoneMode.h
 * @author Alexander Najbjerg Christensen (au482141@post.au.dk)
 * @brief 
 * @version 0.1
 * @date 2020-03-16
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include "IFunMRIController.h"

class WithoutSmartphoneMode : public IFunMRIController
{
public:
    WithoutSmartphoneMode();
    ~WithoutSmartphoneMode();
    void run(void);
    void setMicroSwitchChanged(bool isChanged);
    void setMicroSwitchState(bool isPressed);
private:
    FunMRI* _funMRI = nullptr;
    volatile bool _microSwitchChanged = false; // Value changed to true in interrupt.
    volatile bool _microSwitchState = false;   // Value changed to true if microswitch is HIGH (slider is in the mini-scanner).
};

#endif // __WITHOUTSMARTPHONEMODE_H__