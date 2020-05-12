/*
 * DFTPlayerMini.cpp
 *
 *  Created on: 28. jan. 2020
 *      Author: taunb
 */

#include "../Include/DFPlayerMini.h"



DFPlayerMini::DFPlayerMini(int RX, int TX, int baudrate) {

	_DFPlayerPtr = new DFRobotDFPlayerMini();
	_rx = RX;
	_tx = TX;
	_baudrate = baudrate;

	this->init();
}

DFPlayerMini::~DFPlayerMini()
{
	delete _serialPtr;
	delete _DFPlayerPtr;
}


void DFPlayerMini::stopSound(){


}

void DFPlayerMini::playSound(){
	//_DFPlayerPtr->volume(5);
	_DFPlayerPtr->play(1);
}

void DFPlayerMini::init(){
	//Include exception here instead of Serial:
	
	//new SoftwareSerial(_rx, _tx); ---- SoftwareSerial is in conflict with BluetoothFeather. Dedicated UART pins on Feather is used instead.
	_serialPtr = &Serial; 

	//_serialPtr->begin(_baudrate);
	  
	if(!_DFPlayerPtr->begin(*(_serialPtr)))
	{
	    Serial.println(F("Unable to begin:"));
	    Serial.println(F("1.Please recheck the connection!"));
	    Serial.println(F("2.Please insert the SD card!"));

	    while(true);
	}

	_DFPlayerPtr->volume(25);
}


