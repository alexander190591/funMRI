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

#ifdef TEST_BUILD
    #include <iostream>
#endif

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
    _data = _funMRIFactory->createDataObject();

    _userInterfaceModule->supplyLEDOn();
}

FunMRI::~FunMRI()
{
    delete _funMRIFactory;
    delete _communicationModule;
    delete _scannerModule;
    delete _soundModule;
    delete _supplyModule;
    delete _userInterfaceModule;
    delete _state;
    delete _data;
}

/**
 * @brief Sets the state in the FunMRI object. Used for the State Pattern.
 * 
 * @param state is the object that controls what happens at this state.
 */
void FunMRI::setState(IState *state)
{
    delete _state;          // Garbage collecting
    _state = state;
}

/**
 * @brief Commands the scanner module to scan for an RFID ID.
 * 
 * @return true is returned if scanner has read an ID.
 * @return false is returned if scanner did NOT read an ID.
 */
bool FunMRI::scan(void)
{
    bool newScanAvailable = false;
    _scannerModule->scan();
    newScanAvailable = _scannerModule->isNewScanAvailable();

    if(newScanAvailable)
    {
        unsigned char IDTag[SIZE_OF_DATA_ARRAY - 1];
        for(int i = 0; i < SIZE_OF_DATA_ARRAY - 1; i++)
        {
            IDTag[i] = _scannerModule->retrieveResult()[i];
        }
        setNewID(IDTag);
    }

    return newScanAvailable;
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
    #ifdef DEBUGGING_SUBTLE
        std::cout << "Entered FunMRI.send()..." << std::endl;
    #endif

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
    /**
     * This method is currently aware of the exact size of the incoming data array. This is NOT generic.
     * To overcome this, an assignmentoperator should be implemented for both the IData object and the derived object.
     */
    
    #ifdef DEBUGGING_SUBTLE
        std::cout << "FunMRI.setData()..." << std::endl;
    #endif

    unsigned char incomingData[SIZE_OF_DATA_ARRAY];

    #ifdef DEBUGGING_LARGE
        std::cout << "calling data->getData(incomingData)" << std::endl;
    #endif

    data->getData(incomingData);

    #ifdef DEBUGGING_LARGE
        std::cout << "calling _data->setData(incomingData)" << std::endl;
    #endif

    _data->setData(incomingData);

    // *_data = *data; // This would work, if an assignmentoperator was implemented for both IData and the derived object...
    // std::cout << "Exited FunMRI.setData()." << std::endl;
}

/**
 * @brief Returns the data pointer stored in the FunMRI object.
 * 
 * @return IData* is the pointer to the object stored in the FunMRI object.
 */
IData* FunMRI::getData()
{
    return _data;
}

void FunMRI::getNewID(unsigned char* array)
{
    for(int i = 0; i < SIZE_OF_DATA_ARRAY - 1; i++)
    {
        array[i] = this->_newID[i];
    }
}

void FunMRI::setNewID(unsigned char* newID)
{
    for(int i = 0; i < SIZE_OF_DATA_ARRAY - 1; i++)
    {
        this->_newID[i] = newID[i];
    }
}

void FunMRI::storeInitID(unsigned char* initID)
{
    for(int i = 0; i < SIZE_OF_DATA_ARRAY - 1; i++)
    {
        this->_storedID[i] = initID[i];
    }
}

bool FunMRI::isIDSameAsInit(unsigned char newID[])
{
    bool isSame = false;
    // unsigned char dataArray[SIZE_OF_DATA_ARRAY];
    // _data->getData(dataArray);

    for(int i = 0; i < SIZE_OF_DATA_ARRAY-1; i++)
    {
        // if(dataArray[i+1] == newID[i])
        if(_storedID[i] == newID[i])
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
 * @brief Returns the state of the Mode button.
 * 
 * @return true == HIGH
 * @return false == LOW
 */
bool FunMRI::getMode(void) 
{
    return _userInterfaceModule->getMode();
}

/**
 * @brief Interrupt-method for when the microswitch on the funMRI has been pushed.
 * 
 */
void FunMRI::microSwitchPressed(void)
{
    _state->handleMicroSwitchPressed(this);
    _userInterfaceModule->resetMicroSwitchChanged();
}

/**
 * @brief Returns wether or not the microswitch has changed state.
 * 
 * @return true 
 * @return false 
 */
bool FunMRI::microSwitchChanged(void) 
{
    return _userInterfaceModule->microSwitchChanged();
}

/**
 * @brief Returns the state of the MicroSwitch.
 * 
 * @return true == HIGH
 * @return false == LOW
 */
bool FunMRI::getMicroSwitchState(void) 
{
    return _userInterfaceModule->getMicroSwitchState();
}

/**
 * @brief Used to clear the modeChanged "flag" to enable next change in mode.
 *      Should ONLY be used, when the change has been handled!
 */
void FunMRI::resetModeChanged(void) 
{
    _userInterfaceModule->resetModeChanged();
}

/**
 * @brief Used to clear the microSwitchChanged "flag" to enable next change in microswitch.
 *      Should ONLY be used, when the change has been handled!
 */
void FunMRI::resetMicroSwitchChanged(void) 
{
    _userInterfaceModule->resetMicroSwitchChanged();
}

bool FunMRI::isModeChanged(void) 
{
    return _userInterfaceModule->modeChanged();
}