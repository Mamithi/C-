cmake_minimum_required(VERSION 3.13)
project(basic_geometry)

set(CMAKE_CXX_STANDARD 11)

link_libraries(OpenThreads osg osgDB osgUtil osgViewer osgGA)

add_executable(basic_geometry main.cpp)