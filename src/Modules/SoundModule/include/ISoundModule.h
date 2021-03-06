/*
 * ISoundModule.h
 *
 *  Created on: 28. jan. 2020
 *      Author: taunb
 */

#ifndef SOUNDMODULE_INCLUDE_ISOUNDMODULE_H_
#define SOUNDMODULE_INCLUDE_ISOUNDMODULE_H_

#pragma once

#include "../../../../src/build_defines.h"

/**
* @brief This is the interface for the SoundModule
*
*
*/
class ISoundModule
{
public:
	virtual ~ISoundModule() {/*Nothing to delete...*/}
	virtual void playSound() = 0;
	virtual void stopSound() = 0;
protected:
/**
	*@brief The constructor calls the protected member init() whitch needs to be implemented in the derived classes
	*@param void
	*@returns void
	*/
	virtual void init() = 0;
};
#endif /* SOUNDMODULE_INCLUDE_ISOUNDMODULE_H_ */
