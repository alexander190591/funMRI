#ifndef IBATTERYMODULE_H_
#define IBATTERYMODULE_H_
#include <stdint.h>

class IBatteryModule {
	public:
		virtual float readBatteryVoltage(void) = 0;
		virtual uint8_t MilliVoltToPercentage(float mVolts) = 0;
	};

#endif // IBATTERYMODULE_H_