#ifndef SERIALPRINTTESTFACTORY_H_
#define SERIALPRINTTESTFACTORY_H_

/**
 * @file SerialPrintTestFactory.h
 * @author Tobias Bach Aunboel (au328752@post.au.dk)
 * @brief Test factory for use with Arduino Nano (Serial Print)
 * @version 0.1
 * @date 2020-03-27
 *
 *
 */

#include "IFunMRIFactory.h"

#include "../../Modules/ScannerModule/Include/DummyScanner.h"
#include "../../Modules/CommunicationModule/Include/DummyCommunicationModule.h"
#include "../../Modules/SoundModule/include/DummySoundModule.h"
#include "../../Modules/SupplyModule/Include/DummySupplyModule.h"
#include "../../Modules/UserInterfaceModule/Include/DummyUserInterface.h"

class SerialPrintTestFactory : public IFunMRIFactory
{
public:
    SerialPrintTestFactory(){Serial.println("SerialPrintTestFactory: Constructor.");};
    ~SerialPrintTestFactory(){Serial.println("SerialPrintTestFactory: Destructor.");};
    ICommunicationModule* createCommunicationModule(void);
    IScannerModule* createScannerModule(void);
    ISoundModule* createSoundModule(void);
    ISupplyModule*  createSupplyModule(void);
    IUserInterfaceModule* createUserInterfaceModule(void);
    virtual IData* createDataObject(void);
};

#endif // SMARTPHONEFACTORY_H_