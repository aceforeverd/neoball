cmake_minimum_required(VERSION 3.8)
project(Ball)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        main.cpp
        Makefile Util.cc View.cpp View.hpp Ball.cpp Ball.hpp Ground.cpp Ground.hpp)

add_executable(Ball ${SOURCE_FILES})