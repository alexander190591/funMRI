/**
 * @file TestFactory.cpp
 * @author Alexander Najbjerg Christensen (au482141@post.au.dk)
 * @brief This is the TestFactory. It instatiates the modules needed for a testable funMRI without any actual hardware modules.
 * @version 0.1
 * @date 2020-03-18
 * 
 * @copyright Copyright (c) 2020
 * 
 */


#include "../Include/Implementations/TestFactory.h"
#include "../../Modules/CommunicationModule/Include/CommunicationDummyTest.h"
#include "../../Modules/ScannerModule/Include/DummyScannerTest.h"
#include "../../Modules/SoundModule/Include/SoundDummyTest.h"
#include "../../Modules/SupplyModule/Include/SupplyDummyTest.h"
#include "../../Modules/UserInterfaceModule/Include/UserInterfaceDummyTest.h"

#ifdef TEST_BUILD
    #include <iostream>
#endif

TestFactory::TestFactory()
{
    #ifdef DEBUGGING_LARGE
        std::cout << "TestFactory: Constructor." << std::endl;
    #endif
    // Nothing too delete... Everything sent to FunMRI and deleted in that destructor.
}

TestFactory::~TestFactory()
{
    #ifdef DEBUGGING_LARGE
        std::cout << "TestFactory: Destructor." << std::endl;
    #endif
    // Nothing too delete... Everything sent to FunMRI and deleted in that destructor.
}

ICommunicationModule* TestFactory::createCommunicationModule(void)
{
    return new CommunicationDummyTest();
}

IScannerModule* TestFactory::createScannerModule(void)
{
    return new DummyScannerTest();
}

ISoundModule* TestFactory::createSoundModule(void)
{
    return new SoundDummyTest();
}

ISupplyModule*  TestFactory::createSupplyModule(void)
{
    return new SupplyDummyTest();
}

IUserInterfaceModule* TestFactory::createUserInterfaceModule(void)
{
    return new UserInterfaceDummyTest();
}

IData* TestFactory::createDataObject(void)
{
    return new Data();
}