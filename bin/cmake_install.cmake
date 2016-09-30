# Install script for directory: /home/clim/Desktop/Clim's Files/Programming/cpp/libreEngine

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "/home/clim/Desktop/Clim's Files/Programming/cpp/libreEngine/bin/liblibre-engine.a")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/libre-engine" TYPE DIRECTORY FILES
    "/home/clim/Desktop/Clim's Files/Programming/cpp/libreEngine/include/core"
    "/home/clim/Desktop/Clim's Files/Programming/cpp/libreEngine/include/graphics"
    "/home/clim/Desktop/Clim's Files/Programming/cpp/libreEngine/include/math"
    "/home/clim/Desktop/Clim's Files/Programming/cpp/libreEngine/include/physics"
    "/home/clim/Desktop/Clim's Files/Programming/cpp/libreEngine/include/script"
    "/home/clim/Desktop/Clim's Files/Programming/cpp/libreEngine/include/system"
    "/home/clim/Desktop/Clim's Files/Programming/cpp/libreEngine/include/asset"
    )
endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

file(WRITE "/home/clim/Desktop/Clim's Files/Programming/cpp/libreEngine/bin/${CMAKE_INSTALL_MANIFEST}" "")
foreach(file ${CMAKE_INSTALL_MANIFEST_FILES})
  file(APPEND "/home/clim/Desktop/Clim's Files/Programming/cpp/libreEngine/bin/${CMAKE_INSTALL_MANIFEST}" "${file}\n")
endforeach()
