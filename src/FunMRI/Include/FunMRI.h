#ifndef __FUNMRI_H__
#define __FUNMRI_H__

/**
 * @file FunMRI.h
 * @author Alexander Najbjerg Christensen (au482141@post.au.dk)
 * @brief This class controls everything. It's the class that keeps track of all modules, 
 *        all high level commands, keeps track of the state and the protocol.
 * @version 0.1
 * @date 2020-03-18
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include "../../../src/build_defines.h"
#include "../../Modules/ScannerModule/include/IScannerModule.h"
#include "../../Modules/SoundModule/include/ISoundModule.h"
#include "../../Modules/SupplyModule/Include/ISupplyModule.h"
#include "../../Modules/CommunicationModule/Include/ICommunicationModule.h"
#include "../../Protocol/Include/IData.h"
#include "../../State/Include/IState.h"
#include "../../Modules/UserInterfaceModule/Include/IUserInterfaceModule.h"
#include "../../FunMRIFactory/Include/IFunMRIFactory.h"

class IState; // Forward declaration...  https://stackoverflow.com/questions/396084/headers-including-each-other-in-c

class FunMRI
{
public:
    FunMRI(IFunMRIFactory* funMRIFactory);
    ~FunMRI();
    void setState(IState *state);
    bool scan(void);
    void playSound(void);
    void send(IData* data);
    void receive();
    void setData(IData* data);
    IData* getData();
    void getNewID(unsigned char* array);
    void setNewID(unsigned char* newID);
    void storeInitID(unsigned char* initID);
    bool isIDSameAsInit(unsigned char* newID);
    void batteryStatus(void);
    void initPressed(void);
    void scanPressed(void);
    void modeChanged(void);
    bool isModeChanged(void);
    void resetModeChanged(void);
    bool getMode(void);
    void microSwitchPressed(void);
    bool microSwitchChanged(void);
    void resetMicroSwitchChanged(void);
    bool getMicroSwitchState(void);
private:
    IFunMRIFactory* _funMRIFactory = nullptr;
    IUserInterfaceModule* _userInterfaceModule = nullptr;
    ISupplyModule* _supplyModule = nullptr;
    IScannerModule* _scannerModule = nullptr;
    ICommunicationModule* _communicationModule = nullptr;
    ISoundModule* _soundModule = nullptr;
    IState* _state = nullptr;
    IData* _data = nullptr;
    unsigned char _storedID[7];
    unsigned char _newID[7];
};


#endif // __FUNMRI_H__