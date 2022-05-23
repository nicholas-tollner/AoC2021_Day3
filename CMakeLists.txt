# System
cmake_minimum_required(VERSION 3.21)
set(CMAKE_CXX_STANDARD 14)

# Project
project(AoC2021_Day3)
set(source_files src/main.cpp src/Functions.cpp)
file(GLOB text_files "*.txt")

# Build
add_executable(${CMAKE_PROJECT_NAME} ${source_files})
file(COPY ${text_files} DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

# target_link_libraries()
