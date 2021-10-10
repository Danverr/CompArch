# set minimum cmake version
cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

# project name and language
project(task1 LANGUAGES CXX)

set(BUILD_DIR "${CMAKE_BINARY_DIR}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${BUILD_DIR}/../bin")

set(BINARY_DIR "${CMAKE_BINARY_DIR}")

# Source files list
set(SOURCE_FILES
    # Headers
        number.h
    container.h

    # Sources
        number.cpp
    container.cpp
    main.cpp
        complex.h complex.cpp random.h random.cpp fraction.h polar.h polar.cpp fraction.cpp)

add_executable(task01 ${SOURCE_FILES})
