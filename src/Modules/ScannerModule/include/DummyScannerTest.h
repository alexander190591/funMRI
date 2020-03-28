#include "IScannerModule.h"

#ifdef TEST_BUILD
    #include <iostream>
#endif

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
	#ifdef DEBUGGING_LARGE
		std::cout << "DummyScanner: Constructor" << std::endl;
	#endif

	this->init();
}

DummyScannerTest::~DummyScannerTest()
{
	#ifdef DEBUGGING_LARGE
    std::cout << "DummyScannerTest: Destructor." << std::endl;
	#endif

    // Nothing to delete
}

void DummyScannerTest::scan()
{
	#ifdef DEBUGGING_SUBTLE
		std::cout << "DummyScanner: scan()" << std::endl;
	#endif

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
	#ifdef DEBUGGING_LARGE
		std::cout << "DummyScanner: init()" << std::endl;
	#endif
}