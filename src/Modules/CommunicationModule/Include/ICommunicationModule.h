/*
 * ICommunicationModule.h
 *
 *  Created on: 29. jan. 2020
 *      Author: Alexander
 */

#ifndef ICOMMUNICATIONMODULE_H_
#define ICOMMUNICATIONMODULE_H_

	class ICommunicationModule {
	public:
		virtual bool init() = 0;
		//virtual void sendCmd(String cmd) = 0;
		//virtual String receiveCmd();
	};

#endif /* BLUETOOTHMODULE_HM_10_ICOMMUNICATIONMODULE_H_ */
