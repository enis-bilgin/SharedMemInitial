include_directories(
        . # top level
)

set(SHMREADER_FILES
        shmreader.cpp
        )


add_executable(shmreader ${SHMREADER_FILES})

target_link_libraries(
        shmreader
        glog
)
