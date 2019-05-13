cmake_minimum_required(VERSION 3.13)
project(osg_project)

set(CMAKE_CXX_STANDARD 11)

link_libraries(OpenThreads osg osgDB osgUtil osgViewer osgGA)

#find_package( OpenThreads )
#find_package( osg )
#find_package( osgDB )
#find_package( osgUtil )
#find_package( osgViewer )
#
#macro( config_project PROJNAME LIBNAME )
#    include_directories( ${${LIBNAME}_INCLUDE_DIR} )
#    target_link_libraries( ${PROJNAME} ${${LIBNAME}_LIBRARY} )
#endmacro()

add_executable( osg_project main.cpp )
#config_project( osg_project OPENTHREADS )
#config_project( osg_project OSG )
#config_project( osg_project OSGDB )
#config_project( osg_project OSGUTIL )
#config_project( osg_project OSGVIEWER )

