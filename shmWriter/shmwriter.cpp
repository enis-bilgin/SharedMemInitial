/**
 * Simple program demonstrating shared memory in POSIX systems.
 *
 * author: E.Bilgin
 */

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <unistd.h>
#include <cstring>
#include <fcntl.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <cerrno>
#include <string>

// Sleep
#include <chrono>
#include <thread>

// glog
#include <glog/logging.h>
#include <gflags/gflags.h>



int main(int argc, char *argv[])
{

    /*logging*/
    google::InitGoogleLogging(argv[0]);
    FLAGS_logtostderr = true;

    /* name of the shared memory object */
    const char* name = "OS";

    /*struct*/
    typedef struct special_message {
        char message1[20];
        char side;
        int integer1;
        int integer2;
    };

    /* the size (in bytes) of shared memory object */
    const int SIZE = sizeof(struct special_message);

    /*some message*/
    special_message some_message{};
    strcpy(some_message.message1, "ENISBILGIN");
    some_message.side	  = 'N';
    some_message.integer1 = 11223344;
    some_message.integer2 = -557788;

    /* shared memory file descriptor */
    int shm_fd;

    /* pointer to shared memory obect */
    void* ptr;

    /* create the shared memory object */
    shm_fd = shm_open(name, O_CREAT | O_RDWR, 0666);

    /* configure the size of the shared memory object */
    ftruncate(shm_fd, SIZE);

    /* memory map the shared memory object */
    ptr = (char*)mmap(0, SIZE, PROT_WRITE, MAP_SHARED, shm_fd, 0);


    /* write to the shared memory object */
    memcpy(ptr,&some_message,sizeof(struct special_message));

    std::this_thread::sleep_for(std::chrono::seconds(5));

    // Memory Copy
    strcpy(some_message.message1, "PEPETHEFROG");
    some_message.side	  = '*';
    some_message.integer1 = -22222222;
    some_message.integer2 = 33333333;

    // 2nd Time Copy
    memcpy(ptr,&some_message,sizeof(struct special_message));

    LOG(INFO) << "TRY TO READ MESSAGE";

//    std::this_thread::sleep_for(std::chrono::seconds(5));

    return 0;
}