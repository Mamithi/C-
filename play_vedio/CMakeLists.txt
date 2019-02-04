cmake_minimum_required(VERSION 3.13)
project(play_vedio)

set(CMAKE_CXX_STANDARD 11)

link_libraries(vlc SDL2 SDL2_mixer SDL2_image SDL2_ttf)

add_executable(play_vedio main.cpp)