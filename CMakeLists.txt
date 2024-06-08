cmake_minimum_required(VERSION 3.10)

# Set the project name
project(ImageResizer)

# Set the C standard
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED True)

# Specify the directories where the compiler should look for headers
include_directories(${PROJECT_SOURCE_DIR}/include)

# Add the executable
add_executable(resize_image src/resize_image.c)
