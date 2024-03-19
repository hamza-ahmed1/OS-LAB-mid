#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h> // Added for exit()

int main()
{
    char *ptr;
    int fd;

    // 1- open shared mem obj
    fd = shm_open("OS", O_RDONLY, 0666);
    if (fd == -1) {
        perror("shm_open");
        exit(EXIT_FAILURE);
    }

    // 2-mapping memory
    ptr = (char*)mmap(NULL, 10 * sizeof(char), PROT_READ, MAP_SHARED, fd, 0);
    if (ptr == MAP_FAILED) {
        perror("mmap");
        exit(EXIT_FAILURE);
    }

    // 3-reading
    printf("%s", ptr);

    // 4-unmapping
    if (munmap(ptr, 10 * sizeof(char)) == -1) {
        perror("munmap");
        exit(EXIT_FAILURE);
    }

    // 5-close shared memory descriptor
    close(fd);

    return 0;
}
