# System
cmake_minimum_required(VERSION 3.21)
set(CMAKE_CXX_STANDARD 14)

# Project
project(AoC2021_Day3)
set(source_files src/main.cpp)

# Build
add_executable(${CMAKE_PROJECT_NAME} ${source_files})
# target_link_libraries()
