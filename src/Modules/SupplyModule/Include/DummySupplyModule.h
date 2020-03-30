#ifndef DUMMYSUPPLYMODULE_H_
#define DUMMYSUPPLYMODULE_H_
#include <stdint.h>
#include "ISupplyModule.h"
#include <Arduino.h>

class DummySupplyModule : public ISupplyModule {
	public:
		float readBatteryVoltage(void)
        {
            Serial.println("DummySupplyModule: readBatteryVoltage");
            return 3.3;
        }
		uint8_t MilliVoltToPercentage(float mVolts)
        {
            Serial.println("DummySupplyModule: MilliVoltToPercentage");
            return (mVolts/3.3)*100;
        }
	};

#endif // ISUPPLYMODULE_H_
