cmake_minimum_required(VERSION 3.4...3.18)
project(cmake_example)

add_library(math_lib STATIC src/math_lib.cpp)
set_target_properties(math_lib PROPERTIES POSITION_INDEPENDENT_CODE ON)

add_subdirectory(pybind11)
pybind11_add_module(cmake_example src/binder.cpp)
target_link_libraries(cmake_example PRIVATE math_lib)

# EXAMPLE_VERSION_INFO is defined by setup.py and passed into the C++ code as a
# define (VERSION_INFO) here.
target_compile_definitions(cmake_example
                           PRIVATE VERSION_INFO=${EXAMPLE_VERSION_INFO})
