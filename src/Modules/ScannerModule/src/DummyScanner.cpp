/**
 * @file DummyScanner.cpp
 * @author Tobias Bach Aunboel (au328752@post.au.dk)
 * @brif Test class for the ScannerModule used for testing
 * @version 0.1
 * @date 2020-03-18
 *
 *
 */

#include "../Include/DummyScanner.h"

DummyScanner::DummyScanner()
{
	Serial.println("DummyScanner: Constructor");
	this->init();
}

DummyScanner::~DummyScanner()
{
	// Nothing to delete...
}

void DummyScanner::scan()
{
	Serial.println("DummyScanner: scan()");
	for(int i = 0; i < SIZE_OF_DATA; i++)
	{
		this->_data[i] = i;
	}
	this->_isNewScanAvailable = true;
}
unsigned char* DummyScanner::retrieveResult()
{
	return this->_data;
}
bool DummyScanner::isNewScanAvailable()
{
	return this->_isNewScanAvailable;
}
int DummyScanner::getSizeOfData()
{
	return SIZE_OF_DATA;
}

void DummyScanner::init()
{
	Serial.println("DummyScanner: init()");
}
