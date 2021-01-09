cmake_minimum_required(VERSION 3.19)
project(SerialProtocol VERSION 1.0.0)


# For installation of library (install "FILES" and "TARGETS" must be changed for new files corresponding to actual project)
# "EXT_SRC" can be changed and is the root installation folder.

# Export / install path
SET(INST_INC ${EXP_INC}/${PROJECT_NAME})
SET(INST_LIB ${EXP_LIB}/${PROJECT_NAME})
SET(INTERNAL_INCLUDE ${CMAKE_CURRENT_SOURCE_DIR}/include/SerialProtocol)

add_library(serial_protocol 
    src/SerialMaster.cpp include/SerialProtocol/SerialMaster.h
    src/SerialSlave.cpp include/SerialProtocol/SerialSlave.h
)
target_link_libraries(serial_protocol PUBLIC
    data_register
    serial_port
)
# Installation compatible include directory variant
target_include_directories(
    serial_protocol PUBLIC
    $<INSTALL_INTERFACE:include>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)
add_executable(example-serial_protocol examples/example.cpp)
target_link_libraries(example-serial_protocol serial_protocol ws2_32)

install(
    FILES ${INTERNAL_INCLUDE}/SerialMaster.h ${INTERNAL_INCLUDE}/SerialSlave.h
    DESTINATION ${INST_INC}
)
install(
    TARGETS serial_protocol
    EXPORT export_serial_protocol
    DESTINATION ${INST_LIB}
)
install(
    EXPORT export_serial_protocol
    FILE ${PROJECT_NAME}-config.cmake
    DESTINATION ${INST_LIB}
)
