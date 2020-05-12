#ifndef __USERINTERFACE_H__
#define __USERINTERFACE_H__

/**
 * @file UserInterface.h
 * @author Alexander Najbjerg Christensen (au482141@post.au.dk)
 * @brief 
 * @version 0.1
 * @date 2020-04-30
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include "../include/IUserInterfaceModule.h"

class UserInterfaceModule : public IUserInterfaceModule
{
public:
    UserInterfaceModule(bool madeInSmartphoneMode);
    ~UserInterfaceModule() { /*Nothing to delete...*/ };
    // MicroSwitch (bed in or out)
    bool microSwitchChanged(void);
    bool getMicroSwitchState(void);
    // Mode button
    bool modeChanged(void);
    bool getMode(void);
    // Supply LED
    void supplyLEDOn(void);
    void supplyLEDblink(void);
    void supplyLEDOff(void);
    void resetModeChanged(void);                    // Used to clear the _modeChanged flag. Should ONLY be used, when the change has been handled!
    void resetMicroSwitchChanged(void);             // Used to clear the _microSwitchChanged flag. Should ONLY be used, when the change has been handled!
private:
    bool readModeButton(void);                      // Sets _mode. Changes _modeChanged if _mode has changed since last time this method was called.
    void setModeChanged(bool isChanged);            // Sets _modeChanged.
    bool readMicroSwitch(void);                     // Sets _microSwitchState. Changes _microSwitchChanged if _microSwitchState changes since this method was called.
    void setMicroSwitchChanged(bool isChanged);     // Sets _microSwitchChanged.

    // These should be in the implementation of the interface.
    volatile bool _microSwitchChanged = false;              // Value changed to true in readMicroSwitch() if _microSwitchState has changed since last time .
    volatile bool _microSwitchState = 0;                    // Value changed to true if microswitch is HIGH (slider is in the mini-scanner).
    volatile bool _mode = 0;                                // Current mode switch value (HIGH == 1 or LOW == 0).
    volatile bool _modeChanged = false;                     // Boolean changed to true if _mode has changed since last time readModeButton() was called.
};

 #endif // __USERINTERFACE_H__