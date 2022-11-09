#pragma once
#include "Types.h"

#include <gmock/gmock.h>
#include <gtest/gtest.h>

using namespace testing;

class FComm
{
public:
    MOCK_METHOD(void, Subscribe, (SubscriptionFunction Callback));
};