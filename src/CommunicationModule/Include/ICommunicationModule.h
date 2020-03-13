/*
 * ICommunicationModule.h
 *
 *  Created on: 29. jan. 2020
 *      Author: Alexander
 */

#ifndef BLUETOOTHMODULE_HM_10_ICOMMUNICATIONMODULE_H_
#define BLUETOOTHMODULE_HM_10_ICOMMUNICATIONMODULE_H_
#include <Arduino.h>

	class ICommunicationModule {
	public:
		virtual bool init() = 0;
		virtual void sendCmd(String cmd) = 0;
		virtual String receiveCmd();
	};

#endif /* BLUETOOTHMODULE_HM_10_ICOMMUNICATIONMODULE_H_ */
