// TODO: Figure out why it isn't enough to include the Defines.h file here. Why do we need to add this file in AExampleBase.h and Structs.h?
#include "Defines.h"

// Including Mock version of AExampleViewModel
#include "AExampleViewModelMock.h"
// Including Mock version of Comm
#include "Comm.h"
#include "CommMock.h"

#include "AExample.h"
#include "AExampleModel.h"

#include <gtest/gtest.h>

TEST(AExampleTestNoMockedViewModel, JustForShow)
{
    TUniquePtr<FCommMock> CommMock = MakeUnique<FCommMock>();
    SubscriptionFunction CallBack{};
    EXPECT_CALL(*CommMock, Subscribe(testing::_))
            .WillOnce(DoAll(SaveArg<0>(&CallBack)));

    FAExample AExample{*CommMock};
    
    UObject Outer{};
    auto AExampleViewModelMock = NewObject<AAExampleViewModelMock>(&Outer, AAExampleViewModelMock::StaticClass());
    FAExampleModel AExampleModel{AExample, AExampleViewModelMock};

    FAExampleStruct const ExpectedResult{15,18};

    FAExampleStruct Result{};
    EXPECT_CALL(*AExampleViewModelMock, SetState(testing::_)).WillOnce(DoAll(SaveArg<0>(&Result)));
    
    CallBack({15,18});

    EXPECT_EQ(Result.valueA, ExpectedResult.valueA);
    EXPECT_EQ(Result.valueB, ExpectedResult.valueB);
}
