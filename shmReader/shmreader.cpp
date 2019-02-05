/**
 * Simple program demonstrating shared memory in POSIX systems.
 * E.Bilgin
 */

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <fcntl.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <cstring>
#include <cstring>

#include <unistd.h>
#include <sys/types.h>
#include <cerrno>

// glog
#include <glog/logging.h>
#include <gflags/gflags.h>



int main(int argc, char *argv[])
{
    /*logging*/
    google::InitGoogleLogging(argv[0]);
    FLAGS_logtostderr = true;

    /*struct*/
    typedef struct special_message {
        char message1[20];
        char side;
        int integer1;
        int integer2;
    };

    /* the size (in bytes) of shared memory object */
    const int SIZE = sizeof(struct special_message);

    /* name of the shared memory object */
    const char* name = "OS";

    /* shared memory file descriptor */
    int shm_fd;

    /* pointer to shared memory object */
    void* ptr;

    /* open the shared memory object */
    shm_fd = shm_open(name, O_RDONLY, 0666);

    /* memory map the shared memory object */
    ptr = mmap(0, SIZE, PROT_READ, MAP_SHARED, shm_fd, 0);

    /* read from the shared memory object */
    const auto obj_ptr = static_cast<special_message* >(ptr);

    //std::string abc(obj_ptr->message1);

    LOG(INFO) << "FIRST " << obj_ptr->message1;
    LOG(INFO) << "SIDEE " << obj_ptr->side;
    LOG(INFO) << "SECND " << obj_ptr->integer1;
    LOG(INFO) << "THRDD " << obj_ptr->integer2;

    /* remove the shared memory object */
    shm_unlink(name);

    return 0;
}