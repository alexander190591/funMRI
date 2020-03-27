#include "ISoundModule.h"
#include <iostream>

class SoundDummyTest : public ISoundModule
{
public:
    SoundDummyTest() { std::cout << "SoundDummyTest: Constructor." << std::endl; this->init(); }
    ~SoundDummyTest() { std::cout << "SoundDummyTest: Destructor." << std::endl; /*Nothing to delete...*/ }
    void playSound() { std::cout << "Sound played." << std::endl; }
	void stopSound() { std::cout << "Sound stopped" << std::endl; }
protected:
	void init() { std::cout << "SoundDummyTest init()." << std::endl; }
};