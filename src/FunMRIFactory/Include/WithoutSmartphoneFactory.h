#ifndef WITHOUTSMARTPHONEFACTORY_H_
#define WITHOUTSMARTPHONEFACTORY_H_

/**
 * @file WithoutSmartphoneFactory.h
 * @author Alexander Najbjerg Christensen (au482141@post.au.dk)
 * @brief This is the header for the factory that creates the modules for the funMRI that is used without smartphone.
 * @version 0.1
 * @date 2020-03-18
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include "IFunMRIFactory.h"

class WithoutSmartphoneFactory : public IFunMRIFactory
{
    ICommunicationModule* createCommunicationModule(void);
    IScannerModule* createScannerModule(void);
    ISoundModule* createSoundModule(void);
    ISupplyModule*  createSupplyModule(void);
    IUserInterfaceModule* createUserInterfaceModule(void);
};

#endif // WITHOUTSMARTPHONEFACTORY_H_