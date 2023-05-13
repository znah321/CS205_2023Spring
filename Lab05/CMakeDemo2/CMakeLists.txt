cmake_minimum_required(VERSION 3.10.2)

project(CMakeDemo2)

aux_source_directory(src DIR_SRC)

add_executable(CMakeDemo2 ${DIR_SRC})