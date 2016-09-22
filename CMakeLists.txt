cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

project(libre-engine)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${libre-engine_SOURCE_DIR}/cmake")


find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(GLEW REQUIRED)
find_package(Lua REQUIRED)

include_directories(${CMAKE_SOURCE_DIR}/include)

add_subdirectory(src)
