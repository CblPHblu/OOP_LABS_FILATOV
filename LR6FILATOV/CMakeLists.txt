cmake_minimum_required(VERSION 3.22)
project(LR6FILATOV)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(main main.cpp npc.cpp observer.cpp outlaw.cpp orc.cpp werewolf.cpp)
enable_testing()
add_executable(tests tests.cpp npc.cpp observer.cpp outlaw.cpp orc.cpp werewolf.cpp)


target_link_libraries(tests ${GTEST_LIBRARIES})

add_test(NAME BASIC COMMAND tests)