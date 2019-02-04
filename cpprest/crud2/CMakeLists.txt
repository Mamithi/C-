cmake_minimum_required(VERSION 3.13)
project(crud2)

set(CMAKE_CXX_STANDARD 11)

link_libraries(ssl crypto boost_system cpprest)

add_executable(crud2 main.cpp Main.h)