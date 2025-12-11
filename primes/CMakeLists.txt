cmake_minimum_required(VERSION 3.15)
project(primes C)

file(GLOB PRIMES_SOURCES "src/*.c")

add_library(primes SHARED
        ${PRIMES_SOURCES}
)

set_target_properties(primes PROPERTIES OUTPUT_NAME "primes")
