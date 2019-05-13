cmake_minimum_required(VERSION 3.13)
project(SimpleCppRest)

set(CMAKE_CXX_STANDARD 14)
link_libraries(ssl crypto boost_system cpprest)

add_executable(SimpleCppRest main.cpp)