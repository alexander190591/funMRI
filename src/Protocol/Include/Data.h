#ifndef __DATA_H__
#define __DATA_H__

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

#include "IData.h"

#ifdef TEST_BUILD
    #include <iostream>
#endif

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
 * MSG_ERROR_NO_ID_REGISTERED = '0', // Used when ScannerModule cannot scan an ID.
 * MSG_ERROR_NOT_INIT_TAG     = '1', // Used when ID is not the same as when ID was initiated.
 * MSG_INFO_SOUND_PLAYED      = '2', // Used when sound clip is done playing.
 * MSG_CMD_INIT               = '3', // Used to scanning the ID before playing sound.
 * MSG_CMD_SCAN               = '4', // Used to play sound.
 * MSG_ERROR_NOT_A_MESSAGE    = '5', // Used for when data following the Type Byte is not one of the below values.
 * MSG_TEST_INIT              = 'I',  // FOR TEST PURPOSES
 * MSG_TEST_SCAN              = 'S',  // FOR TEST PURPOSES
 */
class Data : public IData
{
public:
    ~Data() override {
        #ifdef DEBUGGING_LARGE
        std::cout << "Data: Deconstructor." << std::endl;
        #endif
        /*Nothing to delete here...*/
        }
    void getData(unsigned char dataOutputParameter[]) const override;
    void setData(unsigned char dataInputParameter[])  override;
    void setMessage(Message msg)  override;
    void setIDdata(unsigned char IDdata[])  override;
    void getIDdata(unsigned char IDdata[]) override;
    Message getMessage()  override;
    void clearData()  override;
    bool dataReceived()  override;
    bool isSame(unsigned char arrayOne[], unsigned char arrayTwo[])  override;
    bool isIDDataSame(unsigned char testData[]) override;

    // Data& operator=(const Data& data) // Assignment Operator
    // {
    //     std::cout << "Data Assignment operator... begin." << std::endl;
    //     if(&data == this)   // Checking for self-assignment
    //         return *this;
        
    //     for(int i = 0; i < SIZE_OF_DATA_ARRAY; i++)
    //         _data[i] = data._data[i];
        
    //     std::cout << "Data Assignment operator... end." << std::endl;
    //     return *this;
    // };

private:
    unsigned char _data[SIZE_OF_DATA_ARRAY];             
};

//bool operator==(const IData& lhs, const IData& rhs);

#endif // __DATA_H__