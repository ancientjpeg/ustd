cmake_minimum_required(VERSION 3.5)
project(ustd)

set(TOP_LEVEL_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)


add_library(ustd INTERFACE)

set_target_properties(ustd PROPERTIES LINKER_LANGUAGE CXX CXX_STANDARD 17)
target_include_directories(ustd INTERFACE ${TOP_LEVEL_INCLUDE_DIR})

add_subdirectory(tests)
