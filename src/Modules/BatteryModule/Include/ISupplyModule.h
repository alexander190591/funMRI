#ifndef ISUPPLYMODULE_H_
#define ISUPPLYMODULE_H_
#include <stdint.h>

class ISupplyModule {
	public:
		virtual float readBatteryVoltage(void) = 0;
		virtual uint8_t MilliVoltToPercentage(float mVolts) = 0;
	};

#endif // ISUPPLYMODULE_H_