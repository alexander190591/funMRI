/*
 * BatteryFeather.h
 * This is the Header file for the Battery Module embedded in the Bluefruit Feather nRF.
 * It needs read the voltage of the battery and be able to return the battery status as a percentage charge.
 *
 *  Created on: March 16th 2020
 *      Author: Alexander
 */

#ifndef BATTERYFEATHER_H_
#define BATTERYFEATHER_H_

#include "ISupplyModule.h"

#define NRF52

#if defined ARDUINO_NRF52840_CIRCUITPLAY
#define  PIN_VBAT          A8   // this is just a mock read, we'll use the light sensor, so we can run the test
#endif

#define VBAT_MV_PER_LSB   (0.73242188F)   // 3.0V ADC range and 12-bit ADC resolution = 3000mV/4096

#ifdef NRF52840_XXAA
#define VBAT_DIVIDER      (0.5F)          // 150K + 150K voltage divider on VBAT
#define VBAT_DIVIDER_COMP (2.0F)          // Compensation factor for the VBAT divider
#else
#define VBAT_DIVIDER      (0.71275837F)   // 2M + 0.806M voltage divider on VBAT = (2M / (0.806M + 2M))
#define VBAT_DIVIDER_COMP (1.403F)        // Compensation factor for the VBAT divider
#endif

#define REAL_VBAT_MV_PER_LSB (VBAT_DIVIDER_COMP * VBAT_MV_PER_LSB)

class BatteryFeather : public ISupplyModule
{
public:
    BatteryFeather(uint32_t BatteryVoltagePin);
    ~BatteryFeather() {/*Nothing to delete...*/};
    float readBatteryVoltage(void);
    uint8_t MilliVoltToPercentage(float mVolts);
private:
    uint32_t _vBatPin = 0;
};




#endif /* BLUETOOTHMODULE_HM_10_BLUETOOTHMODULE_H_ */