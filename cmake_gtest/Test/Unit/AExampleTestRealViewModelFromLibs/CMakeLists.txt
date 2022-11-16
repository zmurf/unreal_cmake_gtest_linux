# trying based on https://gamedevtricks.com/post/going-commando/
set(TEST_NAME AExampleTestRealViewModelFromLibs)

add_definitions(
-DUE_BUILD_DEBUG=0
-DWITH_PLUGIN_SUPPORT=0
-DUBT_COMPILED_PLATFORM=Linux
-DPLATFORM_LINUX=1
-D_AMD64_
)

SET(CMAKE_CXX_FLAGS "-fno-rtti -Wno-error=invalid-offsetof -Wno-error=unused-local-typedefs -Wno-error=type-limits -Wno-error=unused-value -Wno-error=switch -Wno-error=extra -Wno-error=ignored-qualifiers -Wno-error=sign-compare -Wno-error=deprecated-copy -Wno-error=undef -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -Wno-error=int-in-bool-context -fPIC")

set(PROJECT_ROOT ${CMAKE_CURRENT_SOURCE_DIR}/../../..)
set(APPLICATIONS_ROOT ${PROJECT_ROOT}/../..)
set(UE_LINUX_LIBS ${APPLICATIONS_ROOT}/epic/unreal-engine/Engine/Binaries/Linux/)
set(UE_ENGINE ${APPLICATIONS_ROOT}/epic/unreal-engine/Engine/)
set(UE_ENGINE_SOURCE ${UE_ENGINE}/Source/)

include_directories(
    PUBLIC
    ${UE_ENGINE_SOURCE}/Runtime/InputCore/Classes/
    ${UE_ENGINE_SOURCE}/Runtime/Core/Public/
    ${UE_ENGINE_SOURCE}/Runtime/CoreUObject/Public/
    ${UE_ENGINE_SOURCE}/Runtime/TraceLog/Public/
    ${UE_ENGINE_SOURCE}/Runtime/Engine/Classes/
    ${UE_ENGINE_SOURCE}/Runtime/Engine/Public/
    ${UE_ENGINE_SOURCE}/Runtime/Net/Core/Public/
    ${UE_ENGINE_SOURCE}/Runtime/RHI/Public/
    ${UE_ENGINE_SOURCE}/Runtime/RenderCore/Public/
    ${UE_ENGINE_SOURCE}/Runtime/PhysicsCore/Public/
    ${UE_ENGINE_SOURCE}/Runtime/SlateCore/Public/
    ${UE_ENGINE_SOURCE}/Runtime/ApplicationCore/Public/
    ${UE_ENGINE_SOURCE}/Runtime/Slate/Public/
    ${UE_ENGINE_SOURCE}/Runtime/AudioMixerCore/Public/
    ${UE_ENGINE_SOURCE}/Editor/UnrealEd/Classes/
    ${UE_ENGINE_SOURCE}/Editor/UnrealEd/Public/
    ${UE_ENGINE_SOURCE}/Editor/PropertyEditor/Public/
    ${UE_ENGINE_SOURCE}/Editor/EditorStyle/Public/
    ${UE_ENGINE}/Intermediate/Build/Linux/B4D820EA/UE4Editor/Inc/Engine
    ${UE_ENGINE}/Intermediate/Build/Linux/B4D820EA/UE4Editor/Inc/InputCore
    ${UE_ENGINE}/Intermediate/Build/Linux/B4D820EA/UE4Editor/Inc/SlateCore
    ${UE_ENGINE}/Intermediate/Build/Linux/B4D820EA/UE4Editor/Inc/Slate
    ${UE_ENGINE}/Intermediate/Build/Linux/B4D820EA/UE4Editor/Inc/UnrealEd
)

link_directories(
    PUBLIC
    ${UE_LINUX_LIBS}
    ${UE_ENGINE}/Binaries/ThirdParty/PhysX3/Linux/x86_64-unknown-linux-gnu/
    ${PROJECT_ROOT}/Binaries/Linux/
)

# Test sources
add_executable(${TEST_NAME}
${CMAKE_CURRENT_SOURCE_DIR}/AExampleTest.cpp
)

target_include_directories(${TEST_NAME}
PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/../Defines
    ${CMAKE_CURRENT_SOURCE_DIR}/../Mock
    ${PROJECT_ROOT}/Source/common/ModuleB/FolderA/Public
    ${PROJECT_ROOT}/Source/common/ModuleB/FolderB/Public
    ${PROJECT_ROOT}/Source/common/ModuleB/FolderC/Public
    ${PROJECT_ROOT}/Source/common/ModuleB/FolderD/Public
    ${PROJECT_ROOT}/Source/common/ModuleA/Public
    ${PROJECT_ROOT}/Source/common/ModuleA/Public/AExample
    ${PROJECT_ROOT}/Source/common/ModuleA/Public/AExample/ViewModel
    ${PROJECT_ROOT}/Intermediate/Build/Linux/B4D820EA/UE4Editor/Inc/ModuleA
    ${PROJECT_ROOT}/Intermediate/Build/Linux/B4D820EA/UE4Editor/Development/ModuleA
)

target_link_libraries(${TEST_NAME}
PUBLIC
    UE4Editor-Engine
    UE4Editor-Core
    UE4Editor-CoreUObject
    UE4Editor-ModuleA
    UE4Editor-ModuleB
    gtest
    gtest_main
    gmock
)
