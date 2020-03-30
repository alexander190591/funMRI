/*
 * DFTPlayerMini.h
 *
 *  Created on: 28. jan. 2020
 *      Author: taunb
 */

#ifndef SOUNDMODULE_INCLUDE_DFPLAYERMINI_H_
#define SOUNDMODULE_INCLUDE_DFPLAYERMINI_H_

#include "ISoundModule.h"
//#include "SoftwareSerial.h"
#include "../include/DFRobotDFPlayer/DFRobotDFPlayerMini.h"


class DFPlayerMini : public ISoundModule
{
public:
	DFPlayerMini(int RX, int TX, int baudrate);
	~DFPlayerMini();
	void playSound() override;
	void stopSound() override;
protected:
	void init() override;

private:
	DFRobotDFPlayerMini *_DFPlayerPtr = nullptr;
	//SoftwareSerial *_serialPtr = nullptr;
	HardwareSerial* _serialPtr = nullptr;						// Changed to UART ptr instead of SoftwareSerial.
	int _rx = -1;
	int _tx = -1;
	int _baudrate = 0;

};
#endif /* SOUNDMODULE_INCLUDE_DFPLAYERMINI_H_ */
