cmake_minimum_required(VERSION 3.10)
project(Debugg3r)

include_directories(include)

add_executable(debug 
    main.cpp
    lib/debugger.cpp
    lib/breakpoint.cpp
    lib/linenoise.c
)

add_executable(test
    tests/test.cpp
)

set_target_properties(debug 
PROPERTIES OUTPUT_NAME "debug"
RUNTIME_OUTPUT_DIRECTORY
"${CMAKE_BINARY_DIR}/bin")

set_target_properties(test 
PROPERTIES OUTPUT_NAME "test"
RUNTIME_OUTPUT_DIRECTORY
"${CMAKE_BINARY_DIR}/bin")