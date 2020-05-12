#include "../Include/SoundDummy.h"
#include <Arduino.h>

SoundDummy::SoundDummy(uint8_t ledPin)
{
    _ledPin = ledPin;
    this->init();
}

void SoundDummy::playSound()
{
    #ifdef UART_BUILD
    Serial.println("Playing sound (Setting LED HIGH for two seconds...");        
  	#endif UART_BUILD

    digitalWrite(_ledPin, HIGH);
    delay(2000);
    digitalWrite(_ledPin, LOW);
}

void SoundDummy::stopSound()
{
    digitalWrite(_ledPin, LOW);
}

void SoundDummy::init()
{
    pinMode(_ledPin, OUTPUT);
    digitalWrite(_ledPin, LOW);

    #ifdef UART_BUILD
        Serial.print(_ledPin); Serial.println(" has been set to OUTPUT and LOW...");
    #endif UART_BUILD
    
}