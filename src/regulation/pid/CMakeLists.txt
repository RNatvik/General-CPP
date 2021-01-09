cmake_minimum_required(VERSION 3.19)
project(PID VERSION 1.0.0)

add_library(pid src/PIDController.cpp include/pid/PIDController.h)
target_include_directories(
    pid PUBLIC
    $<INSTALL_INTERFACE:include>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)

add_executable(test examples/test.cpp)