#include <stdio.h>
#include <unistd.h>
#define COM_SIZE 100
int main(int argc, char* argv[]){
    
    pid_t fork_return = fork();
    
    if(fork_return > 0){
        printf("I'm Parent! Let me count from 1 to 100");
        for(int i = 1; i <= 1000; i++)
            printf("%d\n", i);
    }else if(!fork_return){
            printf("I'm Child! Let me execute your command");
            
            execvp(argv[1], argv + 1);
        }else{
            printf("Can't create child process\n");
            return -1;
            }
    return 0;
}
