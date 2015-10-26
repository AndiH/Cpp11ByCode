cmake_minimum_required(VERSION 3.0)
project(Cpp11Examples)

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall -Wextra -Weverything")

add_executable(auto auto.cpp)
add_executable(rangeFor rangeFor.cpp)
add_executable(beginend beginend.cpp)
add_executable(initialization initialization.cpp)
add_executable(lambda lambda.cpp)
add_executable(array array.cpp)
add_executable(smartpointers smartpointers.cpp)
add_executable(classes classes.cpp)
add_executable(constexpr-static_assert constexpr-static_assert.cpp)

set_property(TARGET auto rangeFor beginend initialization lambda array smartpointers classes constexpr-static_assert PROPERTY CXX_STANDARD 11)
set_property(TARGET auto rangeFor beginend initialization lambda array smartpointers classes constexpr-static_assert PROPERTY CXX_STANDARD_REQUIRED ON)
