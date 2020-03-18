/**
 * @file IData.h
 * @author Alexander Najbjerg Christensen (au482141@post.au.dk)
 * @brief Interface for the data class used as communication.
 * @version 0.1
 * @date 2020-03-16
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#ifndef IDATA_H_
#define IDATA_H_

/**
 * @brief DataMessage is the enum used to keep track of the different messages
 *        that can be sent between funMRI and funMRI App.
 * 
 */
enum Message{
    MSG_ERROR_NO_ID_REGISTERED = 0xAA, // Used when ScannerModule cannot scan an ID.
    MSG_ERROR_NOT_INIT_TAG     = 0xBB, // Used when ID is not the same as when ID was initiated.
    MSG_INFO_SOUND_PLAYED      = 0xCC, // Used when sound clip is done playing.
    MSG_CMD_INIT               = 0xDD, // Used to scanning the ID before playing sound.
    MSG_CMD_SCAN               = 0xEE, // Used to play sound.
    MSG_ERROR_NOT_A_MESSAGE    = 0xFF, // Used for when data following the Type Byte is not one of the below values.
    MSG_TEST_INIT              = 'I',  // FOR TEST PURPOSES
    MSG_TEST_SCAN              = 'S',  // FOR TEST PURPOSES
};

class IData
{
public:
    virtual void getData(unsigned char dataOutputParameter[]) = 0;
    virtual void setData(unsigned char dataInputParameter[]) = 0;
    virtual void setMessage(Message msg) = 0;
    virtual void setIDdata(unsigned char IDdata[]) = 0;
    virtual Message getMessage();
    virtual void clearData() = 0;
    virtual bool dataReceived() = 0;
    virtual bool isSame(unsigned char arrayOne[], unsigned char arrayTwo[]) = 0;
};

#endif // IDATA_H_