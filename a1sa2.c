// Create c program where the parent gets lower cpu prority then the child process using nice()

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

void main(){
    int pid, nicev;
    pid = fork();

    for(int i=0; i<5;i++){
        if(pid == 0){
            nicev = nice(-4);
            printf("This child process %d with parent proccess %d gets lower cpu priority %d \n",getpid(), getppid(), nicev);
            sleep(1);
        } else if(pid > 0){
            nicev = nice(4);
            printf("This parent proccess %d gets lower cpu priority %d \n", getpid(), nicev);
            sleep(1);
        } else {
            printf("Error creating process \n");
        }
    }
}