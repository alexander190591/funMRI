// #include "../Include/BatteryFeather.h"
// #include <Arduino.h>

// BatteryFeather::BatteryFeather(uint32_t BatteryVoltagePin)
// {
//     _vBatPin = BatteryVoltagePin;           // = 31; A7 == pin 31 for feather nRF52832
// }

// float BatteryFeather::readBatteryVoltage()
// {
//     float raw;

//     // Set the analog reference to 3.0V (default = 3.6V)
//     analogReference(AR_INTERNAL_3_0);

//     // Set the resolution to 12-bit (0..4095)
//     analogReadResolution(12); // Can be 8, 10, 12 or 14

//     // Let the ADC settle
//     delay(1);

//     // Get the raw 12-bit, 0..3000mV ADC value
//     raw = analogRead(_vBatPin);

//     // Set the ADC back to the default settings
//     analogReference(AR_DEFAULT);
//     analogReadResolution(10);

//     // Convert the raw value to compensated mv, taking the resistor-
//     // divider into account (providing the actual LIPO voltage)
//     // ADC range is 0..3000mV and resolution is 12-bit (0..4095)
//     return raw * REAL_VBAT_MV_PER_LSB;
// }

// uint8_t BatteryFeather::MilliVoltToPercentage(float mVolts)
// {
//     if(mVolts<3300)
//     return 0;

//     if(mVolts <3600) {
//     mVolts -= 3300;
//     return mVolts/30;
//     }

//     mVolts -= 3600;
//     return 10 + (mVolts * 0.15F );  // thats mvolts /6.66666666
// }
