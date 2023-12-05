cmake_minimum_required(VERSION 3.10)
project(LR4FILATOV)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(SCR src/Figure_array.h src/Point.h src/Figure.h src/Square.h src/Rectangle.h src/Trapezoid.h)

add_executable(LR4FILATOV main.cpp src/Figure_array.h src/Point.h src/Figure.h src/Square.h src/Rectangle.h src/Trapezoid.h)

enable_testing()
add_executable(test001 test/test001.cpp src/Figure_array.h src/Point.h src/Figure.h src/Square.h src/Rectangle.h src/Trapezoid.h)
target_link_libraries(test001 ${GTEST_LIBRARIES})

add_test(NAME BASIC COMMAND tests)