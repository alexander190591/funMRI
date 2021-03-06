#ifndef ISUPPLYMODULE_H_
#define ISUPPLYMODULE_H_
#include <stdint.h>
#include "../../../build_defines.h"

class ISupplyModule {
	public:
		virtual ~ISupplyModule() {/*Nothing to delete...*/}
		virtual float readBatteryVoltage(void) = 0;
		virtual uint8_t MilliVoltToPercentage(float mVolts) = 0;
	};

#endif // ISUPPLYMODULE_H_
