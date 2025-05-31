cmake_minimum_required(VERSION 3.10)
include_directories(${CMAKE_SOURCE_DIR}/include)
#project(Network VERSION 0.1.0 LANGUAGE C CXX)

project(Network)

#include(CTest)
#enable_testing()
# Automatically include all the files inside src folder
file(GLOB_RECURSE SOURCE_FILES CONFIGURE_DEPENDS
    src/*.cpp)
# set(SOURCE_FILES
#         src/main.cpp
#         src/printer.cpp)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})

#set_property(TARGET Network PROPERTY CXX_STANDARD 17)