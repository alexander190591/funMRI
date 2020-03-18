/**
 * @file DummyScanner.h
 * @author Tobias Bach Aunbøl (au328752@post.au.dk)
 * @brif Test class for the ScannerModule used for testing
 * @version 0.1
 * @date 2020-03-18
 *
 *
 */

#ifndef DUMMYSCANNER_H
#define DUMMYSCANNER_H

#include "IScannerModule.h"

#define SIZE_OF_DATA 7


class DummyScanner : public IScannerModule
{
public:
	DummyScanner();
	void scan();
	unsigned char* retrieveResult();
	bool isNewScanAvailable();
	int getSizeOfData();
private:
};



#endif // DUMMYSCANNER_H
