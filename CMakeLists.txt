cmake_minimum_required(VERSION 3.5)

project(typeid_object LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(typeid_object main.cpp typed.h)

install(TARGETS typeid_object
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
