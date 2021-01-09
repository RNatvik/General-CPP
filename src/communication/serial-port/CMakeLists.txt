cmake_minimum_required(VERSION 3.19)
project(SerialPort VERSION 1.0.0)



# Simple include directory variant
#target_include_directories(math_library PUBLIC include)

# For installation of library (install "FILES" and "TARGETS" must be changed for new files corresponding to actual project)
# "EXT_SRC" can be changed and is the root installation folder.

SET(INST_INC ${EXP_INC}/${PROJECT_NAME})
SET(INST_LIB ${EXP_LIB}/${PROJECT_NAME})
# Import paths
set(ASIO_SRC F:/CLibs/asio-1.18.1) # Parent import folder for ASIO dependency



add_library(serial_port src/SerialPort.cpp include/SerialPort/SerialPort.h)
add_executable(example-serial_port examples/example.cpp)

# Installation compatible include directory variant
target_include_directories(
    serial_port PUBLIC
    $<INSTALL_INTERFACE:include>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)

target_include_directories(
    serial_port PUBLIC
    ${ASIO_SRC}/include
)

target_link_libraries(example-serial_port serial_port ws2_32)

install(
    FILES ${CMAKE_CURRENT_SOURCE_DIR}/include/SerialPort/SerialPort.h
    DESTINATION ${INST_INC}
)
install(
    TARGETS serial_port
    EXPORT export_serial_port
    DESTINATION ${INST_LIB}
)
install(
    EXPORT export_serial_port
    FILE ${PROJECT_NAME}-config.cmake
    DESTINATION ${INST_LIB}
)
