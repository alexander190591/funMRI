/*
 * BluetoothFeather.h
 * This is the Header file for the Bluetooth Module embedded in the Bluefruit Feather nRF.
 * It needs to communicate with the Arduino through the Serial-pins.
 * On the Arduino Nano, these are the RX0 and the TX1 pins.
 *
 *  Created on: 29. jan. 2020
 *      Author: Alexander
 */

#ifndef BLUETOOTHFEATHER_H_
#define BLUETOOTHFEATHER_H_
#include "../../CommunicationModule/Include/ICommunicationModule.h"
#include <Arduino.h>

class BluetoothFeather : public ICommunicationModule
{
public:
	BluetoothFeather();
	bool init();
	void sendCmd(String cmd);
	String receiveCmd();
};



#endif /* BLUETOOTHMODULE_HM_10_BLUETOOTHMODULE_H_ */