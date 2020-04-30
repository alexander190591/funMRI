#ifndef __TESTMODE_H__
#define __TESTMODE_H__

/**
 * @file TestModeWithoutSmartphone.h
 * @author Alexander Najbjerg Christensen (au482141@post.au.dk)
 * @brief In this test mode all objects are public to enable reading of the objects.
 * @version 0.1
 * @date 2020-03-29
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include "IFunMRIController.h"

class TestModeWithoutSmartphone : public IFunMRIController
{
public:
    TestModeWithoutSmartphone();
    ~TestModeWithoutSmartphone();
    void run(void);
    void resetModeChanged(void);
// private:     // Made public for making testing simple...
    FunMRI* _funMRI = nullptr;
    IData* _data = nullptr;
};

 #endif // __TESTMODE_H__