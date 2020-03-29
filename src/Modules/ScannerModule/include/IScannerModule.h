#ifndef __ISCANNERMODULE_H__
#define __ISCANNERMODULE_H__

#include "../../../../src/build_defines.h"

class IScannerModule
{
public:
	virtual ~IScannerModule() {/*Nothing to delete*/}
	virtual void scan() = 0;
	virtual void init() = 0;
	virtual unsigned char* retrieveResult() = 0;
	virtual bool isNewScanAvailable() = 0;
	virtual int getSizeOfData() = 0;
};


#endif // __ISCANNERMODULE_H__