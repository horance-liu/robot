cmake_minimum_required(VERSION 3.2 FATAL_ERROR)

project(robot VERSION 1.0 LANGUAGES C CXX)

# global options
option(BUILD_TEST      "Set to ON to build tests"              ON)

# Set c++ standard to c++14.
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
message(STATUS "C++14 support has been enabled by default.")

# robot target
file(GLOB_RECURSE robot_srcs CONFIGURE_DEPENDS
    src/*.cpp
    src/*.cc
    src/*.c
)

add_library(robot ${robot_srcs})

target_include_directories(robot
    PUBLIC  include
    PRIVATE src
)

target_link_libraries(robot
    PRIVATE pub
)

add_subdirectory(pub)

if(BUILD_TEST)
    enable_testing()
    add_subdirectory(test)
endif(BUILD_TEST)