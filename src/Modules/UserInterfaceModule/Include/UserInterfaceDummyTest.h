/**
 * @file UserInterfaceDummyTest.h
 * @author Alexander Najbjerg Christensen (au482141@post.au.dk)
 * @brief 
 * @version 0.1
 * @date 2020-03-26
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include "IUserInterfaceModule.h"

#ifdef TEST_BUILD
    #include <iostream>
#endif

class UserInterfaceDummyTest: public IUserInterfaceModule
{
public:
    UserInterfaceDummyTest() { 
        #ifdef DEBUGGING_LARGE
            std::cout << "UserInterfaceDummyTest: Constructor." << std::endl;
        #endif
        }

    ~UserInterfaceDummyTest() { 
        #ifdef DEBUGGING_LARGE
            std::cout << "UserInterfaceDummyTest: Destructor." << std::endl;
        #endif
        /*Nothing to delete...*/
        }

    // MicroSwitch (bed in or out)
    bool microSwitchChanged() {
        readMicroSwitch();
        #ifdef DEBUGGING_SUBTLE
            std::cout << "microSwitchChanged == " << _microSwitchChanged << std::endl;
        #endif
        return _microSwitchChanged;
    };

    bool getMicroSwitchState(){
        readMicroSwitch();
        #ifdef DEBUGGING_SUBTLE
            std::cout << "getMicroSwitchState == " << _microSwitchState << std::endl;
        #endif
        return _microSwitchState;
    };

    // Mode button
    bool modeChanged(){
        readModeButton();
        #ifdef DEBUGGING_SUBTLE
            std::cout << "modeChanged == " << _modeChanged << std::endl;
        #endif
        return _modeChanged;
    };

    bool getMode(){
        readModeButton();
        #ifdef DEBUGGING_SUBTLE
            std::cout << "getMode." << std::endl;
        #endif
        return _mode;
    };

    // Supply LED
    void supplyLEDOn(){
        #ifdef DEBUGGING_SUBTLE
            std::cout << "supplyLEDOn." << std::endl;
        #endif
    };

    void supplyLEDblink(){
        #ifdef DEBUGGING_SUBTLE
            std::cout << "supplyLEDblink." << std::endl;
        #endif
    };
    void supplyLEDOff(){
        #ifdef DEBUGGING_SUBTLE
            std::cout << "supplyLEDOff." << std::endl;
        #endif
    };
private:
    bool readModeButton()                      // Sets _mode. Changes _modeChanged if _mode has changed since last time this method was called.
    {
        bool tmpMode = false;

        #ifdef DEBUGGING_SUBTLE
            std::cout << "readModeButton() entered. Set input to 1 or 0...: ";
            std::cin >> tmpMode;
        #endif

        if(_mode != tmpMode)
        {
            setModeChanged(true);
        }
        _mode = tmpMode;

        #ifdef DEBUGGING_SUBTLE
            std::cout << "Returning: " << _mode << std::endl;
        #endif

        return _mode;
    };

    void setModeChanged(bool isChanged)        // Sets _modeChanged.
    {
        _modeChanged = isChanged;
        #ifdef DEBUGGING_SUBTLE
            std::cout << "setModeChanged() == " << _modeChanged << std::endl;
        #endif
    };
    
    bool readMicroSwitch()                     // Sets _microSwitchState. Changes _microSwitchChanged if _microSwitchState changes since
    {
        bool tmpState = false;

        #ifdef DEBUGGING_SUBTLE
            std::cout << "readMicroSwitch() entered. Set input to HIGH (1) or LWO (0)...: ";
            std::cin >> tmpState;
            std::cout << "Before _microSwitchState was = " << _microSwitchState << std::endl;
            std::cout << "Now tmpState is == " << tmpState << std::endl;
        #endif

        if(_microSwitchState!= tmpState)
        {
            setMicroSwitchChanged(true);
            #ifdef DEBUGGING_SUBTLE
                std::cout << "setMicroSwitchChanged(true) results in _MicroSwitchChanged == " << _microSwitchChanged << std::endl;
            #endif
        }
        _microSwitchState = tmpState;

        #ifdef DEBUGGING_SUBTLE
            std::cout << "Returning the _microSwitchState: " << _microSwitchState << std::endl;
        #endif

        return _microSwitchState;
    };
    
    void setMicroSwitchChanged(bool isChanged) // Sets _microSwitchChanged.
    {
        _microSwitchChanged = isChanged;
        #ifdef DEBUGGING_SUBTLE
            std::cout << "setMicroSwitchChanged. _microSwitchChanged == " << _microSwitchChanged << std::endl;
        #endif
    };

    /**
     * @brief Used to clear the modeChanged "flag" to enable next change in mode.
     *      Should ONLY be used, when the change has been handled!
     */
    void resetModeChanged(void) 
    {
        _modeChanged = false;
        #ifdef DEBUGGING_SUBTLE
            std::cout << "resetModeChanged. _modeChanged == " << _modeChanged << std::endl;
        #endif
    }

    /**
     * @brief Used to clear the microSwitchChanged "flag" to enable next change in microswitch.
     *      Should ONLY be used, when the change has been handled!
     */
    void resetMicroSwitchChanged(void) 
    {
        _microSwitchChanged = false;
        #ifdef DEBUGGING_SUBTLE
            std::cout << "resetModeChanged reset to: " << _microSwitchChanged << std::endl;
        #endif  
    }

    // These should be in the implementation of the interface.
    volatile bool _microSwitchChanged = false;              // Value changed to true in readMicroSwitch() if _microSwitchState has changed since last time .
    volatile bool _microSwitchState = 0;                    // Value changed to true if microswitch is HIGH (slider is in the mini-scanner).
    volatile bool _mode = 0;                                // Current mode switch value (HIGH == 1 or LOW == 0).
    volatile bool _modeChanged = false;                     // Boolean changed to true if _mode has changed since last time readModeButton() was called.
};