/**
 * @file WithoutSmartphoneMode.h
 * @author Alexander Najbjerg Christensen (au482141@post.au.dk)
 * @brief 
 * @version 0.1
 * @date 2020-03-16
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#ifndef WITHOUTSMARTPHONEMODE_H_
#define WITHOUTSMARTPHONEMODE_H_

#include "IFunMRIController.h"

class WithoutSmartphoneMode : public IFunMRIController
{
public:
    void run(void);
private:
    FunMRI* _funMRI = nullptr;
};

#endif // WITHOUTSMARTPHONEMODE_H_