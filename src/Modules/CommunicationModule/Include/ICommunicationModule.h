/*
 * ICommunicationModule.h
 *
 *  Created on: 29. jan. 2020
 *      Author: Alexander
 */

#ifndef ICOMMUNICATIONMODULE_H_
#define ICOMMUNICATIONMODULE_H_
#include "../../../Protocol/Include/Data.h"

	class ICommunicationModule {
	public:
		virtual bool init() = 0;
		virtual void sendData(Data& data) = 0;
		virtual void receiveData(Data& data);
	};

#endif /* BLUETOOTHMODULE_HM_10_ICOMMUNICATIONMODULE_H_ */
