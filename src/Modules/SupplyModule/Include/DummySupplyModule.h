#ifndef DUMMYSUPPLYMODULE_H_
#define DUMMYSUPPLYMODULE_H_
#include <stdint.h>
#include "ISupplyModule.h"
#include <Arduino.h>

class DummySupplyModule : public ISupplyModule {
	public:
		float readBatteryVoltage(void)
        {
            #ifdef UART_BUILD
                Serial.println("DummySupplyModule: readBatteryVoltage");
  		    #endif UART_BUILD
            
            return 3.3;
        }
		uint8_t MilliVoltToPercentage(float mVolts)
        {
            #ifdef UART_BUILD
                Serial.println("DummySupplyModule: MilliVoltToPercentage");
  		    #endif UART_BUILD
            
            return (mVolts/3.3)*100;
        }
	};

#endif // ISUPPLYMODULE_H_
