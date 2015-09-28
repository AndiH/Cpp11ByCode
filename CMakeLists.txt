cmake_minimum_required(VERSION 3.0)
project(Cpp11Examples)

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall -Wextra -Weverything")

add_executable(auto auto.cpp)
add_executable(rangeFor rangeFor.cpp)

set_property(TARGET auto rangeFor PROPERTY CXX_STANDARD 11)
set_property(TARGET auto rangeFor PROPERTY CXX_STANDARD_REQUIRED ON)
