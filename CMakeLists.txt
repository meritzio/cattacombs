cmake_minimum_required(VERSION 2.8)
project(Cattacombs)

include_directories("include")
file(GLOB src "src/*.cpp")

add_subdirectory("example")

add_library(Cattacombs ${src})
