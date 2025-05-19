cmake_minimum_required(VERSION 3.0.0)
project(Network VERSION 0.1.0 LANGUAGE C CXX)

include(CTest)
enable_testing()

add_executable(Network network/tcp_server.cpp)

set_property(TARGET Network PROPERTY CXX_STANDARD 17)