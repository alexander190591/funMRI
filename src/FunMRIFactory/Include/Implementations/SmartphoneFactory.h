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

#include "../IFunMRIFactory.h"

/**
 * @brief Defines for Bluefruit Feather nRF52832
 * 
 */
#define SOMO_TX 7
#define SOMO_RX 11
#define SOMO_BAUDRATE 9600
#define LED_PIN LED_BUILTIN
#define RFID_SS_PIN 5
#define RFID_RST_PIN 4

class SmartphoneFactory : public IFunMRIFactory
{
    ICommunicationModule* createCommunicationModule(void);
    IScannerModule* createScannerModule(void);
    ISoundModule* createSoundModule(void);
    ISupplyModule*  createSupplyModule(void);
    IUserInterfaceModule* createUserInterfaceModule(void);
};

#endif // SMARTPHONEFACTORY_H_