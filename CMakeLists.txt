cmake_minimum_required(VERSION 3.20)
project(cpp)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(container)
add_subdirectory(template)
add_subdirectory(functors)

message("PROJECT_BINARY_DIR is " ${PROJECT_BINARY_DIR})
