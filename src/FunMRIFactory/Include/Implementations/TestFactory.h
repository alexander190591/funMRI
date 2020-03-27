#ifndef TESTFACTORY_H_
#define TESTFACTORY_H_

/**
 * @file TestFactory.h
 * @author Alexander Najbjerg Christensen (au482141@post.au.dk)
 * @brief This is the header for the factory that creates the Dummy modules for the funMRI that is used for testing purposes.
 * @version 0.1
 * @date 2020-03-18
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include "../IFunMRIFactory.h"

class TestFactory : public IFunMRIFactory
{
public:
    TestFactory();
    ~TestFactory();
    ICommunicationModule* createCommunicationModule(void);
    IScannerModule* createScannerModule(void);
    ISoundModule* createSoundModule(void);
    ISupplyModule*  createSupplyModule(void);
    IUserInterfaceModule* createUserInterfaceModule(void);
    IData* createDataObject(void);
};

#endif // TESTFACTORY_H_