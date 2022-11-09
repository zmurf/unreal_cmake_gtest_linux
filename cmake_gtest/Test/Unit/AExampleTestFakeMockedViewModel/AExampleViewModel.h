#pragma once
#include "Structs.h"

#include <gmock/gmock.h>
#include <gtest/gtest.h>

using namespace testing;

class AAExampleViewModel
{
public:
    MOCK_METHOD(void, SetState, (FAExampleStruct const state));
    MOCK_METHOD(void, GetState, (FAExampleStruct &state));    
};