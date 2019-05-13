cmake_minimum_required(VERSION 3.8)
project(untitled)
find_package(PkgConfig REQUIRED)
pkg_check_modules(GSTLIBS REQUIRED
        gobject-2.0
        glib-2.0)

set(CMAKE_CXX_STANDARD 11)

include_directories(
        /usr/lib/x86_64-linux-gnu/glib-2.0/include
        /usr/include/glib-2.0
        /usr/local/include/gstreamer-1.0
        /usr/local/include/libsoup-2.4
        /usr/local/include/json-glib-1.0)

set(SOURCE_FILES main.cpp)

link_directories(${GSTLIBS_LIBRARY_DIRS})

add_executable(untitled ${SOURCE_FILES})

target_link_libraries(untitled ${GSTLIBS_LIBRARIES})
