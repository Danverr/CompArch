cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

project(task2 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)

set(BUILD_DIR "${CMAKE_BINARY_DIR}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${BUILD_DIR}/../bin")

set(BINARY_DIR "${CMAKE_BINARY_DIR}")

# Source files list
set(
    SOURCE_FILES

    # Headers
    src/number/number.h
    src/container/container.h
    src/complex/complex.h
    src/random/random.h
    src/fraction/fraction.h
    src/polar/polar.h

    # Sources
    src/main.cpp
    src/container/container.cpp
    src/complex/complex.cpp
    src/random/random.cpp
    src/polar/polar.cpp
    src/fraction/fraction.cpp
)

add_executable(task2 ${SOURCE_FILES})
