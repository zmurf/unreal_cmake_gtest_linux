// TODO: Figure out why it isn't enough to include the Defines.h file here. Why do we need to add this file in AExampleBase.h and Structs.h?
#include "Defines.h"

#include "AExampleViewModel.h"

// Including Mock version of Comm
#include "Comm.h"
#include "CommMock.h"

#include "AExample.h"
#include "AExampleModel.h"

#include "Templates/UniquePtr.h"

#include <gtest/gtest.h>

TEST(AExampleTest, JustForShow)
{
    TUniquePtr<FCommMock> CommMock = MakeUnique<FCommMock>();
    SubscriptionFunction CallBack{};
    EXPECT_CALL(*CommMock, Subscribe(testing::_))
            .WillOnce(DoAll(SaveArg<0>(&CallBack)));

    FAExample AExample{*CommMock};

    UObject Outer{};
    auto AExampleViewModel = NewObject<AAExampleViewModel>(&Outer, AAExampleViewModel::StaticClass());
    FAExampleModel AExampleModel{AExample, AExampleViewModel};

    FAExampleStruct const ExpectedResult{15,18};
    
    CallBack({15,18});
}
