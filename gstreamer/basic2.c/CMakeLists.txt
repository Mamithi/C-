cmake_minimum_required(VERSION 3.13)
project(basic2_c C)
find_package(PkgConfig REQUIRED)

set(CMAKE_C_STANDARD 99)

include_directories(
        /usr/lib/x86_64-linux-gnu/glib-2.0/include
        /usr/include/glib-2.0
        /usr/local/include/gstreamer-1.0)


set(SOURCE_FILES main.cpp)

link_directories(${GSTLIBS_LIBRARY_DIRS})

add_executable(basic2_c main.c)

target_link_libraries(basic2_c ${GSTLIBS_LIBRARIES})
