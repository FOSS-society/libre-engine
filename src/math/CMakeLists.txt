cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

project(libre-engine-math)

file(GLOB sources *.cpp)
add_library(libre-engine-math ${sources})
