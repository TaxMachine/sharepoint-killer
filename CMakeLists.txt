cmake_minimum_required(VERSION 3.26)
project(sharepoint_killer)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++23 -pthread")
set(SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(RESOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/resources)

file(GLOB_RECURSE SOURCE_FILES ${SOURCE_DIR}/*.*)
file(GLOB_RECURSE RESOURCE_FILES ${RESOURCE_DIR}/*.rc)

add_executable(sharepoint_killer ${SOURCE_FILES})

if (WIN32)
    target_sources(sharepoint_killer PRIVATE ${RESOURCE_FILES})
endif ()