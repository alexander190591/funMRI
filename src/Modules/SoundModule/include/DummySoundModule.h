/**
 * @file DummySound.h
 * @author Tobias Bach Aunboel (au328752@post.au.dk)
 * @brief Test class for the SoundModule used for testing
 * @version 0.1
 * @date 2020-03-24
 *
 *
 */
#ifndef DUMMYSOUNDMODULE_H_
#define DUMMYSOUNDMODULE_H_

#pragma once

#include "ISoundModule.h"
#include <Arduino.h>

/**
* @brief REMEMBER TO RUN Serial.begin(9600) from main otherise print messages wont work
*
*
*/

class DummySoundModule : public ISoundModule
{
public:
DummySoundModule();
void playSound();
void stopSound();
private:
protected:
void init();

};


#endif