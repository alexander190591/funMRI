/**
 * @file DummyUserInterface.h
 * @author Alexander Najbjerg Christensen (au482141@post.au.dk)
 * @brief 
 * @version 0.1
 * @date 2020-03-26
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include "IUserInterfaceModule.h"
#include <Arduino.h>

class DummyUserInterface: public IUserInterfaceModule
{
public:
    DummyUserInterface() {Serial.println("DummyUserInterface: Constructor");}
    ~DummyUserInterface() {Serial.println("DummyUserInteface: Destructor"); /*Nothing to delete...*/}
};