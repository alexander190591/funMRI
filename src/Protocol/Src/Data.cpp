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
    for(int i = 0; i < SIZE_OF_DATA_ARRAY; i++)
        _data[i] = dataInputArray[i];
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
    _data[SIZE_OF_DATA_ARRAY] = {0};        // Clearing the array.
    _data[0] = 'D';
    for(int i = 1; i < SIZE_OF_DATA_ARRAY; i++)
        _data[i] = ID[i-1];
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
        //std::cout << " IDDataFinal[" << i << "]: "<< IDDataFinal[i] << ". dataRead[" << i << "]: " << dataRead[i] << std::endl; // For visual testing...
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

bool operator==(const IData& lhs, const IData& rhs)
{
    unsigned char one[SIZE_OF_DATA_ARRAY];
    lhs.getData(one);
    unsigned char two[SIZE_OF_DATA_ARRAY];
    rhs.getData(two);

    Data dataComparer = Data();

    return dataComparer.isSame(one, two);
}