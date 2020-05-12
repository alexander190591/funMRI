/**
 * @file UserInterfaceModule.cpp
 * @author Alexander Najbjerg Christensen (au482141@post.au.dk)
 * @brief 
 * @version 0.1
 * @date 2020-04-30
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include "../include/UserInterfaceModule.h"
#include <Arduino.h>
#include "../../../defines.h"

/**
 * @brief Construct a new User Interface Module:: User Interface Module object.
 * Sets the two pins, MODE_PIN and MICROSWITCH_PIN as INPUT pins.
 * The pin numbers are defined in main.
 * 
 */
UserInterfaceModule::UserInterfaceModule(bool madeInSmartphoneMode) 
{
    _mode = madeInSmartphoneMode;
    pinMode(MODE_PIN, INPUT);
    pinMode(MICROSWITCH_PIN, INPUT);
    pinMode(LED_PIN, OUTPUT);
    supplyLEDOn();
}

/**
 * @brief Checks if the microswitch state has changed by reading the MICROSWITCH_PIN. Returns the microSwitchChanged "flag".
 * 
 * @return true if microSwitch state has changed resently.
 * @return false if microSwitch state has not changed resently.
 */
bool UserInterfaceModule::microSwitchChanged() 
{
    readMicroSwitch();
    return _microSwitchChanged;
}

/**
 * @brief Returns the state of the microswitch.
 * 
 * @return true if MICROSWITCH_PIN == HIGH
 * @return false if MICROSWITCH_PIN == LOw
 */
bool UserInterfaceModule::getMicroSwitchState() 
{
    bool microswitchstate = readMicroSwitch();
    #ifdef UART_BUILD
        Serial.print("getMicroSwitchState returned: "); Serial.println(microswitchstate);
    #endif UART_BUILD
    
    return microswitchstate;
}

/**
 * @brief Checks if the mode has changed by reading the MODE_PIN. Returns the modeChanged "flag".
 * 
 * @return true if the mode has changed resently.
 * @return false if the mod has not changed resently.
 */
bool UserInterfaceModule::modeChanged() 
{
    readModeButton();
    return _modeChanged;
}

/**
 * @brief returns the state of the mode button.
 * 
 * @return true if MODE_PIN == HIGH
 * @return false if MODE_PIN == LOW
 */
bool UserInterfaceModule::getMode() 
{
    readModeButton();
    return _mode;
}

/**
 * @brief Turns on the supply LED.
 * 
 */
void UserInterfaceModule::supplyLEDOn() 
{
    digitalWrite(LED_PIN, HIGH);
}

/**
 * @brief Makes the supply LED blink (Used for charging).
 * 
 */
void UserInterfaceModule::supplyLEDblink() 
{
    // PWM mode not implemented yet.......
}

/**
 * @brief Turns off the supply LED
 * 
 */
void UserInterfaceModule::supplyLEDOff() 
{
    digitalWrite(LED_PIN, LOW);
}

/**
 * @brief Private method for setting the modeChanged "flag".
 * 
 * @param isChanged set to true if the mode has changed.
 */
void UserInterfaceModule::setModeChanged(bool isChanged) 
{
    _modeChanged = isChanged;
    #ifdef UART_BUILD
        Serial.print("UserInterfaceModule.setModeChanged: _modeChanged == "); Serial.println(_modeChanged);
    #endif UART_BUILD
    }

/**
 * @brief Sets _mode. Changes _modeChanged if _mode has changed since last time this method was called.
 * 
 * @return true if MODE_PIN == HIGH
 * @return false if MODE_PIN == LOW
 */
bool UserInterfaceModule::readModeButton() 
{
    bool tmpMode = digitalRead(MODE_PIN);
    if(_mode != tmpMode)
    {
        #ifdef UART_BUILD
            Serial.println("UserInterfaceModule.readModeButton: SIGNAL HAS CHANGED!");
  		#endif UART_BUILD
        
        setModeChanged(true);
    }
    _mode = tmpMode;

    #ifdef UART_BUILD
        Serial.print("readModeButton returns _mode: "); Serial.println(_mode);
    #endif UART_BUILD
    
    return _mode;
}

/**
 * @brief Sets _microSwitchState. Changes _microSwitchChanged if _microSwitchState changes since this method was called.
 * 
 * @return true if MICROSWITCH_PIN == HIGH
 * @return false if MICROSWITCH_PIN == LOW
 */
bool UserInterfaceModule::readMicroSwitch() 
{
    bool tmpMicroSwitchState = digitalRead(MICROSWITCH_PIN);
    if(_microSwitchState != tmpMicroSwitchState)
    {
        #ifdef UART_BUILD
            Serial.println("UserInterfaceModule.readMicroSwitch: SIGNAL HAS CHANGED!");
  		#endif UART_BUILD
        
        setMicroSwitchChanged(true);
    }
    _microSwitchState = tmpMicroSwitchState;

    #ifdef UART_BUILD
        Serial.print("readMicroSwitch returns _microSwitchState: "); Serial.println(_microSwitchState);
    #endif UART_BUILD
    
    return _microSwitchState;
}

/**
 * @brief Sets a bool value corresponding to a micro switch change made on a change in value.
 *        OBS: Should be reset (resetModeChanged()) when handled, as a new change should be able to happen!
 * 
 * @param isChanged is set to true if mode change has just happened.
 */
void UserInterfaceModule::setMicroSwitchChanged(bool isChanged) 
{
    _microSwitchChanged = isChanged;
}

/**
 * @brief Used to clear the modeChanged "flag" to enable next change in mode.
 *      Should ONLY be used, when the change has been handled!
 */
void UserInterfaceModule::resetModeChanged(void) 
{
    _modeChanged = false;
}

/**
 * @brief Used to clear the microSwitchChanged "flag" to enable next change in microswitch.
 *      Should ONLY be used, when the change has been handled!
 */
void UserInterfaceModule::resetMicroSwitchChanged(void) 
{
    _microSwitchChanged = false;   
}