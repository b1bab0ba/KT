#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(){
    printf("u pid: %d\n", getpid());
    return 0;

}
