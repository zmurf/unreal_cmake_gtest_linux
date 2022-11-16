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
Linking problems

### AExampleTestRealViewModel
Linking problems

### AExampleTestRealViewModelFromLibs
This test tries to use the prebuilt ModuleA and ModuleB libs

---
## Our questions
## Generating x.generated.h and Definitions.x.h files
Is it possible to generate the **x.generated.h** and **Definitions.x.h** files without the need of building the project? Is there a easy way to set what the definitions should be defined to when the Definitions file get generated?

## Generate .sym file manually
The **AExampleTestRealViewModelFromLibs** complains about a missing **AExampleTestRealViewModelFromLibs.sym** file. Is there any way for us to generate this file? Or is there any configuration we can do to ignore the existence of this? Is the file only containing debug symbols, or what is it used for?

## Segfault when trying to build tests that include Actors.
**AExampleTestRealViewModelFromLibs** gets segmentation fault. Seems like we can't crate UObjects from tests.

## Is it possible to hook up to the Broadcast programatically?
In **AExampleViewModel.cpp** we do a `OnAExampleUpdated.Broadcast(AExampleState)`. If we would get the **AExampleTestRealViewModel** to execute correctly, would it be possible for us to hook up to that broadcast in our test? That would be great for us since that would enable us to easily test the interface between our Cpp code and the game world.

## Definition file must be added to "random" files when building tests
For some reason we need to add the **Definitions.ModuleA.h** to **Structs.h**, **AExampleViewModel.h** and **AExampleBase.h** when building the tests. We can's seem to figure out why. It is not needed in these files when building the project (Which is why we have an empty **Defines.h** included for the project and another **Defines.h** pointed out when we build the tests.). Why is this? What are we missing? 