#include "ISupplyModule.h"

#ifdef TEST_BUILD
    #include <iostream>
#endif

class SupplyDummyTest : public ISupplyModule
{
public:
    SupplyDummyTest() { 
        #ifdef DEBUGGING_LARGE
            std::cout << "SupplyDummyTest: Constructor." << std::endl;
        #endif
        };
    ~SupplyDummyTest() { 
        #ifdef DEBUGGING_LARGE
            std::cout << "SupplyDummyTest: Destructor." << std::endl;
        #endif
        /*Nothing to delete...*/ 
        };
    float readBatteryVoltage(void) { return 75.5; };
	uint8_t MilliVoltToPercentage(float mVolts) { return ( mVolts * 100 ) / 3700; };
};
