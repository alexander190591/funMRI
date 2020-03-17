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
 * @brief DataMessage is the enum used to keep track of the different messages
 *        that can be sent between funMRI and funMRI App.
 * 
 */
enum Message{
    ERROR_NO_ID_REGISTERED = 0xAA, // Used when ScannerModule cannot scan an ID.
    ERROR_NOT_INIT_TAG     = 0xBB, // Used when ID is not the same as when ID was initiated.
    SOUND_PLAYED           = 0xCC, // Used when sound clip is done playing.
    INIT                   = 0xDD, // 
    SCAN                   = 0xEE  // 
};

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
 * Where the Type can me the char 'D' for Data or 'M' for Message. 
 * The data bytes are the RFID-ID from the ScannerModule if the Type-byte (byte 0) is a 'D'.
 * If the data is a message (error or information) the Type-byte (byte 0) is an 'M'. 
 * Only Data0 (bit 1) used to store the message. The message is of type DataMessage (enum):
 * 
 * ERROR_NO_ID_REGISTERED = 0xAA, // Used when ScannerModule cannot scan an ID.
 * ERROR_NOT_INIT_TAG     = 0xBB, // Used when ID is not the same as when ID was initiated.
 * SOUND_PLAYED           = 0xCC  // Used when sound clip is done playing.
 */
class Data : public IData
{
public:
    void getData(char* dataOutputParameter) const;
    void setData(char* dataInputParameter);
    void setMessage(Message msg);
private:
    char _data[SIZE_OF_DATA_ARRAY];             
};

#endif // DATA_H_