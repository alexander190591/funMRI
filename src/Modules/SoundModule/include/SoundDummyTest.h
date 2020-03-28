#include "ISoundModule.h"

#ifdef TEST_BUILD
    #include <iostream>
#endif

class SoundDummyTest : public ISoundModule
{
public:
    SoundDummyTest() {
        #ifdef DEBUGGING_LARGE
            std::cout << "SoundDummyTest: Constructor." << std::endl;
        #endif
        this->init(); 
        }
    ~SoundDummyTest() {
        #ifdef DEBUGGING_LARGE
            std::cout << "SoundDummyTest: Destructor." << std::endl;
        #endif            
            
        /*Nothing to delete...*/ 
    }
    void playSound() {
        #ifdef DEBUGGING_SUBTLE
            std::cout << "Sound played." << std::endl;
        #endif
    }
	void stopSound() {
        #ifdef DEBUGGING_SUBTLE
            std::cout << "Sound stopped" << std::endl;
        #endif
        }
protected:
	void init() { 
        #ifdef DEBUGGING_LARGE
            std::cout << "SoundDummyTest init()." << std::endl;
        #endif
        }
};