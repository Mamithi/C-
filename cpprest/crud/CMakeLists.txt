cmake_minimum_required(VERSION 3.13)
project(crud)

set(CMAKE_CXX_STANDARD 11)

link_libraries(ssl crypto boost_system cpprest)

add_executable(crud main.cpp Main.h)