cmake_minimum_required(VERSION 3.25)

# Project name and version
project(voxel-engine VERSION 1.0 LANGUAGES CXX)

# C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# compile_commands.json generation
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Source files
file(GLOB SOURCES src/*.cpp)

# NOTE : Modules maybe ?

# Raylib
find_package(raylib REQUIRED)


# Executable
add_executable(${PROJECT_NAME} ${SOURCES})

# Output binary to bin/
set_target_properties(${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

# Linking libraries 
target_link_libraries(${PROJECT_NAME} PRIVATE raylib) 
