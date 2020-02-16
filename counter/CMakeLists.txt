cmake_minimum_required(VERSION 3.16.2)

set(CMAKE_BUILD_TYPE Debug)
project(hello_world)

link_directories( $ENV{SYSTEMC_HOME}/lib ./ )
include_directories( $ENV{SYSTEMC_HOME}/include )

add_executable(sim design.cpp testbench.cpp)
target_link_libraries(sim systemc)
