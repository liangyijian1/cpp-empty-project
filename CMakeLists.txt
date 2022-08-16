cmake_minimum_required(VERSION 3.1)

project(Complex)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/publish)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib) 

option(UNIT_TEST "UNIT_TEST" OFF)

FILE(GLOB_RECURSE EXECUTABLE_FILES 
    ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/*.c)

message(STATUS "UNIT_TEST:${UNIT_TEST}")

if(UNIT_TEST)
    list(REMOVE_ITEM EXECUTABLE_FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/main/main.cpp)
else()
    list(REMOVE_ITEM EXECUTABLE_FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/main/unitTest.cpp)
    list(REMOVE_ITEM EXECUTABLE_FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/catch.cpp)
endif()

message(STATUS "EXECUTABLE: ${EXECUTABLE_FILES}")

add_executable(Complex ${EXECUTABLE_FILES})

target_precompile_headers(Complex PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src/_pch_/pch.h)

MACRO(collect_head_dirs return_list)
    FILE(GLOB_RECURSE   new_list 
                        ${CMAKE_CURRENT_SOURCE_DIR}/src/*.h
                        ${CMAKE_CURRENT_SOURCE_DIR}/src/*.hpp
                        )
    SET(dir_list "")
    FOREACH(file_path ${new_list})
        GET_FILENAME_COMPONENT(dir_path ${file_path} PATH)
        SET(dir_list ${dir_list} ${dir_path})
    ENDFOREACH()
    LIST(REMOVE_DUPLICATES dir_list)
    SET(${return_list} ${dir_list})
ENDMACRO()

collect_head_dirs(src_header_dirs)
message(STATUS "src_header_dirs:${src_header_dirs}")

target_include_directories (Complex PUBLIC ${src_header_dirs} ${CMAKE_CURRENT_SOURCE_DIR}/deps)

