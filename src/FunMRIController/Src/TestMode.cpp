/**
 * @file TestMode.cpp
 * @author Alexander Najbjerg Christensen (au482141@post.au.dk)
 * @brief 
 * @version 0.1
 * @date 2020-03-29
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include "../Include/TestMode.h"
#include "../../FunMRIFactory/Include/TestFactory.h"

#ifdef TEST_BUILD
    #include <iostream>
#endif

TestMode::TestMode()
{
    _funMRI = new FunMRI(new TestFactory());
    //_funMRI->setState(???????);
}

TestMode::~TestMode()
{
    delete _funMRI;
}

/**
 * @brief This is the Main() for the entire test.
 * 
 */
void TestMode::run()
{
    #ifdef DEBUGGING_SUBTLE
        std::cout << "TestMode.run entered..." << std::endl;
    #endif
    // while(1) // This is the main loop for Without Smartphone mode
    // {

    //     //_funMRI->receive();
    // }
}

/**
 * @brief Sets a bool value corresponding to a micro switch interrupt made on a change in value.
 *        OBS: Should be reset when handled, as a new interrupt should be able to happen!
 * 
 * @param isChanged is set to true if an interrupt has just happened.
 */
void TestMode::setmicroSwitchChanged(bool isChanged) 
{
    _microSwitchChanged = isChanged;
}

/**
 * @brief Sets the state of the micro switch (pressed/not pressed) as a bool value.
 * 
 * @param isPressed corresponds to the value read on the digital pin connected to the micro switch.
 */
void TestMode::setMicroSwitchState(bool isPressed) 
{
    _microSwitchState = isPressed;
}