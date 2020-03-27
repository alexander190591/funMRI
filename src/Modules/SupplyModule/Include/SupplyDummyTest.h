#include "ISupplyModule.h"
#include <iostream>

class SupplyDummyTest : public ISupplyModule
{
public:
    SupplyDummyTest() { /* std::cout << "SupplyDummyTest: Constructor." << std::endl; */ };
    ~SupplyDummyTest() { /* std::cout << "SupplyDummyTest: Destructor." << std::endl; */ /*Nothing to delete...*/ };
    float readBatteryVoltage(void) { return 75.5; };
	uint8_t MilliVoltToPercentage(float mVolts) { return ( mVolts * 100 ) / 3700; };
};
