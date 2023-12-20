cmake_minimum_required(VERSION 3.10)
project(LR5FILATOV)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(LR5FILATOV
        main.cpp
)

enable_testing()
add_executable(test001
        test/test001.cpp
)
target_link_libraries(test001 ${GTEST_LIBRARIES})

add_test(NAME BASIC COMMAND tests05)