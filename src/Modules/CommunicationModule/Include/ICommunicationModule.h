#ifndef __ICOMMUNICATIONMODULE_H__
#define __ICOMMUNICATIONMODULE_H__

/*
 * ICommunicationModule.h
 *
 *  Created on: 29. jan. 2020
 *      Author: Alexander
 */

#include "../../../../src/build_defines.h"
#include "../../../Protocol/Include/IData.h"

	class ICommunicationModule {
	public:
	 	virtual ~ICommunicationModule() {/*Nothing to delete*/}
		virtual bool init() = 0;
		virtual void sendData(IData* data) = 0;
		virtual void receiveData(IData* data) = 0;
	};

#endif // __ICOMMUNICATIONMODULE_H__