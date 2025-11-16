cmake_minimum_required(VERSION 3.15)
project(fib C)

execute_process(
        COMMAND brew --prefix
        OUTPUT_VARIABLE BREW_PREFIX
        OUTPUT_STRIP_TRAILING_WHITESPACE
)
message(STATUS "Using Homebrew prefix: ${BREW_PREFIX}")

file(GLOB FIB_SOURCES "src/*.c")

add_library(fib SHARED ${FIB_SOURCES}
        src/bigint_utils.h
        src/bigint_utils.c
        src/fibonacci.h
        src/fibonacci.c)

set_target_properties(fib PROPERTIES
        OUTPUT_NAME "fib"
)

target_include_directories(fib PRIVATE ${BREW_PREFIX}/include)
target_link_directories(fib PRIVATE ${BREW_PREFIX}/lib)

target_link_libraries(fib PRIVATE gmp)
