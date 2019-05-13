cmake_minimum_required(VERSION 3.13)
project(ui_test)

set(CMAKE_CXX_STANDARD 11)


set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
find_package(Qt5 COMPONENTS Core Gui Widgets REQUIRED)
SET(DASHBOARD_SRC
        window.cpp
        )
SOURCE_GROUP(DASHBOARD FILES ${DASHBOARD_SRC})
add_executable(${PROJECT_NAME} main.cpp ${DASHBOARD_SRC})
target_link_libraries(${PROJECT_NAME} Qt5::Core Qt5::Gui Qt5::Widgets)