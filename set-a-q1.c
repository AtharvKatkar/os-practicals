// create child and parent process and print respective process

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

void main()
{
    int pid;
    pid = fork();

    if (pid == 0)
    {
        printf("This is a child process with id %d and its parent id is %d\n", getpid(), getppid());
    }
    else if (pid > 0)
    {
        printf("This is a parent process with its id %d\n", getpid());
    }
    else
    {
        printf("Error creating process \n");
    }
}