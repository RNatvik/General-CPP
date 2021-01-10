cmake_minimum_required(VERSION 3.19)
project(Timer VERSION 1.0.0)

add_library(timer
    include/timer/AbstractTimer.h
    include/timer/MillisTimer.h
    include/timer/MicrosTimer.h
    src/AbstractTimer.cpp
    src/MillisTimer.cpp
    src/MicrosTimer.cpp
)
target_include_directories(
    timer PUBLIC
    $<INSTALL_INTERFACE:include>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)
target_link_libraries(timer PUBLIC run_clock)


add_executable(timer-example examples/example.cpp)
target_link_libraries(timer-example PUBLIC timer)
