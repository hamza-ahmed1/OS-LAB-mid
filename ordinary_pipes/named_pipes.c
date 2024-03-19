#include<unistd.h>
#include<stdio.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<string.h>
#include<wait.h>
#define WRITING_END 1
#define READING_END 0

int main()
{
    int fd[2], n;
    char write_msg[11] = "HelloWorld";
    char read_msg[11];

    if (pipe(fd) == -1)
    {
        printf("Error while creating a pipe");
        return 1;
    }

    pid_t p = fork();
    if (p < 0)
    {
        printf("error while creating a child process!");
        return 1;
    }
    if (p == 0)
    {
        close(fd[READING_END]);
        printf("Parent is writing ...\n");
        int n = write(fd[WRITING_END], write_msg, strlen(write_msg));
        printf("parent wrote %d words\n", n);
        close(fd[WRITING_END]);
    }
    else
    {
        wait(NULL);
        close(fd[WRITING_END]);
        printf("Parent is reading ...\n");
        int n = read(fd[READING_END], read_msg, sizeof(read_msg));
        printf("Parent rode %d words \n", n);
        printf("%s ", read_msg);
        close(fd[READING_END]);
    }
    return 0;
}
