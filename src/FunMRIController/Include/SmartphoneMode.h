#ifndef __SMARTPHONEMODE_H__
#define __SMARTPHONEMODE_H__

/**
 * @file SmartphoneMode.h
 * @author Alexander Najbjerg Christensen (au482141@post.au.dk)
 * @brief 
 * @version 0.1
 * @date 2020-03-16
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include "IFunMRIController.h"

class SmartphoneMode : public IFunMRIController
{
public:
    SmartphoneMode();
    ~SmartphoneMode();
    void run(void);
    void setmicroSwitchChanged(bool isChanged);
    void setMicroSwitchState(bool isPressed);
private:
    FunMRI* _funMRI = nullptr;
    bool _microSwitchChanged = false; // Value changed to true in interrupt.
    bool _microSwitchState = false;   // Value changed to true if microswitch is HIGH (slider is in the mini-scanner).
};

#endif // __SMARTPHONEMODE_H__