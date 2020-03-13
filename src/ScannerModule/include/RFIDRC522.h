#ifndef RFIDRC522_H
#define RFIDRC522_H

#include "../include/IScannerModule.h"
#include "../include/RFID-RC522/rfid-master/rfid-master/src/MFRC522.h"

#define SIZEOF_DATA 7

class RFIDRC522 : public IScannerModule
{
public:
	RFIDRC522(int RSTpin, int SSpin);
	~RFIDRC522();
	void scan();
	void init();
	unsigned char *retrieveResult();
	bool isNewScanAvailable();
	int getSizeOfData();

private:
	void readRFID();
	bool isDataTheSame(unsigned char*, int size);
	unsigned char _data[SIZEOF_DATA] = {0};
	int _RSTpin = 0;
	int _SSpin = 0;
	bool _isNewScanAvailable = false;
	MFRC522 * _rfidPtr = nullptr;
	MFRC522::MIFARE_Key _mfrc522Key;
	MFRC522::PICC_Type _mfrcPiccType;

};


#endif
