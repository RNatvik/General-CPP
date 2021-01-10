cmake_minimum_required(VERSION 3.19)
project(GeneralLibrary VERSION 1.0.0)

SET(EXP_SRC F:/CLibs)
SET(EXP_INC ${EXP_SRC}/include)
SET(EXP_LIB ${EXP_SRC}/lib)
SET(CMAKE_INSTALL_PREFIX ${EXP_SRC})

add_subdirectory(src/data-structures)
add_subdirectory(src/timing)
add_subdirectory(src/communication)
add_subdirectory(src/regulation)
