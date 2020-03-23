/**
 * @file BluetoothModule.cpp
 * @author TBA (au328752@post.au.dk)
 * This is the implementation for the HM-10 bluetooth module works with Arduino Nano
 * @version 1.1
 * @date 2020-03-18
 *
 * @copyright Copyright (c) 2020
 *
 */

#include "../Include/BluetoothModule.h"

	BluetoothModule::BluetoothModule()
	{
		// Nothing happens here.
	}

	BluetoothModule::~BluetoothModule()
	{
		delete _serialPtr;
	}

	/**
	 * Initiation function. Starts UART and checks that the Bluetooth module is turned on.
	 * @return Returns true if the Bluetooth Module is connected and has the name MR-Skanner. Else returns false.
	 */
	bool BluetoothModule::init()
	{
		Serial.println("calling new init");
		_serialPtr = new SoftwareSerial(BT_RX, BT_TX);

		_serialPtr->begin(BT_BAUDRATE);

		_serialPtr->print("AT+NAME?\n");
		String cmd = "";
		while (_serialPtr->available() == 0) {};		// OBS!!! Blocking call until UART has received stuff!

		cmd = _serialPtr->readString();

		bool isBtOn = false;
		if(cmd == "+NAME=MR-Skanner\r\n")
			isBtOn = true;

		return isBtOn;
	}

	/**
	 * Method for sending a string to the Bluetooth Module.
	 *
	 * If any device is connected via Bluetooth to the Bluetooth Module, the string is sent directly to the device connected.
	 * If no device is connected via Bluetooth to the Bluetooth Module, the string is sent as a command to the Bluetooth Module.
	 * @param cmd is the string to be sent to the Bluetooth Module.
	 */
	void BluetoothModule::sendData(IData* data)
	{
		unsigned char buf[SIZE_OF_DATA_ARRAY];
		data->getData(buf);
		_serialPtr->write(buf,SIZE_OF_DATA_ARRAY);
	}

	/**
	 * Waits for a message to be received from the Bluetooth Module.
	 * OBS! BLOCKING CALL!
	 * @return Response from the Bluetooth Device.
	 */

	void BluetoothModule::receiveData(IData* data)
	{
		char tmpArray[SIZE_OF_DATA_ARRAY + 1] = {0};
		char dataArray[SIZE_OF_DATA_ARRAY] = {0};

		while(_serialPtr->available())
		{
			_serialPtr->readBytes(tmpArray, SIZE_OF_DATA_ARRAY + 1);

			//Testing normal receive (OK)
			/*for(int i = 0; i < SIZE_OF_DATA_ARRAY;i++)
			{
				Serial.println(tmpArray[i]);
			}*/

			if(tmpArray[0] == 'D' || tmpArray[0] == 'M')
			{

				for(int i = 0; i < SIZE_OF_DATA_ARRAY; i++)
				{

					dataArray[i] = tmpArray[i];
				}
			}

		}

		data->setData((unsigned char*)dataArray);
	}

