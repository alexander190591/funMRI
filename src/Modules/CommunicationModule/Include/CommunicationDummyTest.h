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

#include "../../../../src/build_defines.h"
#include "ICommunicationModule.h"
#include "../../../Protocol/Include/Data.h"

#ifdef TEST_BUILD
    #include <iostream>
#endif

class CommunicationDummyTest : public ICommunicationModule
{
public:
    CommunicationDummyTest() {
        #ifdef DEBUGGING_LARGE
            std::cout << "CommunicationDummyTest: Constructor." << std::endl;   
        #endif
        }

    ~CommunicationDummyTest()
    {
    #ifdef DEBUGGING_LARGE
        std::cout << "CommunicationDummyTest: Destructor." << std::endl;
    #endif
        // Nothing to delete...
    }

    bool init() 
    {
        #ifdef DEBUGGING_LARGE
            std::cout << "Communication Module Init." << std::endl;
        #endif
        return true;
    }
    
    void sendData(IData* data) 
    {
        unsigned char dataArray[SIZE_OF_DATA_ARRAY];
        data->getData(dataArray);
        #ifdef DEBUGGING_LARGE
            std::cout << "Data sent... " << std::endl; // << dataArray << std::endl;
        #endif
    }

    void receiveData(IData* data)
    {
        unsigned char dataArray[SIZE_OF_DATA_ARRAY] = {'D', '1', '2', '3', '4', '5', '6', '7'};
        data->setData(dataArray);
        
        #ifdef DEBUGGING_LARGE
            std::cout << "Data received... " << std::endl;
            for(int i = 0; i < SIZE_OF_DATA_ARRAY; i++) 
                std::cout << dataArray[i];
            std::cout << std::endl;
        #endif
    }
};