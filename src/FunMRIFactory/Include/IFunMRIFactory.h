#ifndef IFUNMRIFACTORY_H_
#define IFUNMRIFACTORY_H_

/**
 * @file IFunMRIFactory.h
 * @author Alexander Najbjerg Christensen (au482141@post.au.dk)
 * @brief This is the interface for the FunMRIFactory.
 * @version 0.1
 * @date 2020-03-18
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include "../../Modules/CommunicationModule/Include/ICommunicationModule.h"
#include "../../Modules/ScannerModule/Include/IScannerModule.h"
#include "../../Modules/SoundModule/Include/ISoundModule.h"
#include "../../Modules/SupplyModule/Include/ISupplyModule.h"
#include "../../Modules/UserInterfaceModule/Include/IUserInterfaceModule.h"

class IFunMRIFactory
{
public:
    virtual ICommunicationModule* createCommunicationModule(void) = 0;
    virtual IScannerModule* createScannerModule(void) = 0;
    virtual ISoundModule* createSoundModule(void) = 0;
    virtual ISupplyModule*  createSupplyModule(void) = 0;
    virtual IUserInterfaceModule* createUserInterfaceModule(void) = 0;
};

#endif // IFUNMRIFACTORY_H_