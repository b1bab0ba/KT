#include <stdio.h>
#include <sys/types.h>
#include <unistd.h> 
int main(){
    printf("u ppid: %d\n", getppid());
    return 0; 
    }

