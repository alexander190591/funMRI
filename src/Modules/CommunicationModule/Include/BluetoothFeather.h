#ifndef __BLUETOOTHFEATHER_H__
#define __BLUETOOTHFEATHER_H__

/**
 * @file BluetoothFeather.h
 * @author Alexander Najbjerg Christensen (au482141@post.au.dk)
 * @brief This is the Header file for the Bluetooth Module embedded in the Bluefruit Feather nRF.
 * 			It needs to communicate with the Arduino through the Serial-pins.
 * 			On the Bluefruit Feather, these are the RX and the TX pins.
 * @version 0.1
 * @date 2020-03-18
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include "ICommunicationModule.h"
#include "../../../Protocol/Include/Data.h"

class BluetoothFeather : public ICommunicationModule
{
public:
	BluetoothFeather();
	~BluetoothFeather();
	bool init();
	void sendData(IData* data);
	void receiveData(IData* data);
};

#endif // __BLUETOOTHFEATHER_H__