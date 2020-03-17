/**
 * @file Data.h
 * @author Alexander Najbjerg Christensen (au482141@post.au.dk)
 * @brief Header file for the implementation of the interface for the data class used for communication.
 * @version 0.1
 * @date 2020-03-16
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#ifndef DATA_H_
#define DATA_H_

#include "IData.h"

#define SIZE_OF_DATA_ARRAY 8

/**
 * @brief Data 
 * Class used to keep track of the data between modules. This Data class keeps a char array of eight (8) chars.
 * 
 * Data contains the data sent around between modules. It contains a char array of eight (8) chars.
 * The protocol used with this data is as follows:
 * ----------------------------------------------------------------------------
 * |   Byte   |   0   |   1   |   2   |   3   |   4   |   5   |   6   |   7   |
 * ----------------------------------------------------------------------------
 * | Contains | Type  | Data0 | Data1 | Data2 | Data3 | Data4 | Data5 | Data6 |
 * |          |       | / msg |       |       |       |       |       |       |
 * ----------------------------------------------------------------------------
 * 
 * Where the Type can be the char 'D' for Data or 'M' for Message. 
 * The data bytes are the RFID-ID from the ScannerModule if the Type-byte (byte 0) is a 'D'.
 * If the data is a message (error or information) the Type-byte (byte 0) is an 'M'. 
 * Only Data0 (bit 1) used to store the message. The message is of type DataMessage (enum):
 * 
 * ERROR_NO_ID_REGISTERED = 0xAA, Used when ScannerModule cannot scan an ID.
 * ERROR_NOT_INIT_TAG     = 0xBB, Used when ID is not the same as when ID was initiated.
 * INFO_SOUND_PLAYED      = 0xCC, Used when sound clip is done playing.
 * CMD_INIT               = 0xDD, Used for initiating ID.
 * CMD_SCAN               = 0xEE, Used to play sound.
 */
class Data : public IData
{
public:
    void getData(char dataOutputParameter[]);
    void setData(char dataInputParameter[]);
    void setMessage(Message msg);
    void setIDdata(char IDdata[]);
private:
    char _data[SIZE_OF_DATA_ARRAY];             
};

#endif // DATA_H_