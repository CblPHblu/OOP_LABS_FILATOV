cmake_minimum_required(VERSION 3.10)
project(LR3FILATOV)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(SCR include/Figure_array.h src/farray.cpp include/Point.h src/Point.cpp include/Figure.h src/Figure.cpp include/Square.h src/Square.cpp include/Rectangle.h src/Rectangle.cpp include/Trapezoid.h src/Trapezoid.cpp)

add_executable(LR3FILATOV main.cpp include/Figure_array.h src/Figure_array.cpp include/Point.h src/Point.cpp include/Figure.h src/Figure.cpp include/Square.h src/Square.cpp include/Rectangle.h src/Rectangle.cpp include/Trapezoid.h src/Trapezoid.cpp)

enable_testing()
add_executable(test001 test/test001.cpp include/Figure_array.h src/Figure_array.cpp include/Point.h src/Point.cpp include/Figure.h src/Figure.cpp include/Square.h src/Square.cpp include/Rectangle.h src/Rectangle.cpp include/Trapezoid.h src/Trapezoid.cpp)
target_link_libraries(test001 ${GTEST_LIBRARIES})

add_test(NAME BASIC COMMAND tests)