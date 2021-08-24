cmake_minimum_required (VERSION 3.10.0)
project (sort)
set (CMAKE_CXX_STANDARD 11)

file(GLOB_RECURSE SOURCE_FILES
    src/*.cpp
)

file(GLOB_RECURSE HEADER_FILES
    lib/*.cpp
)

include_directories(
    ./
)

add_executable(main main.cpp ${SOURCE_FILES} ${HEADER_FILES})