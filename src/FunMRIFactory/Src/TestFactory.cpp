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

#include "../Include/TestFactory.h"

ICommunicationModule* TestFactory::createCommunicationModule(void)
{
    // This is where the dummy communicationmodule goes.
}

IScannerModule* TestFactory::createScannerModule(void)
{
    // This is where the dummy scanner module goes.
}

ISoundModule* TestFactory::createSoundModule(void)
{
    // This is where the dummy sound module goes.
}

ISupplyModule*  TestFactory::createSupplyModule(void)
{
    // This is where the dummy dummy supply module goes.
}

IUserInterfaceModule* TestFactory::createUserInterfaceModule(void)
{
    // This is where the dummy user interface module goes.
}