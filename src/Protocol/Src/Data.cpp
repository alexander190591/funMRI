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

/**
 * @brief Method that sets the dataOutputArray to the values found in the _data array.
 * 
 * @param dataOutputArray Array that is being filled with the values found in the _data array.
 *          OBS: Size of dataOutputArray MUST be SIZE_OF_DATA_ARRAY long!!
 */
void Data::getData(char dataOutputArray[])
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
void Data::setData(char dataInputArray[])
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
 * @param ID is the char array that holds the ID values.
 *           OBS: Size of ID MUST be SIZE_OF_DATA_ARRAY-1 long!!
 */
void Data::setIDdata(char ID[])
{
    _data[SIZE_OF_DATA_ARRAY] = {0};        // Clearing the array.
    _data[0] = 'D';
    for(int i = 1; i < SIZE_OF_DATA_ARRAY; i++)
        _data[i] = ID[i-1];
}