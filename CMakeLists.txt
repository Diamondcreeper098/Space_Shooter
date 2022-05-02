cmake_minimum_required(VERSION 3.22)
project(Space_Shooter)

set(CMAKE_CXX_STANDARD 17)
if (DEFINED $ENV{SFML_ROOT})
    message(STATUS "SFML: $ENV{SFML_ROOT}")
    list(APPEND CMAKE_PREFIX_PATH "$ENV{SFML_ROOT}")
endif()


find_package(SFML 2.5.1 COMPONENTS window graphics audio REQUIRED)

add_executable(Space_Shooter main.cpp Application/Application.cpp Application/Application.h TextureManager.h GameObjects/Player.cpp GameObjects/Player.h GameObjects/Baddie.cpp GameObjects/Baddie.h GameObjects/Bullet.cpp GameObjects/Bullet.h GameStates.h)

target_link_libraries(Space_Shooter sfml-window sfml-graphics sfml-audio)