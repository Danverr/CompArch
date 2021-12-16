cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

project(task5 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)

set(BUILD_DIR "${CMAKE_BINARY_DIR}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${BUILD_DIR}/../bin")

set(BINARY_DIR "${CMAKE_BINARY_DIR}")

# Source files list
set(
    SOURCE_FILES

    # Sources
    src/main.cpp
)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")

add_executable(task5 ${SOURCE_FILES})
