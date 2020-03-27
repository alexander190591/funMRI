#include "GoogleTest/googletest/googletest/src/gtest-all.cc"
//#include "GoogleTest/googletest/googlemock/src/gmock-all.cc"
#include "../src/Protocol/Include/Data.h"
#include "../src/FunMRI/Include/FunMRI.h"
#include "../src/FunMRIFactory/Include/Implementations/TestFactory.h"

#include <stdio.h>

/** P R O T O C O L   T E S T S ********************************************************/

TEST(Data, setMessage_getData)
{
    IData* uut_ = new Data();
    uut_->setMessage(MSG_ERROR_NO_ID_REGISTERED);

    unsigned char data[SIZE_OF_DATA_ARRAY];
    uut_->getData(data);

    ASSERT_EQ(data[0], 'M');
    ASSERT_EQ((uint8_t)data[1], MSG_ERROR_NO_ID_REGISTERED);
}

TEST(Data, setData_getData)
{
    // Arrange
    IData* uut_ = new Data();
    unsigned char data[SIZE_OF_DATA_ARRAY] = {'D','1','2','3','4','5','6','7'};
    
    // Act
    uut_->setData(data);
    unsigned char dataRead[SIZE_OF_DATA_ARRAY];
    uut_->getData(dataRead);

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

    // Assert
    ASSERT_EQ(isSame, true);
}

TEST(Data, setIDdata_getData_isSame)
{
    // Arrange
    IData* uut_ = new Data();
    unsigned char IDdata[SIZE_OF_DATA_ARRAY] = {'1','2','3','4','5','6','7'};
    unsigned char IDDataFinal[SIZE_OF_DATA_ARRAY] = {'D','1','2','3','4','5','6','7'};

    // Act
    uut_->setIDdata(IDdata);
    unsigned char dataRead[SIZE_OF_DATA_ARRAY];
    uut_->getData(dataRead);

    // Assert
    ASSERT_EQ(uut_->isSame(dataRead, IDDataFinal), true);
    ASSERT_NE(uut_->isSame(dataRead, IDdata), true);
}

TEST(Data, isIDDataSame)
{
    // Arrange
    IData* uut_ = new Data();
    unsigned char IDdata[SIZE_OF_DATA_ARRAY] = {'1','2','3','4','5','6','7'};
    uut_->setIDdata(IDdata);
    ASSERT_TRUE(uut_->isIDDataSame(IDdata));
}

TEST(FunMRI, SoundDummyTest_playSound)
{
    // Arrange
    FunMRI* _uut = new FunMRI(new TestFactory());

    // Act
    _uut->playSound();

    // Assert: Check if cout matches...
}

// TEST(FunMRI, isIDSameAsInit)
// {
//     // Arrange
//     FunMRI* _uut = new FunMRI(new TestFactory());
    
//     unsigned char IDdata[SIZE_OF_DATA_ARRAY] = {'1','2','3','4','5','6','7'};
//     Data* tmpData = new Data();

//     // Act
//     tmpData->setIDdata(IDdata);

//     _uut->setData(tmpData);
    
//     // Assert
//     ASSERT_TRUE(_uut->isIDSameAsInit(IDdata));
// }

// TEST(FunMRI, CommunicationDummyTest_send)
// {
//     // Arrange
//     FunMRI* _uut = new FunMRI(new TestFactory());
//     unsigned char IDdata[SIZE_OF_DATA_ARRAY] = {'1','2','3','4','5','6','7'};
//     IData* dataToSend = new Data();
//     dataToSend->setIDdata(IDdata);

//     std::cout << "Test........................................" << std::endl;
//     // Act
//     _uut->send(dataToSend);
// }

TEST(FunMRI, Scan_test)
{
    // Arrange
    FunMRI* _uut = new FunMRI(new TestFactory());

    // Act
    _uut->scan();
}

// TEST(FunMRI, Data_EqualEqualOperator)
// {
//     FunMRI* myFunMRI = new FunMRI(new TestFactory());
//     IData* data = new Data();
//     data->setMessage(MSG_INFO_SOUND_PLAYED);
//     myFunMRI->setData(data);

//     IData* dataRead = myFunMRI->getData();

//     ASSERT_EQ(*data, *dataRead);
// }


int main( int argc, char* argv[] )
{
    testing::InitGoogleTest( &argc, argv );

    return RUN_ALL_TESTS();
}