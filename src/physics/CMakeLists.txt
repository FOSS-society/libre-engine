cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

project(libre-engine-physics)

file(GLOB sources *.cpp)
add_library(libre-engine-physics ${sources})
