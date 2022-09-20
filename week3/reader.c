#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define BUF_SIZE 1000


int main(){
    int fd = open("reader.txt", O_RDONLY);
    //printf("File descriptor: %d\n", fd);
    char* buf = calloc(BUF_SIZE, sizeof(char));
    read(fd, buf, BUF_SIZE);
    printf("%s", buf);
    return 0;
}
