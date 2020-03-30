/**
 * @file TestMode.cpp
 * @author Alexander Najbjerg Christensen (au482141@post.au.dk)
 * @brief This is the implementation of the funMRI controller test class for "Without smartphone".
 * @version 0.1
 * @date 2020-03-29
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include "../Include/TestModeWithoutSmartphone.h"
#include "../../FunMRIFactory/Include/TestFactory.h"
#include "../../State/Include/IdleState.h"


#ifdef TEST_BUILD
    #include <iostream>
#endif

TestModeWithoutSmartphone::TestModeWithoutSmartphone()
{
    _funMRI = new FunMRI(new TestFactory());
    _funMRI->setState(new IdleState());
}

TestModeWithoutSmartphone::~TestModeWithoutSmartphone()
{
    delete _funMRI;
}

/**
 * @brief This is the Main() for the entire test. It does NOT have a while-loop. Is run once per test.
 * 
 */
void TestModeWithoutSmartphone::run()
{
    #ifdef DEBUGGING_SUBTLE
        std::cout << "TestModeWithoutSmartphone.run entered..." << std::endl;
    #endif

    if(_microSwitchState && _microSwitchChanged)
        _funMRI->microSwitchPressed();
}

/**
 * @brief Sets a bool value corresponding to a micro switch interrupt made on a change in value.
 *        OBS: Should be reset when handled, as a new interrupt should be able to happen!
 * 
 * @param isChanged is set to true if an interrupt has just happened.
 */
void TestModeWithoutSmartphone::setMicroSwitchChanged(bool isChanged) 
{
    _microSwitchChanged = isChanged;
}

/**
 * @brief Sets the state of the micro switch (pressed/not pressed) as a bool value.
 * 
 * @param isPressed corresponds to the value read on the digital pin connected to the micro switch.
 */
void TestModeWithoutSmartphone::setMicroSwitchState(bool isPressed) 
{
    _microSwitchState = isPressed;
}