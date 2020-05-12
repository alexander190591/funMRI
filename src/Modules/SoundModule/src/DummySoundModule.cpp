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
	#ifdef UART_BUILD
    	Serial.println("DummySoundModule: playSound()");
	#endif UART_BUILD
}

void DummySoundModule::stopSound()
{
	#ifdef UART_BUILD
    	Serial.println("DummySoundModule: stopSound()");
	#endif UART_BUILD
}

void DummySoundModule::init()
{
	#ifdef UART_BUILD
    	Serial.println("DummySoundModule: init()");
	#endif UART_BUILD
}


