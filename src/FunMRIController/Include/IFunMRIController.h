#ifndef _IFUNMRICONTROLLER_H_
#define _IFUNMRICONTROLLER_H_

/**
 * @file IFunMRIController.h
 * @author Alexander Najbjerg Christensen (au482141@post.au.dk)
 * @brief Interface for the funMRIController. This is the controller class. It has only one method: Run().
 * @version 0.1
 * @date 2020-03-16
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include "../../FunMRI/Include/FunMRI.h"

class IFunMRIController
{
    public:
        virtual void run(void) = 0;
};

#endif // _IFUNMRICONTROLLER_H_