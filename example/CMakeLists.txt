cmake_minimum_required(VERSION 2.8)
project(CattacombsTest)

include_directories(../include)
add_executable(CattacombsTest main.cpp)
target_link_libraries(CattacombsTest Cattacombs)
