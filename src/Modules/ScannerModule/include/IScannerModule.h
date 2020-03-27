#ifndef ISCANNERMODULE_H
#define ISCANNERMODULE_H

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



#endif
