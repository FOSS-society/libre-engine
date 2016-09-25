cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

project(libre-engine)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${libre-engine_SOURCE_DIR}/cmake")


include_directories(${CMAKE_SOURCE_DIR}/include)

add_subdirectory(src)
