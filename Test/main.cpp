#include "GoogleTest/googletest/googletest/src/gtest-all.cc"
#include "../src/Protocol/Include/Data.h"

#include <stdio.h>

TEST( Data, setMessage)
{
    IData* myDataPtr = new Data();
    myDataPtr->setMessage(ERROR_NO_ID_REGISTERED);

    char data[SIZE_OF_DATA_ARRAY];
    myDataPtr->getData(data);

    ASSERT_EQ(data[0], 'M');
    ASSERT_EQ((uint8_t)data[1], ERROR_NO_ID_REGISTERED);
}

int main( int argc, char* argv[] )
{
    testing::InitGoogleTest( &argc, argv );

    return RUN_ALL_TESTS();
}