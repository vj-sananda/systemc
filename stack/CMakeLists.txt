cmake_minimum_required(VERSION 3.16.2)

set(CMAKE_BUILD_TYPE Debug)
project(stack)

link_directories( $ENV{SYSTEMC_HOME}/lib ./ )
include_directories( $ENV{SYSTEMC_HOME}/include )

add_executable(sim main.cpp)
target_link_libraries(sim systemc)
