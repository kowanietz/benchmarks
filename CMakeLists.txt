cmake_minimum_required(VERSION 3.15)
project(performance_bench C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O3 -march=native -fPIC")

add_subdirectory(fibonacci)
add_subdirectory(matmul)
