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
    char* message = "Text to pipe";
    char* buf = calloc(BUF_SIZE, sizeof(char));
    write(pipefd[1], message, strlen(message));
    read(pipefd[0], buf, BUF_SIZE);
    printf("I have read this text from pipe: %s\n", buf);
}


