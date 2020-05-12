/**
 * @file DummyUserInterface.h
 * @author Alexander Najbjerg Christensen (au482141@post.au.dk)
 * @brief 
 * @version 0.1
 * @date 2020-03-26
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include "IUserInterfaceModule.h"
#include <Arduino.h>

class DummyUserInterface: public IUserInterfaceModule
{
public:
    DummyUserInterface() {
        #ifdef UART_BUILD
            Serial.println("DummyUserInterface: Constructor");
  		#endif UART_BUILD
        }
    ~DummyUserInterface() {
        #ifdef UART_BUILD
            Serial.println("DummyUserInteface: Destructor"); 
  		#endif UART_BUILD
        /*Nothing to delete...*/}
        // MicroSwitch (bed in or out)
    bool microSwitchChanged() {
        #ifdef DEBUGGING_LARGE
            std::cout << "microSwitchChanged." << std::endl;
        #endif
    };
    bool getMicroSwitchState(){
        #ifdef DEBUGGING_LARGE
            std::cout << "getMicroSwitchState." << std::endl;
        #endif
    };
    // Mode button
    bool modeChanged(){
        #ifdef DEBUGGING_LARGE
            std::cout << "modeChanged." << std::endl;
        #endif
    };
    bool getMode(){
        #ifdef DEBUGGING_LARGE
            std::cout << "getMode." << std::endl;
        #endif
    };
    // Supply LED
    void supplyLEDOn(){
        #ifdef DEBUGGING_LARGE
            std::cout << "supplyLEDOn." << std::endl;
        #endif
    };
    void supplyLEDblink(){
        #ifdef DEBUGGING_LARGE
            std::cout << "supplyLEDblink." << std::endl;
        #endif
    };
    void supplyLEDOff(){
        #ifdef DEBUGGING_LARGE
            std::cout << "supplyLEDOff." << std::endl;
        #endif
    };
private:
    bool readModeButton()                      // Sets _mode. Changes _modeChanged if _mode has changed since last time this method was called.
    {
        #ifdef DEBUGGING_LARGE
            std::cout << "readModeButton." << std::endl;
        #endif
    };
    void setModeChanged(bool isChanged)        // Sets _modeChanged.
    {
        #ifdef DEBUGGING_LARGE
            std::cout << "setModeChanged." << std::endl;
        #endif
    };
    
    bool readMicroSwitch()                     // Sets _microSwitchState. Changes _microSwitchChanged if _microSwitchState changes since
    {
        #ifdef DEBUGGING_LARGE
            std::cout << "readMicroSwitch." << std::endl;
        #endif
    };
    
    void setMicroSwitchChanged(bool isChanged) // Sets _microSwitchChanged.
    {
        #ifdef DEBUGGING_LARGE
            std::cout << "setMicroSwitchChanged." << std::endl;
        #endif
    };

    /**
     * @brief Used to clear the modeChanged "flag" to enable next change in mode.
     *      Should ONLY be used, when the change has been handled!
     */
    void resetModeChanged(void) 
    {
        #ifdef DEBUGGING_LARGE
            std::cout << "resetModeChanged." << std::endl;
        #endif
    }

    /**
     * @brief Used to clear the microSwitchChanged "flag" to enable next change in microswitch.
     *      Should ONLY be used, when the change has been handled!
     */
    void resetMicroSwitchChanged(void) 
    {
        #ifdef DEBUGGING_LARGE
            std::cout << "resetModeChanged." << std::endl;
        #endif  
    }
};