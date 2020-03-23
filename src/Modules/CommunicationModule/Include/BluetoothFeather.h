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

#ifndef BLUETOOTHFEATHER_H_
#define BLUETOOTHFEATHER_H_
#include "ICommunicationModule.h"
#include "../../../Protocol/Include/Data.h"

class BluetoothFeather : public ICommunicationModule
{
public:
	BluetoothFeather();
	bool init();
	void sendData(IData* data);
	void receiveData(IData* data);
};

#endif /* BLUETOOTHMODULE_HM_10_BLUETOOTHMODULE_H_ */