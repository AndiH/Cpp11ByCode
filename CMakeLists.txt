cmake_minimum_required(VERSION 3.0)
project(Cpp11Examples)

add_executable(auto auto.cpp)
set_property(TARGET auto PROPERTY CXX_STANDARD 11)
set_property(TARGET auto PROPERTY CXX_STANDARD_REQUIRED ON)
