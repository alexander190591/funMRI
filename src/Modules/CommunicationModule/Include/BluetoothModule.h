#ifndef __BLUETOOTHMODULE_H__
#define __BLUETOOTHMODULE_H__

/**
 * @file BluetoothModule.h
 * @author TBA (au328752@post.au.dk)
 * This is the implementation for the HM-10 bluetooth module works with Arduino Nano
 * @version 1.1
 * @date 2020-03-18
 *
 * @copyright Copyright (c) 2020
 *
 */

#include "../../CommunicationModule/Include/ICommunicationModule.h"
#include "../../../Protocol/Include/Data.h"
#include <SoftwareSerial.h>
#include <Arduino.h>

#define BT_RX 7
#define BT_TX 8
#define BT_BAUDRATE 9600


class BluetoothModule : public ICommunicationModule
{
public:
	BluetoothModule();
	bool init();
	void sendData(IData* data);
	void receiveData(IData* data);
	~BluetoothModule();

private:
	SoftwareSerial* _serialPtr = nullptr;
};

#endif // __BLUETOOTHMODULE_H__