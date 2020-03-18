#include "GoogleTest/googletest/googletest/src/gtest-all.cc"
#include "../src/Protocol/Include/Data.h"

#include <stdio.h>


TEST(Data, setMessage_getData)
{
    IData* myDataPtr = new Data();
    myDataPtr->setMessage(ERROR_NO_ID_REGISTERED);

    char data[SIZE_OF_DATA_ARRAY];
    myDataPtr->getData(data);

    ASSERT_EQ(data[0], 'M');
    ASSERT_EQ((uint8_t)data[1], ERROR_NO_ID_REGISTERED);
}

TEST(Data, setData_getData)
{
    IData* myDataPtr = new Data();
    char data[SIZE_OF_DATA_ARRAY] = {'D','1','2','3','4','5','6','7'};
    myDataPtr->setData(data);
    char dataRead[SIZE_OF_DATA_ARRAY];
    myDataPtr->getData(dataRead);

    bool isSame = false;
    for(int i = 0; i < SIZE_OF_DATA_ARRAY; i++)
    {
        //std::cout << " data[" << i << "]: "<< data[i] << ". dataRead[" << i << "]: " << dataRead[i] << std::endl; // For visual testing...
        if(data[i] == dataRead[i])
            isSame = true;
        else
        {
            isSame = false;
            break;
        }
    }   
    ASSERT_EQ(isSame, true);
}

TEST(Data, setIDdata_getData)
{
    IData* myDataPtr = new Data();
    char IDdata[SIZE_OF_DATA_ARRAY] = {'1','2','3','4','5','6','7'};
    char IDDataFinal[SIZE_OF_DATA_ARRAY] = {'D','1','2','3','4','5','6','7'};
    myDataPtr->setIDdata(IDdata);
    char dataRead[SIZE_OF_DATA_ARRAY];
    myDataPtr->getData(dataRead);

    bool isSame = false;
    for(int i = 0; i < SIZE_OF_DATA_ARRAY; i++)
    {
        //std::cout << " IDDataFinal[" << i << "]: "<< IDDataFinal[i] << ". dataRead[" << i << "]: " << dataRead[i] << std::endl; // For visual testing...
        if(IDDataFinal[i] == dataRead[i])
            isSame = true;
        else
        {
            isSame = false;
            break;
        }
    }   
    ASSERT_EQ(isSame, true);
}

int main( int argc, char* argv[] )
{
    testing::InitGoogleTest( &argc, argv );

    return RUN_ALL_TESTS();
}