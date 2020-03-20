#include "GoogleTest/googletest/googletest/src/gtest-all.cc"
//#include "GoogleTest/googletest/googlemock/src/gmock-all.cc"
#include "../src/Protocol/Include/Data.h"
#include "../src/FunMRI/Include/FunMRI.h"

#include <stdio.h>

/** P R O T O C O L   T E S T S ********************************************************/
/*
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

TEST(Data, setIDdata_getData)
{
    // Arrange
    IData* uut_ = new Data();
    unsigned char IDdata[SIZE_OF_DATA_ARRAY] = {'1','2','3','4','5','6','7'};
    unsigned char IDDataFinal[SIZE_OF_DATA_ARRAY] = {'D','1','2','3','4','5','6','7'};

    // Act
    uut_->setIDdata(IDdata);
    unsigned char dataRead[SIZE_OF_DATA_ARRAY];
    uut_->getData(dataRead);

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

    // Assert
    ASSERT_EQ(isSame, true);
}
*/

/** M O C K   C L A S S E S ************************************************************/

// class MockFunMRI : public FunMRI
// {
//     // Public methods of FunMRI:
//     // void setState(IState &state);
//     // void scan(void);
//     // void playSound(void);
//     // void send(Data& data);
//     // void receive(Data& data);
//     // void chargingStatus(void);
//     // void initPressed(void);
//     // void scanPressed(void);
//     // void modeChanged(void);
//     // void microSwitchPressed(void);

//     // Mock methods of the above:
//     MOCK_METHOD1(setState, void(IState &state));
//     MOCK_METHOD0(scan, void());
//     MOCK_METHOD0(playSound,void());
//     MOCK_METHOD1(send, void(Data &data));
//     MOCK_METHOD1(receive(Data &data));
//     MOCK_METHOD0(chargingStatus, void());
//     MOCK_METHOD0(initPressed, void());
//     MOCK_METHOD0(scanPressed, void());
//     MOCK_METHOD0(modeChanged, void());
//     MOCK_METHOD0(microSwitchPressed, void());
// }



int main( int argc, char* argv[] )
{
    testing::InitGoogleTest( &argc, argv );

    return RUN_ALL_TESTS();
}