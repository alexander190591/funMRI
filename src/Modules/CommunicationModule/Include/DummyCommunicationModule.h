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
        #ifdef UART_BUILD
            Serial.println("DummyCommunicationModule: Constructor"); 
        #endif UART_BUILD
        
        this->init();
    };
	bool init()
    {
        #ifdef UART_BUILD
            Serial.println("DummyCommunicationModule: init()");
        #endif UART_BUILD
        
        return true;
    };
	void sendData(IData* data)
    {
        #ifdef UART_BUILD
            Serial.println("DummyCommunicationModule: sendData()");
        #endif UART_BUILD
    };
	void receiveData(IData* data)
    {
        #ifdef UART_BUILD
            Serial.println("DummyCommunicationModule: receiveData()");
        #endif UART_BUILD
    };
	~DummyCommunicationModule()
    {
        #ifdef UART_BUILD
            Serial.println("DummyCommunicationModule: destructor");
        #endif UART_BUILD
    };

private:
	SoftwareSerial* _serialPtr = nullptr;
};



#endif /* BLUETOOTHMODULE_HM_10_BLUETOOTHMODULE_H_ */
