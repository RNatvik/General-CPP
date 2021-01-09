cmake_minimum_required(VERSION 3.19)
project(DataRegister VERSION 1.0.0)

add_library(data_register src/DataRegister.cpp include/DataRegister/DataRegister.h)

add_executable(example-data_register examples/example.cpp)
target_include_directories(example-data_register PRIVATE include)
target_link_libraries(example-data_register data_register)

# Simple include directory variant
#target_include_directories(data_register PUBLIC include)

# For installation of library (install "FILES" and "TARGETS" must be changed for new files corresponding to actual project)
# "EXT_SRC" can be changed and is the root installation folder.



SET(INST_INC ${EXP_INC}/${PROJECT_NAME})
SET(INST_LIB ${EXP_LIB}/${PROJECT_NAME})


# Installation compatible include directory variant
target_include_directories(
    data_register PUBLIC
    $<INSTALL_INTERFACE:include>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)

install(
    FILES ${CMAKE_CURRENT_SOURCE_DIR}/include/DataRegister/DataRegister.h
    DESTINATION ${INST_INC}
)
install(
    TARGETS data_register
    EXPORT export_data_register
    DESTINATION ${INST_LIB}
)
install(
    EXPORT export_data_register
    FILE ${PROJECT_NAME}-config.cmake
    DESTINATION ${INST_LIB}
)
