include_directories(
        . # top level
)

set(SHMWRITER_FILES
        shmwriter.cpp
)


add_executable(shmwriter ${SHMWRITER_FILES})
