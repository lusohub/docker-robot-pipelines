cmake_minimum_required(VERSION 3.10)
project(robot_sim)

set(CMAKE_CXX_STANDARD 17)

include_directories(${PROJECT_SOURCE_DIR})

add_executable(robot robot.cpp)

enable_testing()
find_package(GTest REQUIRED)

add_executable(runTests tests/test_robot.cpp)
target_link_libraries(runTests GTest::GTest GTest::Main pthread)

add_test(NAME RobotTests COMMAND runTests)