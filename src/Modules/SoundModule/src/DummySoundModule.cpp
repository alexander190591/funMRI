/**
 * @file DummyScanner.cpp
 * @author Tobias Bach Aunboel (au328752@post.au.dk)
 * @brif Test class for the SoundModule used for testing
 * @version 0.1
 * @date 2020-03-24
 *
 *
 */
#include "../include/DummySoundModule.h"


DummySoundModule::DummySoundModule()
{
	this->init();
}

void DummySoundModule::playSound()
{
	Serial.println("DummySoundModule: playSound()");
}

void DummySoundModule::stopSound()
{
	Serial.println("DummySoundModule: stopSound()");
}

void DummySoundModule::init()
{
	Serial.println("DummySoundModule: init()");
}


