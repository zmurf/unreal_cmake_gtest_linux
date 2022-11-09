#pragma once

#include "AExampleViewModel.h"

#include <gmock/gmock.h>
#include <gtest/gtest.h>

using namespace testing;

class AAExampleViewModelMock : public AAExampleViewModel
{
public:
    MOCK_METHOD(void, SetState, (FAExampleStruct const state), (override));
    MOCK_METHOD(void, GetState, (FAExampleStruct &state), (override));    
};
