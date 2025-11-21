cmake_minimum_required(VERSION 3.15)
project(matmul C)

execute_process(
        COMMAND brew --prefix
        OUTPUT_VARIABLE BREW_PREFIX
        OUTPUT_STRIP_TRAILING_WHITESPACE
)
message(STATUS "Using Homebrew prefix: ${BREW_PREFIX}")

file(GLOB MATMUL_SOURCES "src/*.c")

add_library(matmul SHARED ${MATMUL_SOURCES}
        src/naive.c
)

set_target_properties(matmul PROPERTIES
        OUTPUT_NAME "matmul"
)

target_include_directories(matmul PRIVATE ${BREW_PREFIX}/include)
target_link_directories(matmul PRIVATE ${BREW_PREFIX}/lib)

target_link_libraries(matmul PRIVATE gmp)
