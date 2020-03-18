#ifndef SMARTPHONEMODE_H_
#define SMARTPHONEMODE_H_

/**
 * @file SmartphoneMode.h
 * @author Alexander Najbjerg Christensen (au482141@post.au.dk)
 * @brief 
 * @version 0.1
 * @date 2020-03-16
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include "IFunMRIController.h"

class SmartphoneMode : public IFunMRIController
{
public:
    void run(void);
private:
    FunMRI* _funMRI = nullptr;
};

#endif // SMARTPHONEMODE_H_