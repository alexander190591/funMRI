#ifndef IUSERINTERFACEMODULE_H_
#define IUSERINTERFACEMODULE_H_

/**
 * @file IUserInterfaceModule.h
 * @author Alexander Najbjerg Christensen (au482141@post.au.dk)
 * @brief Interface for the User Interface.
 * @version 0.1
 * @date 2020-03-18
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include "../../../build_defines.h"

class IUserInterfaceModule
{
public:
    virtual ~IUserInterfaceModule() { /*Nothing to delete...*/ };
    // MicroSwitch (bed in or out)
    virtual bool microSwitchChanged(void) = 0;
    virtual bool getMicroSwitchState(void) = 0;
    // Mode button
    virtual bool modeChanged(void) = 0;
    virtual bool getMode(void) = 0;
    // Supply LED
    virtual void supplyLEDOn(void) = 0;
    virtual void supplyLEDblink(void) = 0;
    virtual void supplyLEDOff(void) = 0;
    virtual void resetModeChanged(void) = 0;                    // Used to clear the _modeChanged flag. Should ONLY be used, when the change has been handled!
    virtual void resetMicroSwitchChanged(void) = 0;             // Used to clear the _microSwitchChanged flag. Should ONLY be used, when the change has been handled!
private:
    virtual bool readModeButton(void) = 0;                      // Sets _mode. Changes _modeChanged if _mode has changed since last time this method was called.
    virtual void setModeChanged(bool isChanged) = 0;            // Sets _modeChanged.
    virtual bool readMicroSwitch(void) = 0;                     // Sets _microSwitchState. Changes _microSwitchChanged if _microSwitchState changes since this method was called.
    virtual void setMicroSwitchChanged(bool isChanged) = 0;     // Sets _microSwitchChanged.

    // These should be in the implementation of the interface.
    // volatile bool _microSwitchChanged = false;              // Value changed to true in readMicroSwitch() if _microSwitchState has changed since last time .
    // volatile bool _microSwitchState = 0;                    // Value changed to true if microswitch is HIGH (slider is in the mini-scanner).
    // volatile bool _mode = 0;                                // Current mode switch value (HIGH == 1 or LOW == 0).
    // volatile bool _modeChanged = false;                     // Boolean changed to true if _mode has changed since last time readModeButton() was called.
};


#endif // IUSERINTERFACEMODULE_H_