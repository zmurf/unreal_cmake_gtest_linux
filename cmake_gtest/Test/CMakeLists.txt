cmake_minimum_required(VERSION 3.15)
project(Test)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 14)

# Debugging purposes
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS_DEBUG "-O0")

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/../../external/googletest ${CMAKE_CURRENT_BINARY_DIR}/googletest)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/Unit/AExampleTestFakeMockedViewModel) # Working
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/Unit/AExampleTestGMockedViewModel) # Building. Not finding sym file. Terminated by signal SIGSEGV (Address boundary error)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/Unit/AExampleTestRealViewModel) # Building. Terminated by signal SIGSEGV (Address boundary error)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/Unit/AExampleTestRealViewModelFromLibs)