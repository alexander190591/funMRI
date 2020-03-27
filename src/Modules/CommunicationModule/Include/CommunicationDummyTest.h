/**
 * @file CommunicationDummyTest.h
 * @author Alexander Najbjerg Christensen (au482141@post.au.dk)
 * @brief 
 * @version 0.1
 * @date 2020-03-26
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include "ICommunicationModule.h"
#include "../../../Protocol/Include/Data.h"
#include <iostream>

class CommunicationDummyTest : public ICommunicationModule
{
public:
    CommunicationDummyTest() {/* std::cout << "CommunicationDummyTest: Constructor." << std::endl;*/ }

    ~CommunicationDummyTest()
    {
        // std::cout << "CommunicationDummyTest: Destructor." << std::endl;
        // Nothing to delete...
    }

    bool init() 
    {
        //std::cout << "Communication Module Init." << std::endl;
        return true;
    }
    
    void sendData(IData* data) 
    {
        unsigned char dataArray[SIZE_OF_DATA_ARRAY];
        data->getData(dataArray);
        std::cout << "Data sent... " << std::endl; // << dataArray << std::endl;
    }

    void receiveData(IData* data)
    {
        unsigned char dataArray[SIZE_OF_DATA_ARRAY] = {'D', '1', '2', '3', '4', '5', '6', '7'};
        data->setData(dataArray);
        
        std::cout << "Data received... " << std::endl;
        // for(int i = 0; i < SIZE_OF_DATA_ARRAY; i++) 
        //     std::cout << dataArray[i];
        // std::cout << std::endl;
    }
};