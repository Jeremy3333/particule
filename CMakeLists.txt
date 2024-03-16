cmake_minimum_required(VERSION 3.28)
project(particule)

set(CMAKE_CXX_STANDARD 17)

# Find SDL2 library
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

# Add executable
add_executable(particule main.cpp)
target_link_libraries(particule ${SDL2_LIBRARIES})
