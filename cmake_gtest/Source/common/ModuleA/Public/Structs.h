#pragma once
// TODO: This should not need to be here. Just here to make tests build.
#include "Defines.h"
#include "Structs.generated.h"

USTRUCT(BlueprintType, DisplayName = "A Example Struct", Category = " Interface|Mode")
struct FAExampleStruct
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 valueA;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 valueB;
};