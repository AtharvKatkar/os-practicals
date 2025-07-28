// orphan process by killing its parent

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

void main(){
    int pid;
    pid = fork();

    if(pid == 0){
        printf("This is a child process with id %d and its parent id %d \n", getpid(), getppid());
        sleep(4);
        printf("This is a orphan child process with id %d and its parent id %d \n", getpid(), getppid());
    } else if(pid > 0){
        printf("This is a parent process with id %d \n", getpid());
    } else {
        printf("Error forking process \n");
    }
}