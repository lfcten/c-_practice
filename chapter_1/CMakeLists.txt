cmake_minimum_required(VERSION 3.13)
project(chapter_1)

include_directories(src/include)
aux_source_directory(src/main dir_srcs)

set(CMAKE_CXX_STANDARD 11)

set(WORK ${dir_srcs} src/include/common.h src/include/string_util.h src/main/string_util.cpp src/include/index.h src/main/index.cpp)
add_executable(chapter_1 ${WORK})