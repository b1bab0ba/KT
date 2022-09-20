#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

#define BUF_SIZE 1000
int main(){
    
    int pipefd[2] = {};
    pipe(pipefd);
    int fork_return = fork();
    if(fork_return > 0){
        char* message = "Hello from parent!";
        write(pipefd[1], message, strlen(message));
    }else if(fork_return == 0){
        char* buf = calloc(BUF_SIZE, sizeof(char));
        read(pipefd[0], buf, BUF_SIZE);
        printf("I have received this text from parent: %s\n", buf);
    }else{
        printf("CAN'T FORK THE PROCESS!!!");
    }
    return 0;
}

