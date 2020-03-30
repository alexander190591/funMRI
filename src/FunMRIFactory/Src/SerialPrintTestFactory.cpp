    #include "../Include/Implementations/SerialPrintTestFactory.h"
    
    
    ICommunicationModule* SerialPrintTestFactory::createCommunicationModule(void)
    {
        return new DummyCommunicationModule();
    }

    IScannerModule* SerialPrintTestFactory::createScannerModule(void)
    {
        return new DummyScanner();
    }
    
    ISoundModule* SerialPrintTestFactory::createSoundModule(void)
    {
        //return new DummySoundModule();
        return new DFPlayerMini(0, 1, 9600);
    }

    ISupplyModule* SerialPrintTestFactory::createSupplyModule(void)
    {
        return new DummySupplyModule();
    }

    IUserInterfaceModule* SerialPrintTestFactory::createUserInterfaceModule(void)
    {
        return new DummyUserInterface();
    }