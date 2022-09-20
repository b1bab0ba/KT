#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(){
    pid_t fork_return = fork();
    if(fork_return > 0){
        printf(" I'm Process, my pid = %d, my ppid = %d, my child's pid: %d\n", getpid(), getppid(), fork_return);
    }
    else if(!fork_return){
            printf("I'm Child, my pid = %d, my ppid = %d\n", getpid(), getppid());
        }else{
            printf("Can't create child process\n");
            return -1;
            }
    return 0;
}
