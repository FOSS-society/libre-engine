cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

project(libre-engine)

include_directories(${CMAKE_SOURCE_DIR}/include)
set(CMAKE_CXX_FLAGS "-std=c++11")
file(GLOB CORE "src/core/*.cpp" "include/core/*.hpp")
file(GLOB GRAPHICS "src/graphics/*.cpp" "include/graphics/*.hpp")
file(GLOB MATH "src/math/*.cpp" "include/math/*.hpp")
file(GLOB PHYSICS "src/physics/*.cpp" "include/physics/*.hpp")
file(GLOB SCRIPT "src/script/*.cpp" "include/script/*.hpp")
file(GLOB SYSTEM "src/system/*.cpp" "include/system/*.hpp")
file(GLOB ASSET "src/asset/*.cpp" "include/asset/*.hpp")
file(GLOB FF "src/system/fformats/*.cpp" "include/system/fformats/*.hpp")
file(GLOB OTHER "src/*cpp" "include/*.hpp")
add_library(libre-engine ${CORE} ${GRAPHICS} ${MATH} ${PHYSICS} ${SCRIPT} ${SYSTEM} ${ASSET} ${FF} ${OTHER})


install (TARGETS libre-engine DESTINATION lib)
install (DIRECTORY include/core include/graphics include/math include/physics include/script include/system include/asset include/ DESTINATION include/libre-engine)
