/**
 * @file WithoutSmartphoneFactory.cpp
 * @author Alexander Najbjerg Christensen (au482141@post.au.dk)
 * @brief This is the WithoutSmartphoneFactory implementation. The factory would be especially useful, 
 *        if the modules that are not used in this mode were instatiated to an object, 
 *        that is programmed to set the modules not used in a low-pwer-mode or even shut them down entirely.
 *        This is not the case in this project, and will instead simply do the same thing as the SmartphoneFactory.
 * @version 0.1
 * @date 2020-03-19
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include "../Include/WithoutSmartphoneFactory.h"
#include "../../Modules/CommunicationModule/Include/BluetoothFeather.h"
#include "../../Modules/ScannerModule/Include/RFIDRC522.h"
#include "../../Modules/SoundModule/Include/DFPlayerMini.h"

    /**
     * @brief This method creates a communication module object object for the case where no smartphone should be connected to funMRI.
     *        It would be prefered if this object took care of setting the module in some kind of low-power mode, as the communication module is not used here.
     * 
     * @return ICommunicationModule* is the pointer to the communication module object.
     */
    ICommunicationModule* WithoutSmartphoneFactory::createCommunicationModule(void)
    {
        return new BluetoothFeather();
    }

    /**
     * @brief This method creates a scanner module object object for the case where no smartphone should be connected to funMRI.
     * 
     * @return IScannerModule* is the pointer to the scanner module object.
     */
    IScannerModule* WithoutSmartphoneFactory::createScannerModule(void)
    {
        return new RFIDRC522(RFID_RST_PIN, RFID_SS_PIN);
    }


    /**
     * @brief This method creates a sound module object for the case where no smartphone should be connected to funMRI.
     * 
     * @return ISoundModule* is the pointer to the sound module object.
     */
    ISoundModule* WithoutSmartphoneFactory::createSoundModule(void)
    {
        new DFPlayerMini(SOMO_RX, SOMO_TX, SOMO_BAUDRATE);
    }

    /**
     * @brief This method creates a supply module object for the case where no smartphone should be connected to funMRI.
     * 
     * @return ISupplyModule* is the pointer to the supply module object.
     */
    ISupplyModule*  WithoutSmartphoneFactory::createSupplyModule(void)
    {
        // TODO --------------------------------------------------------------------------------------------
    }

    /**
     * @brief This method creates a User Interface module object for the case where no smartphone should be connected to funMRI.
     * 
     * @return IUserInterfaceModule* is the pointer to the user interface module object.
     */
    IUserInterfaceModule* WithoutSmartphoneFactory::createUserInterfaceModule(void)
    {
        // TODO --------------------------------------------------------------------------------------------
    }