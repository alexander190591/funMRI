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
	#ifdef UART_BUILD
    	Serial.println("DummyScanner: Constructor");
	#endif UART_BUILD
	
	this->init();
}

void DummyScanner::scan()
{
	#ifdef UART_BUILD
    	Serial.println("DummyScanner: scan()");
	#endif UART_BUILD
	
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
	#ifdef UART_BUILD
    Serial.println("DummyScanner: init()");
	#endif UART_BUILD
}
