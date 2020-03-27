#include "IScannerModule.h"
#include <iostream>

#define SIZE_OF_DATA 7


class DummyScannerTest : public IScannerModule
{
public:
	DummyScannerTest();
    ~DummyScannerTest();
	void scan();
	unsigned char* retrieveResult();
	bool isNewScanAvailable();
	int getSizeOfData();
	void init();
private:
	bool _isNewScanAvailable = false;
	unsigned char _data[SIZE_OF_DATA] = {0};
};

DummyScannerTest::DummyScannerTest()
{
	std::cout << "DummyScanner: Constructor" << std::endl;
	this->init();
}

DummyScannerTest::~DummyScannerTest()
{
    std::cout << "DummyScannerTest: Destructor." << std::endl;
    // Nothing to delete
}

void DummyScannerTest::scan()
{
	std::cout << "DummyScanner: scan()" << std::endl;
	for(int i = 0; i < SIZE_OF_DATA; i++)
	{
		this->_data[i] = i;
	}
	this->_isNewScanAvailable = true;
}

unsigned char* DummyScannerTest::retrieveResult()
{
	return this->_data;
}

bool DummyScannerTest::isNewScanAvailable()
{
	return this->_isNewScanAvailable;
}

int DummyScannerTest::getSizeOfData()
{
	return SIZE_OF_DATA;
}

void DummyScannerTest::init()
{
	std::cout << "DummyScanner: init()" << std::endl;
}