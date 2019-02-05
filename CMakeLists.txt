cmake_minimum_required(VERSION 3.12)

include_directories(
        . # top level
)

project(sharedmemWriter)

set(CMAKE_CXX_STANDARD 14)


add_subdirectory(shmWriter)
add_subdirectory(shmReader)

