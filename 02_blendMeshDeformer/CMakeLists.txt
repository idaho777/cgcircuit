cmake_minimum_required(VERSION 3.0)

set(PROJECT_NAME blendMesh)
project(${PROJECT_NAME})

######### Maya #########
include($ENV{DEVKIT_LOCATION}/cmake/pluginEntry.cmake)
message("$ENV{DEVKIT_LOCATION}")

######### Workspace #########
set(WORKSPACE_INCLUDE "${CMAKE_SOURCE_DIR}/include")
include_directories(${WORKSPACE_INCLUDE})
message(STATUS "Include dis lib ${WORKSPACE_INCLUDE}")

######### Source #########
FILE(GLOB SRC_CPP "${CMAKE_SOURCE_DIR}/src/*.cpp")

set(SOURCE_FILES
    pluginMain.cpp
    ${SRC_CPP}
)

set(LIBRARIES
    OpenMaya
    OpenMayaUI
    OpenMayaAnim
    Foundation
)

build_plugin()