/*
 * ICommunicationModule.h
 *
 *  Created on: 29. jan. 2020
 *      Author: Alexander
 */

#ifndef ICOMMUNICATIONMODULE_H_
#define ICOMMUNICATIONMODULE_H_
#include "../../../Protocol/Include/IData.h"

	class ICommunicationModule {
	public:
	 	virtual ~ICommunicationModule() {/*Nothing to delete*/}
		virtual bool init() = 0;
		virtual void sendData(IData* data) = 0;
		virtual void receiveData(IData* data) = 0;
	};

#endif /* BLUETOOTHMODULE_HM_10_ICOMMUNICATIONMODULE_H_ */
