cmake_minimum_required(VERSION 3.12)

include_directories(
        . # top level
)

project(sharedmemWriter)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS_DEBUG} -Wall -std=c++14 -pthread	-fPIC -w -O2")


add_subdirectory(shmWriter)
add_subdirectory(shmReader)
