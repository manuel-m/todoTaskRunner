cmake_minimum_required(VERSION 3.0)

#CPP with node.js toolchain
project (todocpp)
set(_ROOT ${CMAKE_CURRENT_SOURCE_DIR}/..)

include_directories(include)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread")

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${_ROOT}/out/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${_ROOT}/out/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${_ROOT}/out/bin)

set (_DEBUG "")

if (CMAKE_BUILD_TYPE MATCHES Debug)
    set (_DEBUG "${_DEBUG}_d")
endif (CMAKE_BUILD_TYPE MATCHES Debug)

add_subdirectory(libs)

if (CMAKE_BUILD_TYPE MATCHES Debug)
  add_subdirectory(tests)
endif (CMAKE_BUILD_TYPE MATCHES Debug)

add_executable(todocpp${_DEBUG} main.cpp)

target_link_libraries(todocpp${_DEBUG} tdl)

