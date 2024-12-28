cmake_minimum_required(VERSION 3.20)

project(STL)

file(GLOB_RECURSE SOURCES "src/*.cpp")
file(GLOB_RECURSE HEADERS "include/*.h")

include_directories(include)

add_executable(stl ${SOURCES} main.cpp)




