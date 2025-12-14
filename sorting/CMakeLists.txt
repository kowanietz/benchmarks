cmake_minimum_required(VERSION 3.15)
project(sorting CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB SORTING_SOURCES "src/*.cpp")

add_library(sorting SHARED ${SORTING_SOURCES}
        src/bubble_sort_naive.cpp
)

set_target_properties(sorting PROPERTIES OUTPUT_NAME "sorting")
