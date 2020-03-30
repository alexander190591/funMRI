/**
 * @file DummyCommunicationModule.h
 * @author TBA (au328752@post.au.dk)
 * This is the test implementation for CommunicationModule used with SerialPrint
 * @version 1.1
 * @date 2020-03-27
 *
 * @copyright Copyright (c) 2020
 *
 */

#ifndef BLUETOOTHMODULE_HM_10_BLUETOOTHMODULE_H_
#define BLUETOOTHMODULE_HM_10_BLUETOOTHMODULE_H_
#include "../../CommunicationModule/Include/ICommunicationModule.h"
#include "../../../Protocol/Include/Data.h"
#include <SoftwareSerial.h>
#include <Arduino.h>



class DummyCommunicationModule : public ICommunicationModule
{
public:
	DummyCommunicationModule()
    {
        Serial.println("DummyCommunicationModule: Constructor"); 
        this->init();
    };
	bool init()
    {
        Serial.println("DummyCommunicationModule: init()");
        return true;
    };
	void sendData(IData* data)
    {
        Serial.println("DummyCommunicationModule: sendData()");
    };
	void receiveData(IData* data)
    {
        Serial.println("DummyCommunicationModule: receiveData()");
    };
	~DummyCommunicationModule()
    {
        Serial.println("DummyCommunicationModule: destructor");
    };

private:
	SoftwareSerial* _serialPtr = nullptr;
};



#endif /* BLUETOOTHMODULE_HM_10_BLUETOOTHMODULE_H_ */
