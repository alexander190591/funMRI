/*
 * ISoundModule.h
 *
 *  Created on: 28. jan. 2020
 *      Author: taunb
 */

#ifndef SOUNDMODULE_INCLUDE_ISOUNDMODULE_H_
#define SOUNDMODULE_INCLUDE_ISOUNDMODULE_H_

#pragma once

/**
* @brief This is the interface for the SoundModule
*
*
*/
class ISoundModule
{
public:
	/**
	*@brief The constructor calls the protected member init() whitch needs to be implemented in the derived classes
	*@param void
	*@returns void
	*/
	virtual void playSound() = 0;
	virtual void stopSound() = 0;
protected:
	virtual void init() = 0;
};
#endif /* SOUNDMODULE_INCLUDE_ISOUNDMODULE_H_ */
