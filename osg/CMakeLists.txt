cmake_minimum_required(VERSION 3.13)
project(osg)


set(CMAKE_CXX_STANDARD 11)


find_package( OpenThreads )
find_package( osg )
find_package( osgDB )
find_package( osgUtil )
find_package( osgViewer )

macro( config_project PROJNAME LIBNAME )
    include_directories( ${${LIBNAME}_INCLUDE_DIR} )
    target_link_libraries( ${PROJNAME} ${${LIBNAME}_LIBRARY} )
endmacro()

add_executable( osg main.cpp )
config_project( osg OPENTHREADS )
config_project( osg OSG )
config_project( osg OSGDB )
config_project( osg OSGUTIL )
config_project( osg OSGVIEWER )