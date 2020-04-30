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

    while(!(_funMRI->isModeChanged()))
    {
        if(_funMRI->getMicroSwitchState() && _funMRI->microSwitchChanged())
        {
            #ifdef DEBUGGING_LARGE
                std::cout << "Calling _funMRI->microSwitchPressed()" << std::endl;
            #endif
            _funMRI->microSwitchPressed();
        }
    }
    
    #ifdef DEBUGGING_LARGE
        std::cout << "Mode has changed. Now leaving run()..." << std::endl;
    #endif
}

