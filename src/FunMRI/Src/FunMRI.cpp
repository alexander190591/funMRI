/**
 * @file FunMRI.cpp
 * @author Alexander Najbjerg Christensen (au482141@post.au.dk)
 * @brief This class controls everything. It's the class that keeps track of all modules, 
 *        all high level commands, keeps track of the state and the protocol.
 * @version 0.1
 * @date 2020-03-20
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include "../../Modules/ScannerModule/include/IScannerModule.h"
#include "../../Modules/SoundModule/include/ISoundModule.h"
#include "../../Modules/SupplyModule/Include/ISupplyModule.h"
#include "../../Modules/CommunicationModule/Include/ICommunicationModule.h"
#include "../../Protocol/Include/Data.h"
#include "../../State/Include/IState.h"
#include "../../Modules/UserInterfaceModule/Include/IUserInterfaceModule.h"
#include "../../FunMRIFactory/Include/IFunMRIFactory.h"

/**
 * @brief Construct a new funMRI object.
 * 
 * @param funMRIFactory is the factory that creates the other objects controlled by funMRI.
 */
FunMRI::FunMRI(IFunMRIFactory* funMRIFactory)
{
    _funMRIFactory = funMRIFactory;
    _communicationModule = _funMRIFactory->createCommunicationModule();
    _scannerModule = _funMRIFactory->createScannerModule();
    _soundModule = _funMRIFactory->createSoundModule();
    _supplyModule = _funMRIFactory->createSupplyModule();
    _userInterfaceModule = _funMRIFactory->createUserInterfaceModule();
}

FunMRI::~FunMRI()
{
    delete _funMRIFactory;
    delete _communicationModule;
    delete _scannerModule;
    delete _soundModule;
    delete _supplyModule;
    delete _userInterfaceModule;
}

/**
 * @brief Sets the state in the FunMRI object. Used for the State Pattern.
 * 
 * @param state is the object that controls what happens at this state.
 */
void FunMRI::setState(IState *state)
{
    _state = state;
}

/**
 * @brief Commands the scanner module to scan for an RFID ID.
 * 
 */
void FunMRI::scan(void)
{
    _scannerModule->scan();
}

/**
 * @brief Commands the sound module to play the MRI sound.
 * 
 */
void FunMRI::playSound(void)
{
    _soundModule->playSound();
}

/**
 * @brief Commands the communication module to send the data stored in the Data object.
 *        OBS! This method also updates the data stored in the FunMRI::IData-object.
 * 
 * @param data object is the object containing the data/message sent. See Data.h for protocol.
 */
void FunMRI::send(IData* data)
{
    setData(data);
    _communicationModule->sendData(_data);
}

/**
 * @brief Commands the communication module to receive the data if any has been sent to the communication module.
 * 
 * @param [out] data is the output parameter object in which the data/message received is stored. 
 */
void FunMRI::receive()
{
    _communicationModule->receiveData(_data);
}

/**
 * @brief Setting the data object stored in the FunMRI object. Should be called before send() is called.
 * 
 * @param data is the data object that contains the value to be stored in FunMRI.
 */
void FunMRI::setData(IData* data)
{
    *_data = *data;
}

/**
 * @brief Returns the data object stored in the FunMRI object.
 * 
 * @return Data is the object stored in the FunMRI object. Returned by value.
 */
IData* FunMRI::getData()
{
    return _data;
}

bool FunMRI::isIDSameAsInit(unsigned char newID[])
{
    bool isSame = false;
    unsigned char dataArray[SIZE_OF_DATA_ARRAY];
    _data->getData(dataArray);

    for(int i = 0; i < SIZE_OF_DATA_ARRAY-1; i++)
    {
        if(dataArray[i+1] == newID[i])
            isSame = true;
        else
        {
            isSame = false;
            break;
        }
    }
    return isSame;
}

/**
 * @brief Reads the status of the battery.
 * 
 */
void FunMRI::batteryStatus(void)
{
    //_supplyModule->MilliVoltToPercentage(_supplyModule->readBatteryVoltage()); Stuff should happen here...
}

/**
 * @brief Interrupt-method for when the init button on funMRI App has been pressed.
 * 
 */
void FunMRI::initPressed(void)
{
    _state->handleInitPressed(this);
}

/**
 * @brief Interrupt-method for when the scan button oon funMRI App has been pressed.
 * 
 */
void FunMRI::scanPressed(void)
{
    _state->handleScanPressed(this);
}

/**
 * @brief Interrupt-method for when the mode-switch on funMRI has been switched.
 * 
 */
void FunMRI::modeChanged(void)
{
    _state->handleModeChanged(this);
}

/**
 * @brief Interrupt-method for when the microswitch on the funMRI has been pushed.
 * 
 */
void FunMRI::microSwitchPressed(void)
{
    _state->handleMicroSwitchPressed(this);
}