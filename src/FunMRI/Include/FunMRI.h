#include "../../Modules/ScannerModule/include/IScannerModule.h"
#include "../../Modules/SoundModule/include/ISoundModule.h"
#include "../../Modules/BatteryModule/Include/ISupplyModule.h"
#include "../../Modules/CommunicationModule/Include/ICommunicationModule.h"
#include <Arduino.h>

class FunMRI
{
public:
    //void setState(&State);
    void scan(void);
    void playSound(void);
    void send(String msg);
    String receive(void);
    void chargingStatus(void);
private:
    //IUserInterface* _userInterface = nullptr;
    ISupplyModule* _supplyModule = nullptr;
    IScannerModule* _scannerModule = nullptr;
    ICommunicationModule* _communicationModule = nullptr;
    ISoundModule* _soundModule = nullptr;
    //IData* _data = nullptr;
    //State* _state = nullptr;
};