cmake_minimum_required(VERSION 3.0.0)
project(sort VERSION 0.1.0)
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

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)


