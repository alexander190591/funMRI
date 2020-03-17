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
    ERROR_NO_ID_REGISTERED = 0xAA, // Used when ScannerModule cannot scan an ID.
    ERROR_NOT_INIT_TAG     = 0xBB, // Used when ID is not the same as when ID was initiated.
    INFO_SOUND_PLAYED      = 0xCC, // Used when sound clip is done playing.
    CMD_INIT               = 0xDD, // Used to scanning the ID before playing sound.
    CMD_SCAN               = 0xEE  // Used to play sound.
};

class IData
{
public:
    virtual void getData(char dataOutputParameter[]) = 0;
    virtual void setData(char dataInputParameter[]) = 0;
    virtual void setMessage(Message msg) = 0;
    virtual void setIDdata(char IDdata[]) = 0;
};

#endif // IDATA_H_