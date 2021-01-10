cmake_minimum_required(VERSION 3.19)
project(TimingClock VERSION 1.0.0)

add_library(run_clock src/RunClock.cpp include/clock/RunClock.h)
target_include_directories(
    run_clock PUBLIC
    $<INSTALL_INTERFACE:include>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)

add_executable(runclock-test examples/test.cpp)
target_link_libraries(runclock-test run_clock)