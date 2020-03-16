/**
 * @file BluetoothFeather.cpp
 * @author ANC (au482141@post.au.dk)
 * @brief Implementation of Bluetooth Low Energy for Bluefruit Feather. With this implementation, 
 * it's possible to write UART-messages to the microcontroller via BLE.
 * Inspiration from https://github.com/adafruit/Adafruit_nRF52_Arduino/blob/master/libraries/Bluefruit52Lib/examples/Peripheral/bleuart/bleuart.ino.
 * @version 0.1
 * @date 2020-03-10
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include "../Include/BluetoothFeather.h"
#include <bluefruit.h>
#include <Adafruit_LittleFS.h>
#include <InternalFileSystem.h>

//#include "../../BatteryModule/Include/BatteryFeather.h"
//IBatteryModule* battModule = new BatteryFeather(31);


// BLE Service
BLEDfu  bledfu;  // OTA DFU service
BLEDis  bledis;  // device information
BLEUart bleuart; // uart over ble
BLEBas  blebas;  // battery

int counter = 0;

/**
 * @brief Callback function for when module has connected to central.
 * 
 * @param conn_handle Connection Handle used to keep track of the central.
 */
void connect_callback(uint16_t conn_handle)
{
  // Get the reference to current connection
  BLEConnection* connection = Bluefruit.Connection(conn_handle);

  char central_name[32] = { 0 };
  connection->getPeerName(central_name, sizeof(central_name));

  Serial.print("Connected to ");
  Serial.println(central_name);
}

/**
 * Callback function for when connection to central is dropped.
 * @param conn_handle Connection that is dropped.
 * @param reason BLE_HCI_STATUS_CODE. Can be found in ble_hci.h.
 */
void disconnect_callback(uint16_t conn_handle, uint8_t reason)
{
  (void) conn_handle;
  (void) reason;

  Serial.println();
  Serial.print("Disconnected, reason = 0x"); 
  Serial.println(reason, HEX);
}

/**
 * @brief Function used to start advertising. Sets up all advertising settings needed and advertises.
 * 
 */
void startAdv(void)
{
  // Advertising packet
  Bluefruit.Advertising.addFlags(BLE_GAP_ADV_FLAGS_LE_ONLY_GENERAL_DISC_MODE);
  Bluefruit.Advertising.addTxPower();

  // Include bleuart 128-bit uuid
  Bluefruit.Advertising.addService(bleuart);

  // Secondary Scan Response packet (optional)
  // Since there is no room for 'Name' in Advertising packet
  Bluefruit.ScanResponse.addName();
  
  /* Start Advertising
   * - Enable auto advertising if disconnected
   * - Interval:  fast mode = 20 ms, slow mode = 152.5 ms
   * - Timeout for fast mode is 30 seconds
   * - Start(timeout) with timeout = 0 will advertise forever (until connected)
   * 
   * For recommended advertising interval
   * https://developer.apple.com/library/content/qa/qa1931/_index.html   
   */
  Bluefruit.Advertising.restartOnDisconnect(true);
  Bluefruit.Advertising.setInterval(32, 244);    // in unit of 0.625 ms
  Bluefruit.Advertising.setFastTimeout(30);      // number of seconds in fast mode
  Bluefruit.Advertising.start(0);                // 0 = Don't stop advertising after n seconds  
}

/**
 * @brief Sends the String cmd via the Bluetooth module to the central that is connected.
 * 
 * @param cmd String with the command that is to be sent to the central (funMRI App).
 */
void BluetoothFeather::sendCmd(String cmd)
{
    char buf[64];
    cmd.toCharArray(buf, 64);
    int count = sizeof(buf);
    bleuart.write(buf);
    Serial.println(buf);
}

/**
 * @brief Checking for incoming messages on the Bluetooth connection. If anything is available, the message is returned.
 * 
 * @return String with the message received via Bluetooth from central (funMRI App).
 */
String BluetoothFeather::receiveCmd()
{
    String message = "";
  // Forward from BLEUART to HW Serial
  while ( bleuart.available() )
  {
    message = bleuart.readString();
  }
  return message;
}

/**
 * @brief Construct a new BluetoothFeather object.
 * 
 */
BluetoothFeather::BluetoothFeather()
{
    //Serial.println("Bluefruit BLE constructed.");                   // Used for debugging.

}

/**
 * @brief Initiates the Bluetooth module with names, stettings, etc.
 * 
 * @return true is returned always. Needed for the interface implementation (old module checked if module was connected to Arduino).
 * @return false is never returned.
 */
bool BluetoothFeather::init()
{
    Bluefruit.autoConnLed(true);                                    // Setup the BLE LED to be enabled on CONNECT.
    Bluefruit.configPrphBandwidth(BANDWIDTH_MAX);                   // Setting bandwidth to MAX.

    Bluefruit.begin();                                              // Configs should be done before .begin.
    Bluefruit.setTxPower(4);                                        // Sets the power of the transmitter.
    Bluefruit.setName("funMRI");                                    // Sets name of BLE-device (this microconroller) to funMRI.
    Bluefruit.Periph.setConnectCallback(connect_callback);          // Setting callback function for when connected.
    Bluefruit.Periph.setDisconnectCallback(disconnect_callback);    // Setting callback function for when disconnected.
    
    //bledfu.begin();                                                 // Used for updating firmware via BLE (OTA DFU service).
                                                                      // Could be used via app to update funMRI if needed.
    
    bledis.setManufacturer("funMRI Industries");                    // Setting name of manufacturer.
    bledis.setModel("funMRI Version 1");                            // Setting model name.
  
    bledis.begin();                                                 

    bleuart.begin();                                                // Starts up BLE as UART.

    //blebas.begin();                                                 // BLE Battery Service.
    //blebas.write(100);                                              // Always sends 100 % here. Needs rewriting to work with true values.

    startAdv();                                                     // Start advertising.

    Serial.println("BLE setup done. Look for BLE-device 'funMRI'.");

    return true;
}