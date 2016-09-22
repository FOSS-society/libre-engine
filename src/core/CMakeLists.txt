cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

project(libre-engine-core)

file(GLOB sources *.cpp)
add_library(libre-engine-core ${sources})
