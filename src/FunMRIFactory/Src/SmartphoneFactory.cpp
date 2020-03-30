/**
 * @file SmartphoneFactory.cpp
 * @author Alexander Najbjerg Christensen (au482141@post.au.dk)
 * @brief This is the SmartphoneFactory. It instatiates the modules needed for a functional funMRI,
 *        that can communicate with a smartphone.
 * @version 0.1
 * @date 2020-03-18
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include "../Include/SmartphoneFactory.h"
#include "../../Modules/CommunicationModule/Include/BluetoothFeather.h"
#include "../../Modules/ScannerModule/Include/RFIDRC522.h"
#include "../../Modules/SoundModule/Include/DFPlayerMini.h"

// FOR TESTING:
#include "../../Modules/SoundModule/Include/DummySoundModule.h"

    SmartphoneFactory::SmartphoneFactory()
    {
        // Nothing to do...
    }

    SmartphoneFactory::~SmartphoneFactory()
    {
        // Nothing to delete...
    }
    
    ICommunicationModule* SmartphoneFactory::createCommunicationModule(void)
    {
        return new BluetoothFeather();
    }

    IScannerModule* SmartphoneFactory::createScannerModule(void)
    {
        return new RFIDRC522(RFID_RST_PIN, RFID_SS_PIN);
    }

    ISoundModule* SmartphoneFactory::createSoundModule(void)
    {
        //return new DummySoundModule();
        // TODO ERROR IN THIS RETURN........... MAKES THE MICROCONTROLLER STOP!!!
        return new DFPlayerMini(SOMO_RX, SOMO_TX, SOMO_BAUDRATE);
    }

    ISupplyModule*  SmartphoneFactory::createSupplyModule(void)
    {
        return nullptr;
        // TODO --------------------------------------------------------------------------------------------
    }

    IUserInterfaceModule* SmartphoneFactory::createUserInterfaceModule(void)
    {
        return nullptr;
        // TODO --------------------------------------------------------------------------------------------
    }

    IData* SmartphoneFactory::createDataObject(void)
    {
        return new Data();
    }