cmake_minimum_required(VERSION 3.10.2)

project(CMakeDemo3)

aux_source_directory(src DIR_SRCS)

include_directories(include)

add_executable(CMakeDemo3 ${DIR_SRCS})

