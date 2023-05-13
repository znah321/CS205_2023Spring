cmake_minimum_required(VERSION 3.10.2)

project(exp5)

aux_source_directory(. DIR)

include_directories(.)

add_executable(exp5 ${DIR})