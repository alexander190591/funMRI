/**
 * @file UserInterfaceDummyTest.h
 * @author Alexander Najbjerg Christensen (au482141@post.au.dk)
 * @brief 
 * @version 0.1
 * @date 2020-03-26
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include "IUserInterfaceModule.h"

#ifdef TEST_BUILD
    #include <iostream>
#endif

class UserInterfaceDummyTest: public IUserInterfaceModule
{
public:
    UserInterfaceDummyTest() { 
        #ifdef DEBUGGING_LARGE
            std::cout << "UserInterfaceDummyTest: Constructor." << std::endl;
        #endif
        }
    ~UserInterfaceDummyTest() { 
        #ifdef DEBUGGING_LARGE
            std::cout << "UserInterfaceDummyTest: Destructor." << std::endl;
        #endif
        /*Nothing to delete...*/
        }
};