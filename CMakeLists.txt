cmake_minimum_required(VERSION 3.27)
project(Clash)

set(CMAKE_CXX_STANDARD 17)

find_package(raylib 4.5.0 REQUIRED)

add_executable(Clash main.cpp
        src/dimension.cpp
        src/Character.cpp
        src/Character.h
        src/Prop.cpp
        src/Prop.h
        src/Enemy.cpp
        src/Enemy.h
        src/BaseCharacter.cpp
        src/BaseCharacter.h
)

target_link_libraries(Clash raylib)
