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
#include <iostream>

class UserInterfaceDummyTest: public IUserInterfaceModule
{
public:
    UserInterfaceDummyTest() {std::cout << "UserInterfaceDummyTest: Constructor." << std::endl;}
    ~UserInterfaceDummyTest() { std::cout << "UserInterfaceDummyTest: Destructor." << std::endl; /*Nothing to delete...*/}
};