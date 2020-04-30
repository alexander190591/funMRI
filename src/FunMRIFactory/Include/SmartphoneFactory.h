#ifndef SMARTPHONEFACTORY_H_
#define SMARTPHONEFACTORY_H_

/**
 * @file SmartphoneFactory.h
 * @author Alexander Najbjerg Christensen (au482141@post.au.dk)
 * @brief This is the header for the factory that creates the modules for the funMRI that is used with smartphone.
 * @version 0.1
 * @date 2020-03-18
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include "IFunMRIFactory.h"
#include "../../defines.h"

class SmartphoneFactory : public IFunMRIFactory
{
public:
    SmartphoneFactory();
    ~SmartphoneFactory();
    ICommunicationModule* createCommunicationModule(void);
    IScannerModule* createScannerModule(void);
    ISoundModule* createSoundModule(void);
    ISupplyModule*  createSupplyModule(void);
    IUserInterfaceModule* createUserInterfaceModule(void);
    IData* createDataObject(void);
};

#endif // SMARTPHONEFACTORY_H_