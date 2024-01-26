cmake_minimum_required(VERSION 3.27)
project(Clash)

set(CMAKE_CXX_STANDARD 17)

find_package(raylib 4.5.0 REQUIRED)

add_executable(Clash main.cpp
        src/dimension.cpp
        src/Character.cpp
        src/Character.h
)

target_link_libraries(Clash raylib)
