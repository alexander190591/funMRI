/*
 * RFIDRC522.cpp
 *
 *  Created on: 3. feb. 2020
 *      Author: taunb
 */
#include "../Include/RFIDRC522.h"
#include "../Include/RFID-RC522/rfid-master/rfid-master/src/MFRC522.h"
#include <SPI.h>

RFIDRC522::RFIDRC522(int RSTpin, int SSpin)
{
	_RSTpin = RSTpin;
	_SSpin = SSpin;

	this->init();
}

RFIDRC522::~RFIDRC522()
{
	delete _rfidPtr;
}

void RFIDRC522::scan()
{
	Serial.println("scan() entered..."); // For debugging purposes

	_rfidPtr->PCD_Reset();
	_rfidPtr->PCD_Init();

	if(_rfidPtr->PICC_IsNewCardPresent())
	{
		digitalWrite(6, HIGH);
		this->readRFID();
	}
	else
	{
		_isNewScanAvailable = false;
	}



}

void RFIDRC522::init()
{
	_rfidPtr = new MFRC522(_SSpin, _RSTpin);
	Serial.print("ResetPin: "); Serial.println(_RSTpin);
	Serial.print("SSPin: "); Serial.println(_SSpin);
	SPI.begin();
	_rfidPtr->PCD_Init();
}

void RFIDRC522::readRFID()
{
	_isNewScanAvailable = false;
 	_rfidPtr->PICC_ReadCardSerial();
	_mfrcPiccType = _rfidPtr->PICC_GetType(_rfidPtr->uid.sak);

	if(!isDataTheSame(_rfidPtr->uid.uidByte, _rfidPtr->uid.size))
	{
		for(int i = 0; i < this->_rfidPtr->uid.size; i++)
		{
			_data[i] = _rfidPtr->uid.uidByte[i];
		}
	}


// Uncomment for debugging:
	Serial.println("printDec the new");
	for (int i = 0; i < sizeof(_data); i++) {

	Serial.print(_data[i] < 0x10 ? " 0" : " ");

	Serial.print(_data[i], DEC);
	Serial.print(_data[i]);
 	}

	// Halt PICC ??
	_rfidPtr->PICC_HaltA();

	// Stop encryption on PCD ??

	_rfidPtr->PCD_StopCrypto1();
	_isNewScanAvailable = true;
}

unsigned char* RFIDRC522::retrieveResult()
{
	return this->_data;
}

bool RFIDRC522::isNewScanAvailable()
{
	return _isNewScanAvailable;
}

int RFIDRC522::getSizeOfData()
{
	return SIZEOF_DATA;
}

bool RFIDRC522::isDataTheSame(unsigned char* dataToCompare, int sizeOfData)
{
	//if the size is not the same, then return false
	if(sizeof(_data) != sizeOfData)
	{
		return false;
	}

	else
	{
		int checkCount = 0;
		for(int i = 0; i < sizeOfData; i++)
		{
			if(_data[i] == dataToCompare[i])
			{
				checkCount++;
			}
		}
		if(checkCount == sizeof(_data))
		{
			return true;
		}
		else
		{
			return false;
		}

	}
}
