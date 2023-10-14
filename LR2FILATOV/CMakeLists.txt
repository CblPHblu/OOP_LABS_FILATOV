cmake_minimum_required(VERSION 3.22)

project(LR1FIALTOV)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(LR2FILATOV main.cpp src/Money.cpp)

enable_testing()
add_executable(test001 test/test001.cpp  src/Money.cpp)
target_link_libraries(test001 ${GTEST_LIBRARIES})

add_test(NAME BASIC COMMAND test001)