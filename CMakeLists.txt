cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

project(libre-engine)

include_directories(${CMAKE_SOURCE_DIR}/include)
set(CMAKE_CXX_FLAGS "-std=c++11")
file(GLOB CORE "src/core/*.cpp")
file(GLOB GRAPHICS "src/graphics/*.cpp")
file(GLOB MATH "src/math/*.cpp")
file(GLOB PHYSICS "src/physics/*.cpp")
file(GLOB SCRIPT "src/script/*.cpp")
file(GLOB SYSTEM "src/system/*.cpp")
add_library(libre-engine ${CORE} ${GRAPHICS} ${MATH} ${PHYSICS} ${SCRIPT} ${SYSTEM} )


install (TARGETS libre-engine DESTINATION lib)
install (DIRECTORY include/core include/graphics include/math include/physics include/script include/system DESTINATION include/libre-engine)
