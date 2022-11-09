# Prerequisites
Unreal Engine must reside in *../epic/unreal-engine* relative to this folder

# Preparation
First generate the **xxxxx.generated.h** files and the **Definitions.xxxxx.h** files. This is done by building the project

Build project, run
```
./scripts/build.py
```
(the cook will fail. But that is not important at this point. It's just this example not being a complete project)

# Build the tests

```
cd cmake_gtest/Test
rm -rf build/ ; mkdir build ; cmake -S ./ -B ./build ; cd build ; make
```

## Run the tests

### AExampleTestFakeMockedViewModel
This test uses a completely fake version of our viewmodel. Normally, the viewmodel would be an actor object which holds the properties our views use.

Run this test
```
./Unit/AExampleTestFakeMockedViewModel/AExampleTestFakeMockedViewModel
```

This works just fine.

### AExampleTestGMockedViewModel
In this test we try to use the header of the true viewmodel and mock the definition of the methods, as you normally do in GTest.

Run this test
```
./Unit/AExampleTestGMockedViewModel/AExampleTestGMockedViewModel
```

This test fail with following message
```
Failed to find symbol file, expected location:
"/home/pmattss6/repos/ihu5/qnx/apps/qnx_ap/mvendor/cmake_gtest_example/cmake_gtest/Test/build/Unit/AExampleTestGMockedViewModel/AExampleTestGMockedViewModel.sym"
Fatal error: [File:/home/jramstra/unreal/perforce/Partner-Freya-QNX-4.25/Engine/Source/Runtime/CoreUObject/Private/UObject/UObjectGlobals.cpp] [Line: 2522] 
None is not being constructed with NewObject.
fish: “./Unit/AExampleTestGMockedViewM…” terminated by signal SIGSEGV (Address boundary error)
```
(if you use Bash, the last line will be `Segmentation fault (core dumped)`)

Call stack
```
libUE4Editor-CoreUObject.so![Unknown/Just-In-Time compiled code] (Unknown Source:0)
libUE4Editor-CoreUObject.so!UObject::UObject() (Unknown Source:0)
libUE4Editor-Engine.so!AActor::AActor() (Unknown Source:0)
AAExampleViewModel::AAExampleViewModel() (Unknown Source:0)
AAExampleViewModelMock::AAExampleViewModelMock() (Unknown Source:0)
AExampleTestNoMockedViewModel_JustForShow_Test::TestBody() (Unknown Source:0)
void testing::internal::HandleSehExceptionsInMethodIfSupported<testing::Test, void>(testing::Test*, void (testing::Test::*)(), char const*) (Unknown Source:0)
void testing::internal::HandleExceptionsInMethodIfSupported<testing::Test, void>(testing::Test*, void (testing::Test::*)(), char const*) (Unknown Source:0)
testing::Test::Run() (Unknown Source:0)
testing::TestInfo::Run() (Unknown Source:0)
testing::TestSuite::Run() (Unknown Source:0)
testing::internal::UnitTestImpl::RunAllTests() (Unknown Source:0)
bool testing::internal::HandleSehExceptionsInMethodIfSupported<testing::internal::UnitTestImpl, bool>(testing::internal::UnitTestImpl*, bool (testing::internal::UnitTestImpl::*)(), char const*) (Unknown Source:0)
bool testing::internal::HandleExceptionsInMethodIfSupported<testing::internal::UnitTestImpl, bool>(testing::internal::UnitTestImpl*, bool (testing::internal::UnitTestImpl::*)(), char const*) (Unknown Source:0)
testing::UnitTest::Run() (Unknown Source:0)
RUN_ALL_TESTS() (Unknown Source:0)
main (Unknown Source:0)
```

### AExampleTestRealViewModel
Since viewmodels can have their own logic, we would prefer to be able to not have to mock these. In this test we try to build everything with the true viewmodel class.

Run this test
```
./Unit/AExampleTestRealViewModel/AExampleTestRealViewModel
```

This test fail with following message
```
fish: “./Unit/AExampleTestRealViewMode…” terminated by signal SIGSEGV (Address boundary error)
```
(if you use Bash, the message will be `Segmentation fault (core dumped)`)

Call stack
```
libc.so.6!__memmove_avx_unaligned_erms() (/build/glibc-SzIz7B/glibc-2.31/sysdeps/x86_64/multiarch/memmove-vec-unaligned-erms.S:262)
libUE4Editor-Core.so!FName::ToString(FString&) const (Unknown Source:0)
[Unknown/Just-In-Time compiled code] (Unknown Source:0)
```

---
## Our questions
## Generating x.generated.h and Definitions.x.h files
Is it possible to generate the **x.generated.h** and **Definitions.x.h** files without the need of building the project? Is there a easy way to set what the definitions should be defined to when the Definitions file get generated?

## Generate .sym file manually
The **AExampleTestGMockedViewModel** complains about a missing **AExampleTestGMockedViewModel.sym** file. Is there any way for us to generate this file? Or is there any configuration we can do to ignore the existence of this? Is the file only containing debug symbols, or what is it used for?

## Segfault when trying to build tests that include Actors.
Our **AExampleTestGMockedViewModel** and **AExampleTestRealViewModel** seems to segfault due to inclusion of the Engine, which seems to be obligatory when having a class that inherits from AActor. Why is the tests crashing? Is there anyway we could build our Actor classes and still have `#define WITH_ENGINE 0`? We tried to do this, but got `error: ‘virtual UWorld* AActor::GetWorld() const’ marked ‘override’, but does not override`

## Is it possible to hook up to the Broadcast programatically?
In **AExampleViewModel.cpp** we do a `OnAExampleUpdated.Broadcast(AExampleState)`. If we would get the **AExampleTestRealViewModel** to execute correctly, would it be possible for us to hook up to that broadcast in our test? That would be great for us since that would enable us to easily test the interface between our Cpp code and the game world.

## Definition file must be added to "random" files when building tests
For some reason we need to add the **Definitions.ModuleA.h** to **Structs.h**, **AExampleViewModel.h** and **AExampleBase.h** when building the tests. We can's seem to figure out why. It is not needed in these files when building the project (Which is why we have an empty **Defines.h** included for the project and another **Defines.h** pointed out when we build the tests.). Why is this? What are we missing? 