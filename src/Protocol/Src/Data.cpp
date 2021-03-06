/**
 * @file Data.cpp
 * @author Alexander (au482141@post.au.dk)
 * @brief Implementation of the interface for the data class used for communication.
 * @version 0.1
 * @date 2020-03-16
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include "..\Include\Data.h"

// Data::Data(const Data& oldData)
// {
//     for(int i = 0; i < SIZE_OF_DATA_ARRAY; i++)
//         _data[i] = oldData._data[i];
// }

/**
 * @brief Method that sets the dataOutputArray to the values found in the _data array.
 * 
 * @param [out] dataOutputArray Array that is being filled with the values found in the _data array.
 *          OBS: Size of dataOutputArray MUST be SIZE_OF_DATA_ARRAY long!!
 */
void Data::getData(unsigned char dataOutputArray[]) const
{
    for(int i = 0; i < SIZE_OF_DATA_ARRAY; i++)
        dataOutputArray[i] = _data[i];
}

/**
 * @brief Method that sets the _data attribute in the Data object from the dataInputArray.
 * 
 * @param dataInputArray Array of which the values are copied into the _data array.
 *           OBS: Size of dataInputArray MUST be SIZE_OF_DATA_ARRAY long!!
 */
void Data::setData(unsigned char dataInputArray[])
{
    #ifdef DEBUGGING_SUBTLE
        std::cout << "Entered Data::setData()..." << std::endl;
    #endif

    for(int i = 0; i < SIZE_OF_DATA_ARRAY; i++)
    {
        _data[i] = dataInputArray[i];
        #ifdef DEBUGGING_LARGE
            std::cout << "_data[" << i << "] = " << _data[i] << std::endl;
            std::cout << "dataInputArray[" << i << "] = " << dataInputArray[i] << std::endl;
        #endif
    }

    #ifdef DEBUGGING_LARGE
        std::cout << "Exits Data::setData()..." << std::endl;
    #endif
}

/**
 * @brief Setting up the Data array for a message with the message msg.
 * 
 * @param msg is the message to be sent. Needs to be one of the enum values in Message.
 */
void Data::setMessage(Message msg)
{
    _data[SIZE_OF_DATA_ARRAY] = {0};        // Clearing the array.
    _data[0] = 'M';
    _data[1] = msg;
}

/**
 * @brief Setting up the IDdata array with the ID values found in ID.
 * 
 * @param ID is the unsigned char array that holds the ID values.
 *           OBS: Size of ID MUST be SIZE_OF_DATA_ARRAY-1 long!!
 */
void Data::setIDdata(unsigned char ID[])
{
    #ifdef DEBUGGING_LARGE
        std::cout << "Enter: setIDdata()..." << std::endl;
    #endif

    _data[SIZE_OF_DATA_ARRAY] = {0};        // Clearing the array.
    _data[0] = 'D';
    for(int i = 1; i < SIZE_OF_DATA_ARRAY; i++)
        _data[i] = ID[i-1];
}

/**
 * @brief Sets the output parameter ID (should be 7 bytes long) to the data bytes of the _data array in the Data object.
 * 
 * @param ID [out] is set to the (7) data bytes of the _data array in the Data object.
 */
void Data::getIDdata(unsigned char ID[])
{
    for(int i = 0; i < SIZE_OF_DATA_ARRAY - 1; i++)
        ID[i] = _data[i+1];
}

/**
 * @brief Returns the enum equivalent to the value found in the Data object.
 *        If the data in the Data object is not equivalent to any known message,
 *        ERROR_NOT_A_MESSAGE (0xFF) is returned.
 * 
 * @return Message equivalent to the value found in the Data object.
 */
Message Data::getMessage()
{
    if(_data[0] == 'M')
        {
            switch((unsigned char)_data[1])
            {
                case MSG_ERROR_NO_ID_REGISTERED:
                case MSG_ERROR_NOT_INIT_TAG:
                case MSG_INFO_SOUND_PLAYED:
                case MSG_CMD_INIT:
                case MSG_CMD_SCAN:
                case MSG_TEST_SCAN:
                case MSG_TEST_INIT:
                    return (Message)_data[1];
                default:
                    return MSG_ERROR_NOT_A_MESSAGE;
            }
        }
    else
        return MSG_ERROR_NOT_A_MESSAGE;
}

/**
 * @brief Resets the Data object's _data attribute to all zeros.
 * 
 */
void Data::clearData()
{
    for(int i = 0; i < SIZE_OF_DATA_ARRAY; i++)
        _data[i] = 0;
}

/**
 * @brief Method for checking if anything has been stored in the Data object.
 * 
 * @return true is returned if either a message (Data Type == 'M') or data (Data Type == 'D') is in the Type Byte.
 * @return false is returned if no message or data is stored.
 */
bool Data::dataReceived()
{
    if(_data[0] == 'M' || _data[0] == 'D')
        return true;
    else
        return false;
}

/**
 * @brief Checks if the two arrays contain the same data.
 * 
 * @param arrayOne is the array that is compared to arrayTwo.
 * @param arrayTwo is the array that is compared to arrayOne.
 * @return true is returned if the data in the two arrays are equal.
 * @return false is returned if the data in the two arrays are NOT equal.
 */
bool Data::isSame(unsigned char arrayOne[], unsigned char arrayTwo[])
{
    bool isSame = false;
    for(int i = 0; i < SIZE_OF_DATA_ARRAY; i++)
    {
        if(arrayOne[i] == arrayTwo[i])
            isSame = true;
        else
        {
            isSame = false;
            break;
        }
    }
    return isSame;
}

/**
 * @brief Checks if the data bytes ([1] to [7]) in the this data object is the same as the unsigned char array (7 byte long).
 * 
 * @param testData is a 7 byte long unsigned char array that contains the data that is tested for in the object's data bytes.
 * @return true if the data bytes are the same as in the testData array.
 * @return false if the data bytes are NOT the same as in the testData array.
 */
bool Data::isIDDataSame(unsigned char testData[])
{
    bool isSame = false;
    for(int i = 0; i < SIZE_OF_DATA_ARRAY-1; i++)
    {
        if(_data[i+1] == testData[i])
            isSame = true;
        else
        {
            isSame = false;
            break;
        }
    }
    return isSame;
}