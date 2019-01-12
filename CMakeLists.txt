cmake_minimum_required(VERSION 3.8)
project(algorithm)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories("${PROJECT_SOURCE_DIR}/Graph")
include_directories("${PROJECT_SOURCE_DIR}/Utils")
add_subdirectory(Graph)
add_subdirectory(Utils)

add_executable(algorithm main.cpp)
target_link_libraries(algorithm Graph Utils)