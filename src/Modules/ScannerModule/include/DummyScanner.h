/**
 * @file DummyScanner.h
 * @author Tobias Bach Aunboel (au328752@post.au.dk)
 * @brif Test class for the ScannerModule used for testing
 * @version 0.1
 * @date 2020-03-18
 *
 *
 */

#ifndef DUMMYSCANNER_H
#define DUMMYSCANNER_H
/**
 *
 * REMEMBER TO RUN Serial.begin(9600) from main otherwise print message wont work
 *
 */

#include "IScannerModule.h"
#include <Arduino.h>

#define SIZE_OF_DATA 7


class DummyScanner : public IScannerModule
{
public:
	DummyScanner();
	void scan();
	unsigned char* retrieveResult();
	bool isNewScanAvailable();
	int getSizeOfData();
	void init();
private:
	bool _isNewScanAvailable = false;
	unsigned char _data[SIZE_OF_DATA] = {0};
};



#endif // DUMMYSCANNER_H
